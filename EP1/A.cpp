#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, a;
    cin >> n >> x;
    map<int, int> numeros;

    for(int i = 0; i < n; i++) {
        cin >> a;

        if(numeros.count(x-a)) {
            cout << numeros[x-a]+1 << " " << i+1;
            return 0;
        }

        numeros[a] = i;
    }

    cout << "IMPOSSIBLE";

    return 0;
}