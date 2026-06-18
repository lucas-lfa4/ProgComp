#include <bits/stdc++.h>
#define EPS 0.00000001
using namespace std;

struct point {
    double x, y;
    point() { x = y = 0; }
    point(double _x, double _y): x(_x), y(_y) {}
};

class reta {
    double m;
    double n;
    bool retaVertical;
    double x;

    public:

    void calcReta(point p1, point p2) {
        if(fabs(p1.x-p2.x) < EPS) {
            retaVertical = true;
            x = p1.x;
        }
        else {
            retaVertical = false;
            m = (p2.y-p1.y)/(p2.x-p1.x);
            n = p1.y-m*p1.x;
        }
    }

    void pointLocation(point p3) {
        if(retaVertical) {
            if(p3.x - x > EPS)
                cout << "RIGHT\n";
            else if(p3.x - x < -EPS)
                cout << "LEFT\n";
            else
                cout << "TOUCH\n";
        }
        else {
            double y = m*p3.x+n;
            if(p3.y-y > EPS)
                cout << "LEFT\n";
            else if(p3.y-y < -EPS)
                cout << "RIGHT\n";
            else
                cout << "TOUCH\n";
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;
    point p1, p2, p3;
    reta r;

    for(int i = 0; i < t; i++) {
        cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
        r.calcReta(p1, p2);
        r.pointLocation(p3);
    }


    return 0;
}