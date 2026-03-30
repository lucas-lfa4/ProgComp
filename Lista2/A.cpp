#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    int Q, T, F;
    char C;

    cin >> S;
    cin >> Q;

    for(int i = 0; i < Q; i++) {
        cin >> T;

        if(T == 1)
            reverse(S.begin(), S.end());
        else if(T == 2) {
            cin >> F;
            cin >> C;

            if(F == 1)
                S = C + S;
            else if(F == 2)
                S = S + C;
        }
    }

    cout << S;

    return 0;
}