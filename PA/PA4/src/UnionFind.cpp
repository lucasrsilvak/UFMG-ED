#include "UnionFind.h"

UnionFind::UnionFind(int V) : tamanho(V) {
    subconjuntos = new Subconjunto[V];
    for (int i = 0; i < V; ++i) {
        subconjuntos[i].representante = i;
        subconjuntos[i].rank = 0;
    }
}

UnionFind::~UnionFind() {
    delete[] subconjuntos;
}

int UnionFind::Find(int E) {
    if (subconjuntos[E].representante != E) {
        subconjuntos[E].representante = Find(subconjuntos[E].representante);
    }
    return subconjuntos[E].representante;
}

void UnionFind::Union(int E, int F) {
    int raiz_x = Find(E);
    int raiz_y = Find(F);

    if (raiz_x != raiz_y) {
        if (subconjuntos[raiz_x].rank < subconjuntos[raiz_y].rank) {
            subconjuntos[raiz_x].representante = raiz_y;
        } else if (subconjuntos[raiz_x].rank > subconjuntos[raiz_y].rank) {
            subconjuntos[raiz_y].representante = raiz_x;
        } else {
            subconjuntos[raiz_y].representante = raiz_x;
            subconjuntos[raiz_x].rank++;
        }
    }
}