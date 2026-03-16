#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q, numero;
    cin >> N >> Q;

    vector<int> A(N);

    for(int i = 0; i < N; i++)
        cin >> A[i];
    
    for(int i = 0; i < Q; i++) {
        cin >> numero;


        if(binary_search(A.begin(), A.end(), numero)) {
            auto it = lower_bound(A.begin(), A.end(), numero);
            if(i == Q-1)
                cout << it - A.begin();
            else 
                cout << it - A.begin() << "\n";
        }
        else {
            if(i == Q-1)
                cout << "-1";
            else 
                cout << "-1\n";
        }
    }

    return 0;
}