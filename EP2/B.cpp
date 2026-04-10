#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); //desincronizar as bibliotecas do c e c++
    cin.tie(nullptr); //desincroniza os buffers de input e output
    int n, m, a;
    cin >> n >> m;
    queue<pair<int, int>> fila;
    int ultimo;

    for(int i = 0; i < n; i++) {
        cin >> a;
        fila.push({i+1, a});
    }

    while(fila.size() != 0) {
        if(m >= fila.front().second) {
            ultimo = fila.front().first;
            fila.pop();
        }
        else {
            ultimo = fila.front().first;
            fila.push({fila.front().first, fila.front().second - m});
            fila.pop();
        }
    }

    cout << ultimo;

    return 0;
}