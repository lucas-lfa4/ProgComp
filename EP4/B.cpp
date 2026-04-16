#include<bits/stdc++.h>

using namespace std;

bool isSafe(char chess[8][8], int linha, int coluna);
void placeQueens(int coluna, char chess[8][8], int& resultado);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    char chess[8][8];

    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            cin >> chess[i][j];

    int resultado = 0;

    placeQueens(0, chess, resultado);

    cout << resultado;

    return 0;
}

bool isSafe(char chess[8][8], int linha, int coluna) {
    if(chess[linha][coluna] == '*')
        return false;
    int i, j;
    
    //checar se existe uma rainha na mesma coluna
    for(i = 0; i < linha; i++)
        if(chess[i][coluna] == 'x')
            return false;

    //checar se existe uma rainha na diagonal
    //superior direita
    i = linha;
    j = coluna;
    while(i >= 0 && j <= 7) {
        if(chess[i][j] == 'x')
            return false;
        else {
            i--;
            j++;
        }
    }
    //superior esquerda
    i = linha;
    j = coluna;
    while(i >=0 && j >= 0) {
        if(chess[i][j] == 'x')
            return false;
        else {
            i--;
            j--;
        }
    }

    return true;
}

void placeQueens(int linha, char chess[8][8], int& resultado) {
    if(linha == 8) {
        resultado++;
        return;
    }

    for(int i = 0; i < 8; i++) {
        if(isSafe(chess, linha, i)) {
            chess[linha][i] = 'x';
            placeQueens(linha+1, chess, resultado);

            chess[linha][i] = '.';
        }
    }
}