#include <bits/stdc++.h>

using namespace std;

bool possoColocarEsseNumero(int numero, int sudoku[9][9], int linha, int coluna);
void colocarNumero(int sudoku[9][9], int linha, int coluna, bool* existeSol);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    int sudoku[9][9];
    bool existeSol = false;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 9; j++)
            for(int k = 0; k < 9; k++)
                cin >> sudoku[j][k];
        colocarNumero(sudoku, 0, 0, &existeSol);
        if(!existeSol)
            cout << "No solution\n";
        existeSol = false;
    }

    return 0;
}

bool possoColocarEsseNumero(int numero, int sudoku[9][9], int linha, int coluna) {
    //checar se existe o mesmo numero na linha ou coluna
    for(int i = 0; i < 9; i++) {
        if(sudoku[linha][i] == numero)
            return false;
        if(sudoku[i][coluna] == numero)
            return false;
    }

    //checar se existe o mesmo numero no mesmo quadrante
    int comecoLinha = linha - (linha % 3), comecoColuna = coluna - (coluna % 3);

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (sudoku[i + comecoLinha][j + comecoColuna] == numero)
                return false;

    return true;
}

void colocarNumero(int sudoku[9][9], int linha, int coluna, bool* existeSol) {
    if(linha == 9 && coluna == 8) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++)
                cout << sudoku[i][j] << " ";

            cout << "\n";
        }
        *existeSol = true;
        return;
    }

    if(linha == 9) {
        coluna++;
        linha = 0;
    }

    if(sudoku[linha][coluna] != 0) {
        colocarNumero(sudoku, linha+1, coluna, existeSol);
        return;
    }

    for(int i = 1; i <= 9; i++) {
        if(possoColocarEsseNumero(i, sudoku, linha, coluna)) {
            sudoku[linha][coluna] = i;
            colocarNumero(sudoku, linha+1, coluna, existeSol);
            sudoku[linha][coluna] = 0;
        }
    }
}