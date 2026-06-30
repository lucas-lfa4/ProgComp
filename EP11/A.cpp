#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int v;
    long long int flow;
    int C;
    int rev; // Guarda a posição da matriz de adj do vertice anterior da aresta reversa 
};

class Graph {
    int v;
    int* level;
    vector<Edge>* adj;

    public:
        Graph(int v) {
            this->v = v;
            adj = new vector<Edge>[v];
            level = new int[v];
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
        long long int sendFlow(int u, long long int flow, int t, int start[]);
        long long int DinicMaxFlow(int s, int t);
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, a, b, c;
    cin >> n >> m;

    Graph grafo(n+1);

    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;

        grafo.addEdge(a-1, b-1, c);
    }

    cout << grafo.DinicMaxFlow(0, n-1);

    return 0;
}

bool Graph::BFS(int s, int t) {
    for(int i = 0; i < v; i++)
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
            if(level[e.v] < 0 && e.flow < e.C) {
                level[e.v] = level[u] + 1;

                q.push_back(e.v);
            }
        }
    }

    return level[t] < 0 ? false : true;
}

long long int Graph::sendFlow(int u, long long int flow, int t, int start[]) {
    if(u == t)
        return flow;

    for(; start[u] < (int) adj[u].size(); start[u]++) {
        Edge& e = adj[u][start[u]];

        if(level[e.v] == level[u] + 1 && e.flow < e.C) {
            long long int curr_flow = min(flow, e.C - e.flow);
            long long int temp_flow = sendFlow(e.v, curr_flow, t, start);

            if(temp_flow > 0) {
                e.flow += temp_flow;

                adj[e.v][e.rev].flow -= temp_flow;
                return temp_flow;
            }
        }
    }

    return 0;
}

long long int Graph::DinicMaxFlow(int s, int t) {
    if(s == t)
        return -1;

    long long int total = 0;

    while(BFS(s, t) == true) {
        int* start = new int[v+1]{ 0 };

        while(long long int flow = sendFlow(s, LONG_LONG_MAX, t, start)) {
            total += flow;
        }

        delete[] start;
    }

    return total;
}