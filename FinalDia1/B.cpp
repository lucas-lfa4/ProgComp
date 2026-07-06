#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, c, orb, custo = 0;
    cin >> t;

    while(t != 0) {
        cin >> n >> c;

        vector<int> orbita[101];

        for(int i = 0; i < n; i++) {
            cin >> orb;
            orbita[orb].push_back(i);
        }

        for(int i = 0; i <= 100; i++) {
            if(orbita[i].size() != 0 && orbita[i].size() >= c) {
                custo += c;
            }
            else if(orbita[i].size() != 0 & orbita[i].size() < c) {
                custo += orbita[i].size();
            }
        }

        cout << custo << "\n";

        t--;
        custo = 0;
    }


    


    return 0;
}