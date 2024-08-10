#include "Grafo.h"
#include "ListaAdjacencia.h"

#include <iostream>
#include <cmath>
#include <limits>

#define INFINITO std::numeric_limits<float>::infinity()

using namespace std;

Grafo::Grafo() {}

Grafo::~Grafo() {}

void Grafo::InsereVertice() {
    Lista L;
    Vertices.InsereFinal(L);
}

void Grafo::InsereAresta(int u, int v) {
    Lista L = Vertices.GetItem(u);
    L.InsereFinal(v);
    Vertices.SetItem(L, u);
}

int Grafo::QuantidadeVertices() {
    return Vertices.GetTamanho();
}

int Grafo::QuantidadeArestas() {
    int Arestas = 0;
    for (int i = 0; i < Vertices.GetTamanho(); i++) {
        Arestas += Vertices.GetItem(i).GetTamanho();
    }
    return Arestas/2;
}

int Grafo::GrauMaximo() {
    int grauMaximo = 0;
    for (int i = 0; i < Vertices.GetTamanho(); i++) {
        int tamanhoLista = Vertices.GetItem(i).GetTamanho();
        if (tamanhoLista > grauMaximo) {
            grauMaximo = tamanhoLista;
        }
    }
    return grauMaximo;
}

int Grafo::GrauMinimo() {
    int grauMinimo = Vertices.GetItem(0).GetTamanho();
    for (int i = 1; i < Vertices.GetTamanho(); i++) {
        int tamanhoLista = Vertices.GetItem(i).GetTamanho();
        if (tamanhoLista < grauMinimo) {
            grauMinimo = tamanhoLista;
        }
    }
    return grauMinimo;
}

void Grafo::ImprimeVizinhos(int v) {
    Lista L = Vertices.GetItem(v);
    L.Imprime();
}