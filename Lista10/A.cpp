#include<bits/stdc++.h>
#define EPS 0.000000001
using namespace std;

// struct point_i {int x, y;}
struct point_i {
    int x, y;
    point_i() { x = y = 0; }
    point_i(int _x, int _y) : x(_x), y(_y) {}
};

struct point {
    double x, y;
    point() { x = y = 0.0; }
    point(int _x, int _y) : x(_x), y(_y) {}
    bool operator < (point other) const {
        if(fabs(x-other.x) > EPS)
            return x < other.x;
        return y < other.y;
    }
    bool operator == (point other) const {
        return (fabs(x-other.x) < EPS) && (fabs(y-other.y) < EPS);
    }
};

// Reatas
struct line {
    double a, b, c;
};

// Função para dar a equação da reta a partir de dois pontos
void pointToLine(const point &p1, const point &p2, line &l) {
    if(fabs(p1.x - p2.x) < EPS)
        l = {1.0, 0.0, -1*p1.x};
    else
        l = {(double)(p1.y - p2.y), (double)(p2.x-p1.x), (double)(p1.x*p2.y-p2.x*p1.y)};
}

double area(const vector<point> &P);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<point> P(n);

    for(int i = 0; i < n; i++)
        cin >> P[i].x >> P[i].y;

    P.push_back(P[0]);

    cout << area(P);
    


    return 0;
}

double area(const vector<point> &P) {
    double ans = 0.0;
    for(int i = 0; i < P.size()-1; i++)
        ans += P[i].x*P[i+1].y - P[i].y*P[i+1].x;
    return fabs(ans)/2.0;
}