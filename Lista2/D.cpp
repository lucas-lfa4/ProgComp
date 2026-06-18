#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q, tempo = 0;

    cin >> n >> q;
    queue<pair<string, int>> fila;
    pair<string, int> aux;

    for(int i = 0; i < n; i++) {
        cin >> aux.first >> aux.second;
        fila.push(aux);
    }

    while(!fila.empty()) {
        aux = fila.front();
        fila.pop();

        if(aux.second > q) {
            aux.second -= q;
            tempo += q;
            fila.push(aux);
        }
        else {
            tempo += aux.second;
            cout << aux.first << " " << tempo << "\n";
        }
    }

    return 0;
}