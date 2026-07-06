#include <bits/stdc++.h>
#define INF 100000000

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
vector<vii> AL;
vector<bool> visited;

void bfs(int u);
void printAL();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, u, v, w;

    cin >> n >> m;

    AL.assign(n, vii());
    visited.assign(n, false);

    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;

        AL[u].push_back({v, w});
        AL[v].push_back({u, w});
    }

    printAL();
    cout << "BFS:\n";
    bfs(0);

    return 0;
}

void bfs(int s) {
    int tam = AL.size();
    vector<int> dist(tam, INF);
    dist[s] = 0;

    queue<int> q;
    q.push(s);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(auto& e : AL[u]) {
            if(dist[e.first] != INF) continue;
            cout << "Vertice " << e.first << " distancia ate a origem: " << dist[u]+1 << "\n";
            dist[e.first] = dist[u]+1;
            q.push(e.first);
        }
    }
}

void printAL() {
    int tam = AL.size();
    for(int i = 0; i < tam; i++) {
        cout << "Vertice " << i << ": ";

        for(int j = 0; j < AL[i].size(); j++)
            cout << "{" <<AL[i][j].first << ", " << AL[i][j].second << "}; ";
        
            cout << "\n";
    }
}