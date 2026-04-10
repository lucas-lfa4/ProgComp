#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); //desincronizar as bibliotecas do c e c++
    cin.tie(nullptr); //desincroniza os buffers de input e output

    int N, a;
    map<int,int> s; //(a, qnt)
    cin >> N;
    int removes = 0;

    for(int i = 0; i < N; i++) {
        cin >> a;
        if(s.find(a) == s.end()) {
            s.insert({a, 1});
        }
        else {
            s[a]++;
        }
    }

    for(auto it : s) {
        if(it.first == it.second) {
            //nada
        }
        else if(it.first > it.second) {
            removes += it.second;
        }
        else if(it.first < it.second) {
            removes += it.second - it.first;
        }
    }

    cout << removes;

    return 0;
}