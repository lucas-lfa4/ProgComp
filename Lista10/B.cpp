#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<long long int, long long int>> P(n);

    for(int i = 0; i < n; i++)
        cin >> P[i].first >> P[i].second;

    P.push_back(P[0]);

    long long int ans = 0;
    for(int i = 0; i < (int) P.size()-1; i++)
        ans += P[i].first*P[i+1].second - P[i].second*P[i+1].first;

    cout << abs(ans);

    return 0;
}