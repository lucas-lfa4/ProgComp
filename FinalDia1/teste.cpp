#include <bits/stdc++.h>

using namespace std;

void MergeSort(vector<int>& array, int l, int r);
void Merge(vector<int>& array, int l, int r);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> A(n);

    for(int i=0; i < n; i++)
        cin >> A[i];

    sort(A.begin(), A.end());

    int cnt, atual;

    for(int i=0; i < n; i++) {
        if(i==0) {
            atual = A[0];
            cnt = 1;
        }
        else {
            if(A[i] != atual) {
                cnt++;
                atual = A[i];
            }
        }
    }

    cout << cnt << endl;
    
    

    return 0;
}

void MergeSort(vector<int>& array, int l, int r) {
    int m = (l+r)/2;

    if(l < r) {
        MergeSort(array, l, m);
        MergeSort(array, m+1, r);
        Merge(array, l, r);
    }
}

void Merge(vector<int>& array, int l, int r) {
    int i, m, i1, i2;
    vector<int> tmp(array.size());

    for(i = l; i <= r; i++)
        tmp[i] = array[i];

    m = (l+r)/2;
    i1 = l;
    i2 = m+1;

    for(i = l; i <= r; i++) {
        if(i1 == m+1)
            array[i] = tmp[i2++];
        else if(i2 > r)
            array[i] = tmp[i1++];
        else if(tmp[i1] <= tmp[i2])
            array[i] = tmp[i1++];
        else
            array[i] = tmp[i2++];
    }
}