#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, x, L, dist;
    bool achou = false;
    cin >> t;

    for(int i = 0; i < t; i++, achou = false) {
        multiset<int> a;
        unordered_multiset<int> dif;
        cin >> n;

        cin >> x;
        a.insert(x);
        for(int j = 0; j < n-1; j++) {
            cin >> x;
            a.insert(x);

            dif.insert(*prev(a.end()) - *prev(a.end(), 2));
        }

        for(auto it = a.begin(); it != prev(a.end()) && !achou; it++) {
            //percorrer a até achar um numero repetido
            if(*it == *next(it)) {
                L = *it;
                dist = distance(a.begin(), it);

                //percorrer dif de 0 até dist-2 ou até encontrar uma diferenca menor que 2*L
                auto it2 = dif.begin();
                for(int i = 0; i < dist-1 && !achou; i++, it2++) {
                    if(*it2 < 2*L) {
                        cout << L << L << *next(a.begin(), i) << *next(a.begin(), i+1) << "\n";
                        achou = true;
                    }
                }
                //percorrer dif de dist+2 até n-2 ou até encontrar uma diferenca menor que 2*L
                it2 = next(dif.begin(), dist+2);
                for(int i = dist+2; i <= n-2 && !achou; i++, it2++) {
                    if(*it2 < 2*L) {
                        cout << L << L << *next(a.begin(), i) << *next(a.begin(), i+1) << "\n";
                        achou = true;
                    }
                }
            }
        }
        if(!achou)
            cout << "-1\n";
    }


    return 0;
}