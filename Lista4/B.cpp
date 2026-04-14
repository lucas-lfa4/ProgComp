#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t, n, x;
    cin >> t;
    vector<int> a;

    for(int i = 0; i < t; i++) {
        cin >> n >> x;
        a.resize(n);

        for(int j = 0; j < n; j++) {
            cin >> a[j];
        }
    }
    

    return 0;
}