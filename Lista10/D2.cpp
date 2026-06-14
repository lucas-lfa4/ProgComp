#include <bits/stdc++.h>
using namespace std;

struct point {
    long long int x, y;
    point() { x = y = 0; }
    point(long long int _x, long long int _y) : x(_x), y(_y) {}
};

int orientacao(point p1, point p2, point p3);
bool seInterceptam(point p1, point p2, point p3, point p4);
bool pointIsInside(point p1, point p, point p2);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    point p1, p2, p3, p4;

    for(int i = 0; i < t; i++) {
        cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;

        if(seInterceptam(p1, p2, p3, p4))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}

int orientacao(point p1, point p, point p2) {
    long long int z = (p.x-p1.x)*(p2.y-p1.y)-(p2.x-p1.x)*(p.y-p1.y);
    if(z == 0)
        return 0;
    return (z > 0)? 1 : -1;
}

bool seInterceptam(point p1, point p2, point p3, point p4) {
    int o1 = orientacao(p1, p2, p3);
    int o2 = orientacao(p1, p2, p4);
    int o3 = orientacao(p3, p4, p1);
    int o4 = orientacao(p3, p4, p2);

    if(o1*o2 < 0 && o3*o4 < 0)
        return true;

    if(o1 == 0 && pointIsInside(p1, p3, p2)) return true;
    if(o2 == 0 && pointIsInside(p1, p4, p2)) return true;
    if(o3 == 0 && pointIsInside(p3, p1, p4)) return true;
    if(o4 == 0 && pointIsInside(p3, p2, p4)) return true;

    return false;
}

bool pointIsInside(point p1, point p, point p2) {
    if(p.x <= max(p1.x, p2.x) && p.x >= min(p1.x, p2.x) &&
       p.y <= max(p1.y, p2.y) && p.y >= min(p1.y, p2.y))
       return true;
    return false;
}