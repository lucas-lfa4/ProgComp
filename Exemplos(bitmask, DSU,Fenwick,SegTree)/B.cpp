#include <bits/stdc++.h>
#define LSOne(S) ((S) & -(S))

using namespace std;

typedef vector<long long int> vlli;

class FenwickTree {
    private:
        vlli ft;

    public:
        FenwickTree(int m) {
            ft.assign(m+1, 0);
        }

        long long int rsq(int j) {
            long long int sum = 0;
            for(; j; j -= LSOne(j))
                sum += ft[j];

            return sum;
        }

        long long int rsq(int i, int j) {
            return rsq(j) - rsq(i-1);
        }

        // v é a diferença entre o novo número e o antigo número
        void update(int i, int v) {
            for(; i < (int)ft.size(); i+= LSOne(i))
                ft[i] += v;
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q, k, incremento;
    char c;
    cin >> N >> Q;
    FenwickTree ft(N);

    for(int i = 0; i < Q; i++) {
        cin >> c;

        if(c == '+') {
            cin >> k >> incremento;
            ft.update(k+1, incremento);
        }
        else if(c == '?') {
            cin >> k;
            if(k == 0)
                cout << "0\n";
            else
                cout << ft.rsq(k) << "\n";
        }
    }

    return 0;
}