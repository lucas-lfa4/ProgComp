#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); //desincronizar as bibliotecas do c e c++
    cin.tie(nullptr); //desincroniza os buffers de input e output

    int n;
    cin >> n;
    vector<string> nomes;
    string name;

    for(int i = 0; i < n; i++) {
        cin >> name;
        if(binary_search(nomes.begin(), nomes.end(), name))
            cout << "YES\n";
        else {
            cout << "NO\n";
            nomes.push_back(name);
            sort(nomes.begin(), nomes.end());
        }
    }

    return 0;
}