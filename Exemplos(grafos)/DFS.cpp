#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
vector<vii> AL;
vector<bool> visited;

void dfs(int u);
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
    cout << "DFS:\n";
    dfs(0);

    return 0;
}

void dfs(int u) {
    cout << "Vertice " << u << " visitado\n";
    visited[u] = true;

    for(auto &e : AL[u]) {
        int v = e.first;
        if(visited[v] == false)
            dfs(v);
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