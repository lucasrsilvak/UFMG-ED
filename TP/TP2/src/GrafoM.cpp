#include "GrafoM.h"
#include "Heap.h"
#include "Tripla.h"

#include <iostream>
#include <cmath>
#include <limits>
 
#define INFINITO std::numeric_limits<float>::infinity()

using namespace std;

// Construtor
// int v: Número de vértices

GrafoM::GrafoM(int v) {
    Vertices = v;

    Adjacente = new Tripla*[v];
    Pontos = new Ponto[v];
    
    for (int i = 0; i < v; ++i) {
        Adjacente[i] = new Tripla[v];
        for (int j = 0; j < v; ++j) {
            Adjacente[i][j] = Tripla(0, 0, 0);
        }
    }
}

// Destrutor

GrafoM::~GrafoM() {
    delete[] Pontos;
    for (int i = 0; i < Vertices; ++i) {
        delete[] Adjacente[i];
    }
    delete[] Adjacente;
}

// void SetPonto: Insere um ponto
// int   v: Vértice do ponto
// Ponto p: Ponto

void GrafoM::SetPonto(int v, Ponto p) {
    if (v < 0 or v >= Vertices) throw invalid_argument("Vértice não contido no grafo.");
    Pontos[v] = p;
}

// void SetAdjacente: Insere uma relação de adjacência (aresta)
// int u: Vértice de origem
// int v: Vértice de chegada

void GrafoM::SetAdjacente(int u, int v) {
    if (u < 0 or u >= Vertices or v < 0 or v >= Vertices) throw invalid_argument("Vértice não contido no grafo.");
    Adjacente[u][v] = Tripla(1, 0, Pontos[u].Distancia(Pontos[v]));
}

// void SetPortal: Insere uma relação de adjacência (aresta) do tipo portal
// int u: Vértice de origem
// int v: Vértice de chegada

void GrafoM::SetPortal(int u, int v) {
    if (u < 0 or u >= Vertices or v < 0 or v >= Vertices) throw invalid_argument("Vértice não contido no grafo.");
    Adjacente[u][v] = Tripla(1, 1, 0);
}

// float CalculaDistancia: Implementa o algoritmo Djikstra para calcular a mínima distância entre dois vértices
// int numPortal: Número de portais que podem ser utilizados

float GrafoM::CalculaDistancia(int numPortal) {
    int Fim = Vertices - 1;
    float Distancia[Vertices];

    for (int i = 0; i < Vertices; i++) {
        Distancia[i] = INFINITO;
    }

    Distancia[0] = 0;
    
    Heap* Queue = new Heap(Vertices);
    Queue->Inserir(Tripla(0, 0, 0));

    while(!Queue->Vazio()) {
        Tripla Topo = Queue->Remover();
        int u = Topo.GetVertice();
        int p = Topo.GetPortal();
        float d = Topo.GetDistancia();

        if (u == Fim) {
            delete Queue;
            return Distancia[Fim];
        }

        for (int v = 0; v < Vertices; v++) {
            if (Adjacente[u][v].GetVertice()) {
                if (Adjacente[u][v].GetPortal()) {
                    if (p < numPortal) {
                        if (Distancia[v] > d) {
                            Distancia[v] = d;
                            Queue->Inserir(Tripla(v, p + 1, d));
                        }
                    }
                } else {
                    float Delta = Adjacente[u][v].GetDistancia();
                    if (Distancia[v] > d + Delta) {
                        Distancia[v] = d + Delta;
                        Queue->Inserir(Tripla(v, p, d + Delta));
                    }
                }
            }
        }
    }

    delete Queue;
    return Distancia[Fim];
}

// float AcharCaminho: Implementa o algoritmo A* para encontrar um caminho entre dois vértices
// int numPortal: Número de portais que podem ser utilizados

float GrafoM::AcharCaminho(int numPortal) {
    int Fim = Vertices - 1;
    float Distancia[Vertices];

    for (int i = 0; i < Vertices; i++) {
        Distancia[i] = INFINITO;
    }

    Distancia[0] = 0;
    
    Heap* Queue = new Heap(Vertices);
    Queue->Inserir(Tripla(0, 0, Pontos[0].Distancia(Pontos[Fim])));

    while(!Queue->Vazio()) {
        Tripla Topo = Queue->Remover();
        int u = Topo.GetVertice();
        int p = Topo.GetPortal();
        float d = Topo.GetDistancia() - Pontos[u].Distancia(Pontos[Fim]);

        if (u == Fim) {
            delete Queue;
            return Distancia[Fim];
        }

        for (int v = 0; v < Vertices; v++) {
            if (Adjacente[u][v].GetVertice()) {
                if (Adjacente[u][v].GetPortal()) {
                    if (p < numPortal) {
                        if (Distancia[v] > d) {
                            Distancia[v] = d;
                            Queue->Inserir(Tripla(v, p + 1, d + Pontos[v].Distancia(Pontos[Fim])));
                        }
                    }
                } else {
                    float Delta = Adjacente[u][v].GetDistancia();
                    if (Distancia[v] > d + Delta) {
                        Distancia[v] = d + Delta;
                        Queue->Inserir(Tripla(v, p, d + Delta + Pontos[v].Distancia(Pontos[Fim])));
                    }
                }
            }
        }
    }

    delete Queue;
    return Distancia[Fim];
}