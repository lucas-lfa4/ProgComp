#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, x, soma = 0;
    cin >> t;

    while(t != 0) {
        soma = 0;
        cin >> n;
        vector<int> a;
        for(int i = 0; i < 2*n; i++) {
            cin >> x;
            a.push_back(x);
        }
        sort(a.begin(), a.end());
        for(int i = 0; i < 2*n; i++) {
            if(i%2 == 1) {
                soma += a.back();
                a.pop_back();
            }
            else {
                a.pop_back();
            }
        }

        cout << soma << "\n";

        t--;
    }


    return 0;
}