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

    int AM[V][V];
    int p[V][V];
    int D[V][V];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            AM[i][j] = INF;
            D[i][j]= INF;
            p[i][j] = i;
        }
        AM[i][i] = 0;
        D[i][i]= 0;
    }

    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        AM[u][v] = w;   // directed graph
        D[u][v] = w;
    }

    for(int k = 0; k < V; k++)
        for(int i = 0; i < V; i++)
            for(int j = 0; j < V; j++)
                if(D[i][k] != INF && D[k][j] != INF && D[i][k]+D[k][j] < D[i][j]) {
                    D[i][j] = D[i][k]+D[k][j];
                    p[i][j] = p[k][j];
                }

    return 0;
}