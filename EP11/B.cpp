#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> knights;
vector<vector<int>> adj;
vector<int> match;
vector<bool> vis;

bool dfs(int u) {
    for (int v : adj[u]) {
        if (vis[v]) continue;
        vis[v] = true;

        if (match[v] < 0 || dfs(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    knights.resize(k);
    for (int i = 0; i < k; ++i)
        cin >> knights[i].first >> knights[i].second;

    adj.assign(k, vector<int>());
    vector<int> even_nodes;

    for (int i = 0; i < k; ++i) {
        if ((knights[i].first + knights[i].second) % 2 == 0) {
            even_nodes.push_back(i);
            
            for (int j = 0; j < k; ++j) {
                if ((knights[j].first + knights[j].second) % 2 != 0) {
                    int dr = abs(knights[i].first - knights[j].first);
                    int dc = abs(knights[i].second - knights[j].second);
                    
                    if ((dr == 1 && dc == 2) || (dr == 2 && dc == 1)) {
                        adj[i].push_back(j);
                    }
                }
            }
        }
    }

    match.assign(k, -1);
    int mcbm = 0;

    for (int u : even_nodes) {
        vis.assign(k, false);
        if (dfs(u)) {
            mcbm++;
        }
    }

    cout << mcbm << "\n";

    return 0;
}