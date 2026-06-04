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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    return 0;
}