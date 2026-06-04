#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n;
    
    vector<int> timings[2];
    timings[0].reserve(n);
    timings[1].reserve(n);

    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        timings[0][i] = a;
        timings[1][i] = b;
    }


    return 0;
}