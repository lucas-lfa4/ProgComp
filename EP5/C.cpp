#include<bits/stdc++.h>

using namespace std;

bool isSorted(vector<int> a);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    vector<int> a;
    bool isSorted = false;

    for(int i = 0; i < t; i++) {
        cin >> n;
        a.resize(n);

        for(int j = 0; j < n; j++) {
            cin >> a[i];
        }

        while() {

        }
    }

    return 0;
}

bool isSorted(vector<int> a) {
    for(auto it = a.begin(); it != a.end()-1; it++)
        if(*it > *(it+1))
            return false;

    return true;
}