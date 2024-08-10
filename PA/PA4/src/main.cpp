#include <iostream>
#include "Grafo.h"
#include "UnionFind.h"

using namespace std;

int main() {
    int n, m;
    
    cin >> n >> m;

    Grafo G(n);

    for (int i = 0; i < m; i++) {
        int u, v, D;
        cin >> u >> v >> D;
        G.InsereAresta(u, v, D);
    }

    cout << G.MinimaGeradora() << endl;

    return 0;
}
