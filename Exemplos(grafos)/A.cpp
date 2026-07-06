#include <bits/stdc++.h>
#define INF 200000000

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, N, X;

    cin >> T;
    int** AM;
    char** Resposta;
    vector<int> dist;

    for(int Case = 1; Case <= T; Case++) {
        cin >> N;
        AM = new int*[N];
        Resposta = new char*[N];
        dist.resize(N, INF);

        for(int i = 0; i < N; i++) {
            AM[i] = new int[N];
            Resposta[i] = new char[N];
        }

        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                cin >> AM[i][j];
        
        queue<int> q;
        q.push(0);
        dist[0] = 0;

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(int i = 0; i < N; i++) {
                if(dist[i] != INF) continue;
                dist[i] = dist[u]+1;
                q.push(i);
            }
        }

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(i == j)
                    Resposta[i][j] = 'Y';
                else if(i == 0)
                    Resposta[i][j] = 'Y';
                else if(dist[i] != INF) {
                    
                }
            }
        }

        for(int i = 0; i < N; i++) {
            delete[] AM[i];
            delete[] Resposta[i];
        }
        delete[] AM;
        delete[] Resposta;
    }


    return 0;
}