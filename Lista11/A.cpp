#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> teleporter(m);

    for(int i = 0; i < m; i++) {
        cin >> teleporter[i].first >> teleporter[i].second;
    }


    return 0;
}