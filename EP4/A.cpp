#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, x = -1;
    int soma = 0;
    vector<int> a;

    cin >> t;

    for(int i = 0; i < t; i++, x = -1, soma = 0) {
        cin >> n;
        a.resize(n);

        for(int j = 0; j < n; j++) {
            cin >> a[j];
            soma += a[j];
        }

        sort(a.begin(), a.end());

        


        cout << x << "\n";
    }

    return 0;
}