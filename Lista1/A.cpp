#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K, Q, aux;

    cin >> N >> K >> Q;

    vector<int> jogadores(N, K);
    vector<int> A(N, 0);

    for(int i = 0; i < Q; i++) {
        cin >> aux;
        A[aux-1]++;
    }

    for(int i = 0; i < N; i++) {
        //cout << "Jogador " << i+1 << ", " << A[i] << " vitorias\n";
        //cout << "Jogador " << i+1 << ", " << A[i] << " vitorias\n";
        jogadores[i] += A[i] - Q;
        if(jogadores[i] <=0)
            cout << "No\n";
        else
            cout << "Yes\n";
    }

    return 0;
}