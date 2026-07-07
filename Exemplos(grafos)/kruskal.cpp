#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> iii;

class UnionFind {
    private:
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
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E;
    cin >> E >> V;

    vector<iii> EL(E);
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;  // read as (u, v, w)
        EL[i] = {w, u, v};   // reorder as (w, u, v)
    }

    sort(EL.begin(), EL.end());

    int mst_cost = 0, num_taken = 0;    //nenhuma aresta pega

    UnionFind UF(V);

    for(int i  = 0; i < E && num_taken != V-1; i++) {
        auto [w, u, v] = EL[i];
        if(UF.mesmoGrupo(u, v)) continue;
        mst_cost += w;
        UF.unite(u, v);
        num_taken++;
    }


    return 0;
}