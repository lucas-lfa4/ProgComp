#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, k, curr = 0, cnt = 0;
    cin >> t;

    while(t != 0) {
        cin >> n >> k;

        string s;

        cin >> s;

        while(curr <= s.length()) {
            if(s[curr] == 'B') {
                cnt ++;
                curr += k;
            }
            else
                curr++;
        }

        cout << cnt << "\n";

        cnt = 0;
        curr = 0;
        t--;
    }


    return 0;
}