#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    char chess[8][8];
    bool colunas[8];

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            cin >> chess[i][j];
        }
        colunas[i] = true;
    }

    for(int a = 0; a < 8; a++) {
        if(colunas[a] && chess[0][a] == '.') {
            
        }
        for(int b = 0; b < 8; b++) {
            for(int c = 0; c < 8; c++) {
                for(int d = 0; d < 8; d++) {
                    for(int e = 0; e < 8; e++) {
                        for(int f = 0; f < 8; f++) {
                            for(int g = 0; g < 8; g++) {
                                for(int h = 0; h < 8; h++) {
                                    
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    


    return 0;
}