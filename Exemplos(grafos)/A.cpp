#include <bits/stdc++.h>
#define INF 200000000

using namespace std;

vector<bool> bfsReachable(int N, int** AM);
void printReach(vector<int> reach) {
    int i = 0;
    for(auto it = reach.begin(); it != reach.end(); it++) {
        if(*it) {
            cout << "S ";
        }
        else
            cout << "N ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, N, X;

    cin >> T;
    int** AM;
    char** Resposta;


    for(int Case = 1; Case <= T; Case++) {
        cin >> N;
        AM = new int*[N];
        Resposta = new char*[N];

        for(int i = 0; i < N; i++) {
            AM[i] = new int[N];
            Resposta[i] = new char[N];
        }

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cin >> AM[i][j];
                Resposta[i][j] = 'N';
            }
        }
        
        vector<bool> reach = bfsReachable(N, AM);

        for(int i = 0; i < N; i++) {
            //Tirar o vertice i e ver se ainda existe um caminho do 0 até o j.

            //Para tirar o i de jogo, primeiro fazemos uma cópia das ligações dele
            int copia[N];
            for(int k = 0; k < N; k++) {
                copia[k] = AM[i][k];
                AM[i][k] = 0;
            }

            //Rodar o BFS de novo para ver se ainda existe um caminho do 0 até j
            vector<bool> reach2 = bfsReachable(N, AM);

            for(int j = 0; j < N; j++)
                AM[i][j] = copia[j];

            for(int j = 0; j < N; j++) {
                if(i == j)
                    Resposta[i][j] = (reach[i] ? 'Y' : 'N');
                else if(!reach[j])
                    Resposta[i][j] = 'N';
                else
                    Resposta[i][j] = (reach2[i] ? 'N' : 'Y');
            }
        }

        cout << "Case " << Case << ":\n";
        for(int i = 0; i < N; i++) {
            for(int j = 1; j <= 2*N+1; j++) {
                if(j == 1 || j == 2*N+1)
                    cout << '+';
                else
                    cout << '-';
            }
            cout << "\n";

            for(int j = 0; j < N; j++) {
                cout << "|" << Resposta[i][j];
            }
            cout << "|\n";
        }

        for(int i = 1; i <= 2*N+1; i++) {
            if(i == 1 || i == 2*N+1)
                cout << '+';
            else
                cout << '-';
        }
        cout << "\n";

        for(int i = 0; i < N; i++) {
            delete[] AM[i];
            delete[] Resposta[i];
        }
        delete[] AM;
        delete[] Resposta;
    }

    return 0;
}

vector<bool> bfsReachable(int N, int** AM) {
    vector<bool> reach(N, false);
    queue<int> q;

    reach[0] = true;
    q.push(0);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int v = 0; v < N; v++) {
            if(AM[u][v] == 1 && !reach[v]) {
                reach[v] = true;
                q.push(v);
            }
        }
    }

    return reach;
}