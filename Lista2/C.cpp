#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b, num_quartos = 0;
    cin >> n;
    
    //matriz que as colunas são: dia chegada, dia de saída e indice da reserva.
    vector<vector<int>> vec(n, vector<int>(3));

    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        vec[i][0] = a;
        vec[i][1] = b;
        vec[i][2] = i;
    }

    //Ordenar o a matriz com base no dia da chegada crescente
    sort(vec.begin(), vec.end());
    /*for(int i = 0; i < n; i++) {
        cout << vec[i][0] << " " << vec[i][1] << " "<< vec[i][2] << endl;
    }*/

    //Heap de minimo que guarda {dia de saida, numero do quarto}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> quartos_ocupados;

    //vetor que guarda o quarto alocado para cada hospede
    vector<int> quarto(n);
    int dia_chegada;
    int dia_saida;
    int indice;

    for(int i = 0; i < n; i++) {
        dia_chegada = vec[i][0];
        dia_saida = vec[i][1];
        indice = vec[i][2];

        //Hotel vazio ou quarto livre, novo hospede pega
        if(quartos_ocupados.empty()) {
            quartos_ocupados.emplace(dia_saida, 1);
            quarto[indice] = 1;
            num_quartos++;
        }
        else if(quartos_ocupados.top().first < dia_chegada) {
            quartos_ocupados.emplace(dia_saida, quartos_ocupados.top().second);
            quarto[indice] = quartos_ocupados.top().second;
            quartos_ocupados.pop();
        }
        else {
            //Nao tem nenhum quarto livre, arruma outro quarto e coloca na Heap
            num_quartos++;
            quarto[indice] = num_quartos;
            quartos_ocupados.emplace(dia_saida, num_quartos);
        }
    }

    cout << num_quartos << "\n";
    for(int i = 0; i < n; i++)
        cout << quarto[i] << " ";

    return 0;
}