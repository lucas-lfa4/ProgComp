#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> h(N);
    vector<int> dp(N, 1000000000);

    for(int i  = 0; i < N; i++)
        cin >> h[i];
    
    dp[0] = 0;

    for(int i = 1; i < N; i++)
        for(int j = 1; j <= K; j++)
            if(i-j >= 0)
                dp[i] = min(dp[i], dp[i-j]+abs(h[i]-h[i-j]));

    cout << dp[N-1];

    return 0;
}