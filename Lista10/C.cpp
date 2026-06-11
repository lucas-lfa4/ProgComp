#include <bits/stdc++.h>
#define EPS 0.00000001
using namespace std;

struct point {
    double x, y;
    point() { x = y = 0; }
    point(double _x, double _y) : x(_x), y(_y) {}
    bool operator < (point other) const {
        if(fabs(x-other.x) > EPS)
            return x < other.x;
        else if(fabs(y-other.y) > EPS)
            return y < other.y;
    }
    bool operator == (point other) const {
        return (fabs(x-other.x) < EPS) && (fabs(y-other.y) < EPS);
    }
};

double distanciaPontoAPonto(const point &p1, const point &p2);
bool ehColinear(const point &p1, const point &p2, const point &p3);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    point p1, p2, p3, p;
    double a, b, c, tmp, l = 1.0;
    const double PI = acos(-1.0);
    double teta;

    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
    if(ehColinear(p1, p2, p3)) {
        cout << "NEITHER";
        return 0;
    }
    a = distanciaPontoAPonto(p2, p3);
    b = distanciaPontoAPonto(p1, p3);
    c = distanciaPontoAPonto(p1, p2);

    if(c-b > EPS && c-a > EPS) {
        tmp = a;
        a = c;
        c = tmp;
    }
    else if(b-a > EPS && b-c > EPS) {
        tmp = a;
        a = b;
        b = tmp;
    }
    
    teta = acos((b*b+c*c-a*a)/(2*b*c));

    if(fabs((PI/2) - teta) < EPS) {
        cout << "RIGHT";
        return 0;
    }
    else {
        for(int i = 1; i <=3; i++) {
            if (i == 1) {
                l = 1.0;
                for(int j = 0; j < 2; j++, l = -1*l) {
                    p.x = p1.x + l;
                    p.y = p1.y;

                    a = distanciaPontoAPonto(p2, p3);
                    b = distanciaPontoAPonto(p, p3);
                    c = distanciaPontoAPonto(p, p2);

                    if(c-b > EPS && c-a > EPS) {
                        tmp = a;
                        a = c;
                        c = tmp;
                    }
                    else if(b-a > EPS && b-c > EPS) {
                        tmp = a;
                        a = b;
                        b = tmp;
                    }
                    
                    teta = acos((b*b+c*c-a*a)/(2*b*c));

                    if(fabs(PI/2-teta) < EPS) {
                        cout << "ALMOST";
                        return 0;
                    }
                }
                for(int j = 0; j < 2; j++, l = -1*l) {
                    p.x = p1.x;
                    p.y = p1.y + l;

                    a = distanciaPontoAPonto(p2, p3);
                    b = distanciaPontoAPonto(p, p3);
                    c = distanciaPontoAPonto(p, p2);

                    if(c-b > EPS && c-a > EPS) {
                        tmp = a;
                        a = c;
                        c = tmp;
                    }
                    else if(b-a > EPS && b-c > EPS) {
                        tmp = a;
                        a = b;
                        b = tmp;
                    }
                    
                    teta = acos((b*b+c*c-a*a)/(2*b*c));

                    if(fabs(PI/2-teta) < EPS) {
                        cout << "ALMOST";
                        return 0;
                    }
                }
            }
            else if(i == 2) {
                l = 1.0;
                for(int j = 0; j < 2; j++, l = -1*l) {
                    p.x = p2.x + l;
                    p.y = p2.y;

                    a = distanciaPontoAPonto(p, p3);
                    b = distanciaPontoAPonto(p1, p3);
                    c = distanciaPontoAPonto(p1, p);

                    if(c-b > EPS && c-a > EPS) {
                        tmp = a;
                        a = c;
                        c = tmp;
                    }
                    else if(b-a > EPS && b-c > EPS) {
                        tmp = a;
                        a = b;
                        b = tmp;
                    }
                    
                    teta = acos((b*b+c*c-a*a)/(2*b*c));

                    if(fabs(PI/2-teta) < EPS) {
                        cout << "ALMOST";
                        return 0;
                    }
                }
                for(int j = 0; j < 2; j++, l = -1*l) {
                    p.x = p2.x;
                    p.y = p2.y + l;

                    a = distanciaPontoAPonto(p, p3);
                    b = distanciaPontoAPonto(p1, p3);
                    c = distanciaPontoAPonto(p1, p);

                    if(c-b > EPS && c-a > EPS) {
                        tmp = a;
                        a = c;
                        c = tmp;
                    }
                    else if(b-a > EPS && b-c > EPS) {
                        tmp = a;
                        a = b;
                        b = tmp;
                    }
                    
                    teta = acos((b*b+c*c-a*a)/(2*b*c));

                    if(fabs(PI/2-teta) < EPS) {
                        cout << "ALMOST";
                        return 0;
                    }
                }
            }
            else {
                l = 1.0;
                for(int j = 0; j < 2; j++, l = -1*l) {
                    p.x = p3.x + l;
                    p.y = p3.y;

                    a = distanciaPontoAPonto(p2, p);
                    b = distanciaPontoAPonto(p1, p);
                    c = distanciaPontoAPonto(p1, p2);

                    if(c-b > EPS && c-a > EPS) {
                        tmp = a;
                        a = c;
                        c = tmp;
                    }
                    else if(b-a > EPS && b-c > EPS) {
                        tmp = a;
                        a = b;
                        b = tmp;
                    }
                    
                    teta = acos((b*b+c*c-a*a)/(2*b*c));

                    if(fabs(PI/2-teta) < EPS) {
                        cout << "ALMOST";
                        return 0;
                    }
                }
                for(int j = 0; j < 2; j++, l = -1*l) {
                    p.x = p1.x;
                    p.y = p1.y + l;

                    a = distanciaPontoAPonto(p2, p3);
                    b = distanciaPontoAPonto(p, p3);
                    c = distanciaPontoAPonto(p, p2);

                    if(c-b > EPS && c-a > EPS) {
                        tmp = a;
                        a = c;
                        c = tmp;
                    }
                    else if(b-a > EPS && b-c > EPS) {
                        tmp = a;
                        a = b;
                        b = tmp;
                    }
                    
                    teta = acos((b*b+c*c-a*a)/(2*b*c));

                    if(fabs(PI/2-teta) < EPS) {
                        cout << "ALMOST";
                        return 0;
                    }
                }
            }
        }

        cout << "NEITHER";
    }


    return 0;
}

double distanciaPontoAPonto(const point &p1, const point &p2) {
    return sqrt(pow(p1.x-p2.x, 2)+pow(p1.y-p2.y, 2));
}

bool ehColinear(const point &p1, const point &p2, const point &p3) {
    double det = p1.x*p2.y+p3.x*p1.y+p2.x*p3.y-p3.x*p2.y-p1.x*p3.y-p2.x*p1.y;
    if(fabs(det) < EPS)
        return true;
    else
        return false;
}