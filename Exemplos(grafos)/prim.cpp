#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> AL;                                  // the graph stored in AL
vi taken;                                        // to avoid cycle
priority_queue<ii> pq;                           // to select shorter edges

void process(int u) {
    taken[u] = 1;
    for(auto &[v, w] : AL[u])
        if(!taken[v])
            pq.push({-w, -v});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E;
    cin >> V >> E;
    AL.assign(V, vii());

    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        AL[u].emplace_back(v, w);
        AL[v].emplace_back(u, w);
    }

    taken.assign(V, 0);
    process(0);
    int mst_cost, num_taken = 0;

    while(!pq.empty() && num_taken != V-1) {
        auto [w, u] = pq.top();
        pq.pop();
        w = -w;
        u = -u;

        if(taken[u]) continue;
        mst_cost += w;
        process(u);
        num_taken++;
    }

    return 0;
}