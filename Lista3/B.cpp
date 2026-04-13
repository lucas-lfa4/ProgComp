#include<bits/stdc++.h>
#define LSOne(S) ((S) & -(S))

using namespace std;

class FenwickTree {
    private:
        vector<long long int> ft;
        vector<long long int> x;
    public:
        FenwickTree(long long int m) {
            ft.assign(m+1, 0);
            x.assign(m+1, 0);
        }
        long long int rsq(int j) {
            long long int sum = 0;
            for(; j; j -=LSOne(j))
                sum += ft[j];
            return sum;
        }
        long long int acumulado(long long int i, long long int j) {
            return (rsq(j) - rsq(i-1));
        }
        void update(long long int k, long long int u) {
            long long int var = u - x[k];
            x[k] = u;

            for(; k < (long long int) ft.size(); k += LSOne(k))
                ft[k] += var;
        }
        void print() {
            for(auto it = ft.begin(); it != ft.end(); it++)
                cout << *it << " ";
            cout << "\n";
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long int n, q, op, a;
    long long x, b;

    cin >> n >> q;

    FenwickTree ft(n);

    for(int i = 1; i <= n; i++) {
        cin >> x;
        ft.update(i, x);
    }

    for(int i = 0; i < q; i++) {
        cin >> op >> a >> b;

        switch(op) {
        case 1:
            ft.update(a, b);
            break;
        case 2:
            cout << ft.acumulado(a, b) << "\n";
            break;
        default:
            break;
        }
    }

    return 0;
}