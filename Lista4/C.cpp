#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    char sudoku[9][9];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 9; j++) {
            for(int k = 0; k < 9; k++) {
                cin >> sudoku[j][k];
            }
        }
    }
    

    return 0;
}