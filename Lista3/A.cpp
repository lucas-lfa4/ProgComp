#include <bits/stdc++.h>

using namespace std;

class grafo {
    private:
        int n;
        vector<int>* adj;

    public:
        grafo(int tam) {
            n = tam;
            adj = new vector<int>[tam+1];
        }
        void addEdge(int u, int v);
        pair<int, int> bfs(int u); // essa função retorna o elemento mais distante de u e sua respectiva distancia
        void print_tree_diameter();
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int a, b;
    cin >> n;
    if(n == 1) {
        cout << "0\n";
        return 0;
    }
    
    grafo G(n);

    for(int i = 0; i < n-1; i++) {
        cin >> a >> b;

        G.addEdge(a, b);
    }

    G.print_tree_diameter();


    return 0;
}

void grafo::addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

pair<int, int> grafo::bfs(int u) {
    int dist[n+1];
    for(int i = 1; i <= n; i++)
        dist[i] = -1;
    
    queue<int> q;
    q.push(u);

    dist[u] = 0;

    while(!q.empty()) {
        int t = q.front();
        q.pop();

        for(auto it = adj[t].begin(); it != adj[t].end(); it++) {
            int v = *it;

            if(dist[v] == -1) {
                q.push(v);

                dist[v] = dist[t] + 1;
            }
        }
    }

    int max_dist = 0;
    int elem = u;

    for(int i = 1; i <=n; i++) {
        if(max_dist < dist[i]) {
            max_dist = dist[i];
            elem = i;
        }
    }

    return {elem, max_dist};
}

void grafo::print_tree_diameter() {
    pair<int, int> t1 = bfs(1);

    pair<int, int> t2 = bfs(t1.first);

    cout << t2.second;
}