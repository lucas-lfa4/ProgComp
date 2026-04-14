#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long int> p(n);
    long long int soma1, soma2;
    long long int dif_min = 20000000000;

    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }

    for(int i = 0; i < (1<<n); i++) {
        soma1 = 0;
        soma2 = 0;

        for(int j = 0; j < n; j++) {
            if(i & (1<<j)) {
                soma1 += p[j];
            }
            else {
                soma2 += p[j];
            }
        }

        if(dif_min > abs(soma1 - soma2)) {
            dif_min = abs(soma1 - soma2);
        }
    }

    cout << dif_min;

    return 0;
}