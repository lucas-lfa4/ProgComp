#include <bits/stdc++.h>

using namespace std;

struct point {
    long long int x, y;
};

struct circulo {
    point centro;
    long long int raio;
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    circulo* circulos;
    point ps, pt;
    long long int d, dist2;
    bool achou = false;

    cin >> t;

    for(int i = 0; i < t; i++, achou = false) {
        cin >> n;
        circulos = (circulo* ) calloc(n, sizeof(circulo));
        for(int j = 0; j < n; j++) {
            cin >> circulos[j].centro.x >> circulos[j].centro.y;
            circulos[j].raio = 0;
        }

        cin >> ps.x >> ps.y >> pt.x >> pt.y;

        d = (ps.x-pt.x)*(ps.x-pt.x) + (ps.y-pt.y)*(ps.y-pt.y);

        for(int j = 0; j < n && !achou; j++) {
            dist2 = (circulos[j].centro.x - pt.x)*(circulos[j].centro.x - pt.x) + (circulos[j].centro.y - pt.y)*(circulos[j].centro.y - pt.y);
            if(dist2 <= d) {
                cout << "NO\n";
                achou = true;
            }
        }

        if(!achou)
            cout << "YES\n";

        free(circulos);
    }

    

    return 0;
}