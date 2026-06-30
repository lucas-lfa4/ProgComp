#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t;

    while(t != 0) {
        string a;
        cin >> a;
        n = a.length();

        for(int i = 0; i < n/2; i++) {
            swap(a[i], a[n-1-i]);
        }

        for(int i = 0; i < n; i++) {
            if(a[i] == 'q')
                a[i] = 'p';
            else if(a[i] == 'p')
                a[i] = 'q';
        }

        cout << a << "\n";

        t--;
    }

    return 0;
}