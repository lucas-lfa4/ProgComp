#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, deslocamento = 0;
    long long int soma = 0;
    cin >> t;

    for(int i = 0; i < t; i++) {
        cin >> n;
        vector<int> field(n);
        vector<int> impares(n);
        soma = 0;
        deslocamento = 0;

        for(int k = 0; k < n; k++) {
            cin >> field[k];

            if(field[k]%2 == 0)
                soma += field[k];
            else {
                impares[deslocamento] = field[k];
                deslocamento++;
            }
        }

        if(impares[0] != 0) {
            sort(impares.begin(), impares.end());
            reverse(impares.begin(), impares.end());
            if(deslocamento%2 == 0) {
                for(int k = 0; k < deslocamento/2; k++)
                    soma += impares[k];
            }
            else {
                for(int k = 0; k < deslocamento/2 + 1; k++)
                    soma += impares[k];
            }
            cout << soma << "\n";
        }
        else
            cout << "0\n";

        
    }

    return 0;
}