#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int c, l, m, d, soma_pote, cnt = 0;
    cin >> c;
    bool acabou = false;
    bool vez_esquerda = true;
    int cruzamentos = 0;
    vector<int> dist_carros_esquerda;
    vector<int> dist_carros_direita;
    vector<int> pote;
    string s;

    for(int i = 0; i < c; i++, acabou = false, soma_pote = 0, vez_esquerda = true, cruzamentos = 0, cnt = 0) {
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
        auto it_left = dist_carros_esquerda.begin();
        auto it_right = dist_carros_direita.begin();

        while(!acabou) {
            if(vez_esquerda) {
                while(it_left != dist_carros_esquerda.end() && soma_pote + *it_left < 100*l) {
                    pote.push_back(*it_left);
                    soma_pote += *it_left;
                    it_left++;
                }



                vez_esquerda = false;
            }
            else {
                while(it_right != dist_carros_direita.end() && soma_pote + *it_right < 100*l) {
                    pote.push_back(*it_right);
                    soma_pote += *it_right;
                    it_right++;
                }

                vez_esquerda = true;
            }

            
        }

        dist_carros_direita.clear();
        dist_carros_esquerda.clear();
        pote.clear();
        s.clear();
    }

    return 0;
}