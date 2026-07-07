#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> AM;

vector<bool> bfsReachable(int start) {
    vector<bool> reach(N, false);
    queue<int> q;
    reach[start] = true;
    q.push(start);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v = 0; v < N; v++) {
            if (AM[u][v] == 1 && !reach[v]) {
                reach[v] = true;
                q.push(v);
            }
        }
    }
    return reach;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> N;
        AM.assign(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> AM[i][j];

        vector<bool> reach = bfsReachable(0);
        vector<vector<char>> res(N, vector<char>(N, 'N'));

        for (int i = 0; i < N; i++) {
            // Remove i's outgoing edges (equivalent to deleting node i
            // for reachability purposes), then BFS once for this i.
            vector<int> saved = AM[i];
            fill(AM[i].begin(), AM[i].end(), 0);
            vector<bool> reach2 = bfsReachable(0);
            AM[i] = saved; // restore before moving to next i

            for (int j = 0; j < N; j++) {
                if (i == j) {
                    res[i][j] = reach[i] ? 'Y' : 'N';
                } else if (!reach[j]) {
                    res[i][j] = 'N';
                } else {
                    res[i][j] = reach2[j] ? 'N' : 'Y';
                }
            }
        }

        cout << "Case " << tc << ":\n";
        string sep(2 * N + 1, '-');
        sep[0] = '+';
        sep.back() = '+';
        for (int i = 0; i < N; i++) {
            cout << sep << "\n";
            cout << "|";
            for (int j = 0; j < N; j++) cout << res[i][j] << "|";
            cout << "\n";
        }
        cout << sep << "\n";
    }
    return 0;
}