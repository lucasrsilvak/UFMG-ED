#include "Grafo.h"
#include "Heap.h"
#include "UnionFind.h"

#include <iostream>
#include <limits>

using namespace std;

Grafo::Grafo(int V) : Vertices(V) {
    MatrizAdjacencia = new int*[Vertices];
    for (int i = 0; i < Vertices; ++i) {
        MatrizAdjacencia[i] = new int[Vertices];
        for (int j = 0; j < Vertices; ++j) {
            MatrizAdjacencia[i][j] = -1;
        }
    }
}

Grafo::~Grafo() {
    for (int i = 0; i < Vertices; ++i) {
        delete[] MatrizAdjacencia[i];
    }
    delete[] MatrizAdjacencia;
}

void Grafo::InsereAresta(int u, int v, int D) {
    MatrizAdjacencia[u][v] = D;
    MatrizAdjacencia[v][u] = D;
}

int Grafo::MinimaGeradora() {
    int Custo = 0;
    int Arestas = 0;

    UnionFind uf(Vertices);

    Heap H(Vertices * (Vertices - 1) / 2);

    for (int i = 0; i < Vertices; ++i) {
        for (int j = i + 1; j < Vertices; ++j) {
            if (MatrizAdjacencia[i][j] != -1) {
                Aresta aresta = {i, j, MatrizAdjacencia[i][j]};
                H.Inserir(aresta);
            }
        }
    }

    while (!H.Vazio() && Arestas < Vertices - 1) {
        Aresta aresta = H.Remover();
        int u = aresta.u;
        int v = aresta.v;
        int custo = aresta.custo;

        if (uf.Find(u) != uf.Find(v)) {
            uf.Union(u, v);
            Custo += custo;
            Arestas++;
        }
    }
    return Custo;
}
