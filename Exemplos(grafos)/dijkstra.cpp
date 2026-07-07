#include <bits/stdc++.h>
#define INF 200000000

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E;
    cin >> V >> E;

    vector<vii> AL(V);

    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        AL[u].emplace_back(v, w);
        AL[v].emplace_back(u, w);
    }

    vi dist(V, INF);
    dist[0] = 0;
    set<ii> pq;

    for(int u = 0; u < V; u++)
        pq.emplace(dist[u], u);

    while(!pq.empty()) {
        auto [d, u] = *pq.begin();
        pq.erase(pq.begin());

        for(auto &[v, w] : AL[u]) {
            if(dist[u]+w >= dist[v]) continue;
            pq.erase(pq.find({dist[v], v}));
            dist[v] = dist[u]+w;
            pq.emplace(dist[v], v);
        }
    }

    return 0;
}