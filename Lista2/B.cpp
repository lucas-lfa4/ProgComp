#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    long long int soma = 0;
    cin >> t;

    for(int i = 0; i < t; i++, soma = 0) {
        cin >> n;
        vector<int> s(n);
        priority_queue<int> pq;
        for(int j = 0; j < n; j++) {
            cin >> s[j];
            pq.emplace(s[j]);
            if(s[j] == 0) {
                soma += pq.top();
                pq.pop(); 
            }
        }

        cout << soma << "\n";
    }

    return 0;
}