#include <bits/stdc++.h>
#define LSOne(S) ((S) & -(S))

using namespace std;

typedef vector<int> vi;

class FenwickTree {
    private:
        vi ft;

    public:
        FenwickTree(int m) {
            ft.assign(m+1, 0);
        }

        int rsq(int j) {
            int sum = 0;
            for(; j; j -= LSOne(j))
                sum += ft[j];

            return sum;
        }

        int rsq(int i, int j) {
            return rsq(j) - rsq(i-1);
        }

        // v é a diferença entre o novo número e o antigo número
        void update(int i, int v) {
            for(; i < (int)ft.size(); i+= LSOne(i))
                ft[i] += v;
        }
};

int main() {


    return 0;
}