#include<bits/stdc++.h>
#define MAX 10000000

using namespace std;

vector<int> ehBeautiful(MAX+1);
vector<bool> ehPrimo(MAX+1, true);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q, n, qnt = 0;
    cin >> q;

    for(long long p = 2; p * p <= MAX; p++)
        if(ehPrimo[p])
            for(long long i = p * p; i <= MAX; i += p)
                ehPrimo[i] = false;

    for(int i = 2; i <= MAX; i++) {
        if(ehPrimo[i]) {
            qnt++;
            if(i == 2)
                ehBeautiful[i] = true;
            else
                ehBeautiful[i] = ehBeautiful[qnt-1];
        }
    }

    for(int i = 0; i < q; i++) {
        cin >> n;

        if(ehBeautiful[n])
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}