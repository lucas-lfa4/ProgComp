#include <bits/stdc++.h>

using namespace std;

bool possoColocarEsseNumero(int numero, int sudoku[9][9], int linha, int coluna);
void colocarNumero(int sudoku[9][9], int linha, int coluna, int** resultado);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    char sudoku[9][9];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < 9; j++)
            for(int k = 0; k < 9; k++)
                cin >> sudoku[j][k];
    
    
    

    return 0;
}

bool possoColocarEsseNumero(int numero, int sudoku[9][9], int linha, int coluna) {
    if(sudoku[linha][coluna] != 0)
        return false;
    
    //checar se existe o mesmo numero na linha ou coluna
    for(int i = 0; i < 9; i++) {
        if(sudoku[linha][i] == numero)
            return false;
        if(sudoku[i][coluna] == numero)
            return false;
    }

    //checar se existe o mesmo numero no mesmo quadrante
    if(linha <= 2 && coluna <= 2) {
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                if(sudoku[i][j] == numero)
                    return false;
    }
    else if(linha >= 3 && linha <= 5 && coluna <= 2) {
        for(int i = 3; i < 6; i++)
            for(int j = 0; j < 3; j++)
                if(sudoku[i][j] == numero)
                    return false;
    }
    else if(linha >= 6 && linha <= 8 && coluna <= 2) {
        for(int i = 6; i < 9; i++)
            for(int j = 0; j < 3; j++)
                if(sudoku[i][j] == numero)
                    return false;
    }
    else if(linha <= 2 && coluna >=3 && coluna <= 5) {
        for(int i = 0; i < 3; i++)
            for(int j = 3; j < 6; j++)
                if(sudoku[i][j] == numero)
                    return false;
    }
    else if(linha >= 3 && linha <= 5 && coluna >= 3 && coluna <= 5) {
        for(int i = 3; i < 6; i++)
            for(int j = 3; j < 6; j++)
                if(sudoku[i][j] == numero)
                    return false;
    }
    else if(linha >= 6 && linha <= 8 && coluna >= 3 && coluna <= 5) {
        for(int i = 6; i < 9; i++)
            for(int j = 3; j < 6; j++)
                if(sudoku[i][j] == numero)
                    return false;
    }
    else if(linha <= 2 && coluna >= 6 && coluna <= 8) {
        for(int i = 0; i < 3; i++)
            for(int j = 6; j < 9; j++)
                if(sudoku[i][j] == numero)
                    return false;
    }
    else if(linha >= 3 && linha <= 5 && coluna >= 6 && coluna <= 8) {
        for(int i = 3; i < 6; i++)
            for(int j = 6; j < 9; j++)
                if(sudoku[i][j] == numero)
                    return false;
    }
    else if (linha >= 6 && linha <= 8 && coluna >= 6 && coluna <= 8) {
        for(int i = 6; i < 9; i++)
            for(int j = 6; j < 9; j++)
                if(sudoku[i][j] == numero)
                    return false;
    }
}

void colocarNumero(int sudoku[9][9], int linha, int coluna, int** resultado) {
    if(linha == 9) {

    }

    
}