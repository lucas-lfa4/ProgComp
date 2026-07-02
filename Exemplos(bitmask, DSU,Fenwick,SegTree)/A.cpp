#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned int n;
    bitset<32> num, a, b;
    bool vezA = true;

    cin >> n;

    while(n != 0) {
        num = bitset<32>(n);

        vezA = true;
        for(int i = 0; i < 32; i++) {
            if(num[i] == 1 && vezA) {
                a[i] = 1;
                vezA = false;
            }
            else if(num[i] == 1 && vezA == false) {
                b[i] = 1;
                vezA = true;
            }
        }

        cout << a.to_ulong() << " " << b.to_ulong() << "\n";

        cin >> n;
        a.reset();
        b.reset();
    }
    

    return 0;
}