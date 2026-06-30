#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int V; // Vertice v de uma aresta direcionada u-v
    int flow; // Fluxo de dados em uma aresta
    int C; // Capacidade da aresta
    int rev; // indice da aresta reversa
};

class Graph {
    int V; // Numero de vertices
    int* level; // Armazena o nível do nó
    vector<Edge>* adj;

    public:
        Graph(int V) {
            this->V = V;
            adj = new vector<Edge>[V];
            level = new int[V];
        }

        ~Graph() {
            delete[] adj;
            delete[] level;
        }

        void addEdge(int u, int v, int C) {
            Edge a{ v, 0, C, (int)adj[v].size() };
            Edge b{ u, 0, C, (int)adj[u].size() };

            adj[u].push_back(a);
            adj[v].push_back(b);
        }

        bool BFS(int s, int t);
        int sendFlow(int u, int flow, int t, int start[]);
        int DinicMaxFlow(int s, int t);

        void dfsMinCut(int s, vector<bool>& visited);
        void printMinCutEdges(int s);
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, a, b;
    cin >> n >> m;

    Graph grafo(n);

    for(int i = 0; i < m; i++) {
        cin >> a >> b;

        grafo.addEdge(a-1, b-1, 1);
    }

    cout << grafo.DinicMaxFlow(0, n-1) << "\n";
    grafo.printMinCutEdges(0);


    return 0;
}

bool Graph::BFS(int s, int t) {
    for(int i = 0; i < V; i++)
        level[i] = -1;
    
    level[s] = 0;

    list<int> q;
    q.push_back(s);

    vector<Edge>::iterator i;
    while(!q.empty()) {
        int u = q.front();
        q.pop_front();
        for(i = adj[u].begin(); i != adj[u].end(); i++) {
            Edge& e = *i;
            if(level[e.V] < 0 && e.flow < e.C) {
                level[e.V] = level[u] + 1;

                q.push_back(e.V);
            }
        }
    }

    // Se não consegue alcancar t retorna falso
    return level[t] < 0 ? false : true;
}

// start[i] guarda a quantidade de arestas exploradas por i.
// u : vertice atual
// t : vertice final
int Graph::sendFlow(int u, int flow, int t, int start[]) {
    if(u == t)
        return flow;

    // percorre todas as arestas adjacentes uma por uma
    for(; start[u] < (int) adj[u].size(); start[u]++) {
        Edge& e = adj[u][start[u]];

        if(level[e.V] == level[u] + 1 && e.flow < e.C) {
            int curr_flow = min(flow, e.C - e.flow);
            int temp_flow = sendFlow(e.V, curr_flow, t, start);

            if(temp_flow > 0) {
                e.flow += temp_flow;

                adj[e.V][e.rev].flow -= temp_flow;
                return temp_flow;
            }
        }
    }

    return 0;
}

int Graph::DinicMaxFlow(int s, int t) {
    if(s == t)
        return -1;

    int total = 0;

    while(BFS(s, t) == true) {
        int* start = new int[V+1]{ 0 };

        while(int flow = sendFlow(s, INT_MAX, t, start)) {
            total += flow;
        }

        delete[] start;
    }

    return total;
}

// DFS auxiliar para encontrar vértices alcançáveis no grafo residual
void Graph::dfsMinCut(int s, vector<bool>& visited) {
    visited[s] = true;
    for (int i = 0; i < adj[s].size(); i++) {
        Edge e = adj[s][i];
        // Só viaja se a aresta tiver capacidade residual e o vizinho não foi visitado
        if (e.C - e.flow > 0 && !visited[e.V]) {
            dfsMinCut(e.V, visited);
        }
    }
}

// Método principal para imprimir as arestas do corte
void Graph::printMinCutEdges(int s) {
    // Vetor para marcar quem é alcançável a partir de s
    vector<bool> visited(V, false);
    
    // Roda a DFS a partir da origem
    dfsMinCut(s, visited);

    // Verifica todas as arestas de todos os vértices
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            Edge e = adj[i][j];
            
            // Se o vértice de origem foi visitado, 
            // o vértice de destino NÃO foi visitado, 
            // e é uma aresta original (C > 0)
            if (visited[i] && !visited[e.V] && e.C > 0) {
                cout << i+1 << " " << e.V+1 << "\n";
            }
        }
    }
}