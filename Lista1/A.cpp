#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> A(n);
    vector<int> aux(n);
    int cnt = 0;

    for(int i=0; i < n; i++) {
        cin >> A[i];
    }



    for(int i=0; i < n; i++) {
        cout << A[i];
    }
    
    cout << endl << A.size();
    

    return 0;
}