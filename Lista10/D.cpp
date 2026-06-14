#include <bits/stdc++.h>
#define EPS 0.00000001
using namespace std;

struct point {
    double x, y;
    point() { x = y = 0; }
    point(double _x, double _y) : x(_x), y(_y) {}
    bool operator < (point other) const {
        if(fabs(x - other.x) > EPS)
            return x < other.x;
        else if(fabs(y - other.y) > EPS)
            return y < other.y;
    }
    bool operator == (point other) const {
        return (fabs(x - other.x) < EPS) && (fabs(y - other.y) < EPS);
    }
};

double distPontoAPonto(point p1, point p2);

class segReta {
    public:
        double m;
        double n;
        point Pa;
        point Pb;
        double l;

        segReta(point p1, point p2) {
            m = (p2.y - p1.y)/(p2.x - p1.x);
            n = p1.y - m*p1.x;
            Pa = p1;
            Pb = p2;
            l = distPontoAPonto(Pa, Pb);
        }
        bool pointIsInside(point p);
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    point p1, p2, p3, p4;

    for(int i = 0; i < t; i++) {
        cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;

        if(p2.x == p1.x || p4.x == p3.x) {
            if(p2.x == p1.x && p4.x == p3.x)
                cout << "NO\n";
            else {
                if(p2.x == p1.x) {
                    segReta r2(p3, p4);
                    point p(p1.x, r2.m*p1.x + r2.n);
                    
                    if(r2.pointIsInside(p))
                        cout << "YES\n";
                    else
                        cout << "NO\n";
                }
                else {
                    segReta r1(p1, p2);
                    point p(p3.x, r1.m*p3.x + r1.n);

                    if(r1.pointIsInside(p))
                        cout << "YES\n";
                    else
                        cout << "NO\n";
                }
            }
        }
        else {
            segReta r1(p1, p2);
            segReta r2(p3, p4);

            if(fabs(r1.m - r2.m) < EPS) {
                if(fabs(r1.n - r2.n) < EPS)
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
            else {
                point p;
                p.x = (r2.n-r1.n)/(r1.m-r2.m);
                p.y = r1.m*p.x+r1.n;

                if(r1.pointIsInside(p) && r2.pointIsInside(p))
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
        }
    }


    return 0;
}

double distPontoAPonto(point p1, point p2) {
    return sqrt(pow(p1.x-p2.x, 2) + pow(p1.y-p2.y, 2));
}

bool segReta::pointIsInside(point p) {
    if(distPontoAPonto(p, Pa) - l > EPS || distPontoAPonto(p, Pb) - l> EPS)
        return false;

    return true;
}