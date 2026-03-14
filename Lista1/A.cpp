#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> A(n);

    for(int i=0; i < n; i++)
        cin >> A[i];

    sort(A.begin(), A.end());

    int cnt, atual;

    for(int i=0; i < n; i++) {
        if(i==0) {
            atual = A[0];
            cnt = 1;
        }
        else {
            if(A[i] != atual) {
                cnt++;
                atual = A[i];
            }
        }
    }

    cout << cnt << endl;

    return 0;
}