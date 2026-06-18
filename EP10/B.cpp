#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, m, n;

    cin >> t;

    for(int i = 0; i < t; i++) {
        cin >> n >> m;
        if(n%m == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}