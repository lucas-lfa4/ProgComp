#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, atual, cnt = 0;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    for(int i = 0; i < n; i++) {
        if(i == 0) {
            atual = a[i];
            cnt++;
        }
        else {
            if(a[i] != atual) {
                atual = a[i];
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}