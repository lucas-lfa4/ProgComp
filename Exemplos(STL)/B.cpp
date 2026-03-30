#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int c, l, m, d, soma, prox_valor, cnt = 0;
    cin >> c;

    bool vez_esquerda = true;
    int cruzamentos = 0;
    vector<int> dist_carros_esquerda;
    vector<int> dist_carros_direita;
    string s;

    for(int i = 0; i < c; i++, soma = 0, vez_esquerda = true, cruzamentos = 0, cnt = 0) {
        cin >> l >> m;

        for(int k = 0; k < m; k++) {
            cin >> d >> s;
            if(s == "left")
                dist_carros_esquerda.push_back(d);
            else
                dist_carros_direita.push_back(d);
        }

        sort(dist_carros_direita.begin(), dist_carros_direita.end());
        reverse(dist_carros_direita.begin(), dist_carros_direita.end());
        sort(dist_carros_esquerda.begin(), dist_carros_esquerda.end());
        reverse(dist_carros_esquerda.begin(), dist_carros_esquerda.end());

        /*cout << "carros esperando na margem esquerda\n";
        for(auto it = dist_carros_esquerda.begin(); it != dist_carros_esquerda.end(); it++) {
            cout << *it << " ";
        }
        cout << "\ncarros esperando na margem direita\n";
        for(auto it = dist_carros_direita.begin(); it != dist_carros_direita.end(); it++) {
            cout << *it << " ";
        }
        cout << "\n";*/

        while(!(dist_carros_direita.empty() && dist_carros_esquerda.empty())) {
            if(vez_esquerda) {
                for(auto it = dist_carros_esquerda.begin(); it != dist_carros_esquerda.end(); ) {
                    if(soma + (*it) < 100*l) {
                        soma += *it;

                        if(it+1 != dist_carros_esquerda.end()) {
                            prox_valor = *(it+1);
                            dist_carros_esquerda.erase(it);
                            it = find(dist_carros_esquerda.begin(), dist_carros_esquerda.end(), prox_valor);
                        }
                        else {
                            dist_carros_esquerda.erase(it);
                            it = dist_carros_esquerda.end();
                        }
                    }
                    else
                        it++;
                }
                
                vez_esquerda = false;
                cruzamentos++;
                soma = 0;
            }
            else {
                for(auto it = dist_carros_direita.begin(); it != dist_carros_direita.end(); ) {
                    if(soma + (*it) < 100*l) {
                        soma += *it;

                        if(it+1 != dist_carros_direita.end()) {
                            prox_valor = *(it+1);
                            dist_carros_direita.erase(it);
                            it = find(dist_carros_direita.begin(), dist_carros_direita.end(), prox_valor);
                        }
                        else {
                            dist_carros_direita.erase(it);
                            it = dist_carros_direita.end();
                        }
                    }
                    else
                        it++;
                }

                vez_esquerda = true;
                cruzamentos++;
                soma = 0;
            }
        }

        cout << cruzamentos << "\n";

        dist_carros_direita.clear();
        dist_carros_esquerda.clear();
        s.clear();
    }

    return 0;
}