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
            Edge b{ u, 0, 0, (int)adj[u].size() };

            adj[u].push_back(a);
            adj[v].push_back(b);
        }

        bool BFS(int s, int t);
        int sendFlow(int u, int flow, int t, int start[]);
        int DinicMaxFlow(int s, int t);
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Graph g(6);
    g.addEdge(0, 1, 16);
    g.addEdge(0, 2, 13);
    g.addEdge(1, 2, 10);
    g.addEdge(1, 3, 12);
    g.addEdge(2, 1, 4);
    g.addEdge(2, 4, 14);
    g.addEdge(3, 2, 9);
    g.addEdge(3, 5, 20);
    g.addEdge(4, 3, 7);
    g.addEdge(4, 5, 4);

    // next exmp
    /*g.addEdge(0, 1, 3 );
      g.addEdge(0, 2, 7 ) ;
      g.addEdge(1, 3, 9);
      g.addEdge(1, 4, 9 );
      g.addEdge(2, 1, 9 );
      g.addEdge(2, 4, 9);
      g.addEdge(2, 5, 4);
      g.addEdge(3, 5, 3);
      g.addEdge(4, 5, 7 );
      g.addEdge(0, 4, 10);

     // next exp
     g.addEdge(0, 1, 10);
     g.addEdge(0, 2, 10);
     g.addEdge(1, 3, 4 );
     g.addEdge(1, 4, 8 );
     g.addEdge(1, 2, 2 );
     g.addEdge(2, 4, 9 );
     g.addEdge(3, 5, 10 );
     g.addEdge(4, 3, 6 );
     g.addEdge(4, 5, 10 ); */

    cout << "Maximum flow " << g.DinicMaxFlow(0, 5) << "\n";

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