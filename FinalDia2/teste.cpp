#include <iostream>

using namespace std;

const int MAXN = 10000000;

// Arrays globais alocados na BSS (automaticamente inicializados com false/0)
bool is_prime[MAXN + 1];
bool is_beautiful[MAXN + 1];

int main() {
    // Otimização de I/O obrigatória para grandes volumes de consultas (fast I/O)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 1. Inicializamos considerando todos como potenciais primos a partir do 2
    for (int i = 2; i <= MAXN; i++) {
        is_prime[i] = true;
    }

    // 2. Crivo de Eratóstenes para marcar os não-primos
    for (long long p = 2; p * p <= MAXN; p++) {
        if (is_prime[p]) {
            for (long long i = p * p; i <= MAXN; i += p) {
                is_prime[i] = false;
            }
        }
    }

    // 3. Definimos a propriedade "beautiful" para os números iterando de baixo para cima
    int prime_count = 0; // Guarda a quantidade total de primos encontrados até agora

    for (int p = 2; p <= MAXN; p++) {
        if (is_prime[p]) {
            prime_count++; // Atualiza a posição (o primo 'p' é o prime_count-ésimo primo)

            if (p == 2) {
                is_beautiful[p] = true; // Caso base
            } else {
                // A quantidade de primos menores que 'p' é exatamente (prime_count - 1).
                // Logo, 'p' só é lindo se esse número anterior também foi registrado como lindo.
                is_beautiful[p] = is_beautiful[prime_count - 1];
            }
        }
    }

    // 4. Respondendo às consultas
    int q;
    if (cin >> q) {
        while (q--) {
            int n;
            cin >> n;
            if (is_beautiful[n]) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}