#include <bits/stdc++.h>
#define EPS 0,00000001
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, x;
    vector<int> a;
    cin >> t;

    for(int i = 0; i < t; i++) {
        cin >> n;
        a.reserve(n);
        for(int j = 0; j < n; j++) {
            cin >> x;
            a.push_back(x);
        }
        

        a.clear();
        a.shrink_to_fit();
    }


    return 0;
}