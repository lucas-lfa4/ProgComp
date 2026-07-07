#include <bits/stdc++.h>
#define INF LONG_LONG_MAX

using namespace std;

typedef pair<long long int, int> llii;
typedef pair<int, int> ii;
typedef vector<long long int> vlli;
typedef vector<ii> vii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E;
    int u, v, w;
    cin >> V >> E;

    vector<vii> AL(V);

    for(int i = 0; i < E; i++) {
        cin >> u >> v >> w;

        AL[u-1].emplace_back(v-1, w);
    }

    vlli dist(V, INF);
    dist[0] = 0;
    set<llii> pq;

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

    for(int i = 0; i < V; i++)
        cout << dist[i] << " ";

    return 0;
}