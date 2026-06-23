#include<bits/stdc++.h>

using namespace std;

class UnionFind {
    vector<int> parent;
    vector<int> tamanho;

    public:
        UnionFind(int size) {
            parent.resize(size);
            tamanho.resize(size);

            for(int i = 0; i < size; i++) {
                parent[i] = i;
                tamanho[i] = 1;
            }
        }

        int find(int i) {
            if(parent[i] == i)
                return i;
            return parent[i] = find(parent[i]);
        }

        void unite(int i, int j) {
            int irep = find(i);
            int jrep = find(j);

            parent[irep] = jrep;

            if(irep != jrep)
                tamanho[jrep] += tamanho[irep];
        }

        bool mesmoGrupo(int i, int j) {
            if(find(i) == find(j))
                return true;
            else 
                return false;
        }

        long long int attReps(int i, int j) {
            int irep = find(i);
            int jrep = find(j);

            return (long long int) tamanho[irep] * tamanho[jrep];
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    int a, b;
    cin >> N >> M;

    UnionFind grafo(N);
    int matriz[M][2];

    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        matriz[i][0] = a-1;
        matriz[i][1] = b-1;
    }
    
    vector<long long int> inconvenience(M, 0);
    long long int inconveniencia_atual = (long long int) N*(N-1)/2;

    for(int i = M-1; i >= 0; i--) {
        inconvenience[i] = inconveniencia_atual;
        if(grafo.mesmoGrupo(matriz[i][0], matriz[i][1])) {
            grafo.unite(matriz[i][0], matriz[i][1]);
        }
        else {
            inconveniencia_atual -= grafo.attReps(matriz[i][0], matriz[i][1]);
            grafo.unite(matriz[i][0], matriz[i][1]);
        }
    }

    for(int i  = 0; i < M; i++)
        cout << inconvenience[i] << "\n";

    return 0;
}