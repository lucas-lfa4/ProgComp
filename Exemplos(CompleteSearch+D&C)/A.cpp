#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    int a, b, c;
    bool falhou = false;
    int cnt = 0;
    cin >> n >> m;
    vector<int> permutacoes(n);
    for(int i = 0; i < n; i++)
        permutacoes[i] = i;
    vector<tuple<int, int, int>> restricoes(m);

    while(!(n == 0 && m == 0)) {
        for(int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            get<0>(restricoes[i]) = a;
            get<1>(restricoes[i]) = b;
            get<2>(restricoes[i]) = c;
        }

        do {
            for(int i = 0; i < m && !falhou; i++) {
                int dist = 0;
                bool primeiro = false, segundo = false;
                bool acabou = false;

                if(get<2>(restricoes[i]) > 0) {
                    for(int j = 0; j < n &&  !falhou && !acabou; j++) {
                        if((permutacoes[j] == get<0>(restricoes[i]) || permutacoes[j] == get<1>(restricoes[i])) && primeiro == false)
                            primeiro = true;
                        else if((permutacoes[j] == get<0>(restricoes[i]) || permutacoes[j] == get<1>(restricoes[i])) && primeiro == true) {
                            segundo = true;
                            acabou = true;
                        }
                        else if(!(permutacoes[j] == get<0>(restricoes[i]) || permutacoes[j] == get<1>(restricoes[i])) && primeiro == true) {
                            dist++;
                            if(dist > get<2>(restricoes[i]))
                                falhou = true;
                        }
                    }
                }
                else {
                    for(int j = 0; j < n; j++) {
                        if((permutacoes[j] == get<0>(restricoes[i]) || permutacoes[j] == get<1>(restricoes[i])) && primeiro == false)
                            primeiro = true;
                        else if((permutacoes[j] == get<0>(restricoes[i]) || permutacoes[j] == get<1>(restricoes[i])) && primeiro == true) {
                            segundo = true;
                            if(dist >= -1*get<2>(restricoes[i]))
                                acabou = true;
                            else
                                falhou = true;
                        }
                        else if(!(permutacoes[j] == get<0>(restricoes[i]) || permutacoes[j] == get<1>(restricoes[i])) && primeiro == true)
                            dist++;
                    }
                }
            }
            if(!falhou)
                cnt++;
            else if(falhou)
                falhou = false;
        } while(next_permutation(permutacoes.begin(), permutacoes.end()));

        cout << cnt << "\n";

        cin >> n >> m;
        restricoes.resize(m, {0,0,0});
        permutacoes.resize(n);
        for(int i = 0; i < n; i++)
            permutacoes[i] = i;
        cnt = 0;
    }

    return 0;
}