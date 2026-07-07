#include <bits/stdc++.h>

using namespace std;

struct point {
    long long int x, y;
    point() { x = y = 0; }
    point(long long int _x, long long int _y): x(_x), y(_y) {}
};

int orientacao(point p1, point p, point p2);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, z;

    cin >> t;
    point p1, p2, p3;
    for(int i = 0; i < t; i++) {
        cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
        z = orientacao(p1, p2, p3);
        if(z > 0)
            cout << "LEFT\n";
        else if(z < 0)
            cout << "RIGHT\n";
        else
            cout << "TOUCH\n";
    }


    return 0;
}

int orientacao(point p1, point p, point p2) {
    long long int z = (p.x-p1.x)*(p2.y-p1.y)-(p2.x-p1.x)*(p.y-p1.y);
    if(z == 0)
        return 0;
    return (z > 0)? 1 : -1;
}