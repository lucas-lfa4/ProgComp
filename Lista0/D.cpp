#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    string a[n];
    string b[n];

    for(int i=0; i<n; i++) {
        cin >> a[i];
        b[i] = a[i];

        for(int j=a[i].length()-1; j >= 0; j--) {
            if(a[i][j] == 'p')
                b[i][a[i].length()-1-j] = 'q';
            else if(a[i][j] == 'q')
                b[i][a[i].length()-1-j] = 'p';
            else if(a[i][j] == 'w')
                b[i][a[i].length()-1-j] = 'w';
        }

        cout << b[i] << "\n";
    }

    return 0;
}