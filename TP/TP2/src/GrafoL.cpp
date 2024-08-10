#include "GrafoL.h"
#include "Heap.h"
#include "Tripla.h"

#include <iostream>
#include <cmath>
#include <limits>

#define INFINITO std::numeric_limits<float>::max()

using namespace std;

// Construtor
// int v: Número de vértices

GrafoL::GrafoL(int v) {
    Vertices  = v;
    Adjacente = new Lista[v];
    Pontos    = new Ponto[v];
}

// Destrutor

GrafoL::~GrafoL() {
    delete[] Adjacente;
    delete[] Pontos;
}

// void SetPonto: Insere um ponto
// int   v: Vértice do ponto
// Ponto p: Ponto

void GrafoL::SetPonto(int v, Ponto p) {
    if (v < 0 or v >= Vertices) throw invalid_argument("Vértice não contido no grafo.");
    Pontos[v] = p;
}

// void SetAdjacente: Insere uma relação de adjacência (aresta)
// int u: Vértice de origem
// int v: Vértice de chegada

void GrafoL::SetAdjacente(int u, int v) {
    if (u < 0 or u >= Vertices or v < 0 or v >= Vertices) throw invalid_argument("Vértice não contido no grafo.");
    Adjacente[u].InsereFinal(Tripla(v, 0, Pontos[u].Distancia(Pontos[v])));
}

// void SetPortal: Insere uma relação de adjacência (aresta) do tipo portal
// int u: Vértice de origem
// int v: Vértice de chegada

void GrafoL::SetPortal(int u, int v) {
    if (u < 0 or u >= Vertices or v < 0 or v >= Vertices) throw invalid_argument("Vértice não contido no grafo.");
    Adjacente[u].InsereFinal(Tripla(v, 1, 0));
}

// float CalculaDistancia: Implementa o algoritmo Djikstra para calcular a mínima distância entre dois vértices
// int numPortal: Número de portais que podem ser utilizados

float GrafoL::CalculaDistancia(int numPortal) {
    int Fim = Vertices - 1;
    float Distancia[Vertices];

    for (int i = 0; i < Vertices; i++) {
        Distancia[i] = INFINITO;
    }

    Distancia[0] = 0;

    Heap* Queue = new Heap(Vertices);
    Queue->Inserir(Tripla(0, 0, 0));

    while (!Queue->Vazio()) {
        Tripla Topo = Queue->Remover();

        int u = Topo.GetVertice();

        if (u == Fim) {
            delete Queue;
            return Distancia[Fim];
        }

        int p   = Topo.GetPortal();
        float d = Topo.GetDistancia();

        Node* Atual = Adjacente[u].GetPrimeiro()->GetNext();

        while (Atual != nullptr) {
            int v = Atual->GetData().GetVertice();
            if (Atual->GetData().GetPortal()) {
                if (p < numPortal) {
                    if (Distancia[v] > d) {
                        Distancia[v] = d;
                        Queue->Inserir(Tripla(v, p + 1, d));
                    }
                }
            } else {
                float Delta = Atual->GetData().GetDistancia();
                if (Distancia[v] > d + Delta) {
                    Distancia[v] = d + Delta;
                    Queue->Inserir(Tripla(v, p, d + Delta));
                }
            }

            Atual = Atual->GetNext();
        }
    }

    delete Queue;
    return Distancia[Fim];
}

// float AcharCaminho: Implementa o algoritmo A* para encontrar um caminho entre dois vértices
// int numPortal: Número de portais que podem ser utilizados

float GrafoL::AcharCaminho(int numPortal) {
    int Fim = Vertices - 1;
    float Distancia[Vertices];

    Distancia[0] = 0;
    
    for (int i = 1; i < Vertices; i++) {
        Distancia[i] = INFINITO;
    }

    Heap* Queue = new Heap(Vertices);
    Queue->Inserir(Tripla(0, 0, Pontos[0].Distancia(Pontos[Fim])));

    while (!Queue->Vazio()) {
        Tripla Topo = Queue->Remover();

        int u = Topo.GetVertice();

        if (u == Fim) {
            delete Queue;
            return Distancia[Fim];
        }

        int p   = Topo.GetPortal();
        float d = Topo.GetDistancia() - Pontos[u].Distancia(Pontos[Fim]);

        Node* Atual = Adjacente[u].GetPrimeiro()->GetNext();
 
        while (Atual != nullptr) {
            int v = Atual->GetData().GetVertice();

            if (Atual->GetData().GetPortal()) {
                if (p < numPortal) {
                    if (d < Distancia[v]) {
                        Distancia[v] = d;
                        Queue->Inserir(Tripla(v, p + 1, d + Pontos[v].Distancia(Pontos[Fim])));
                    }
                } 
            } else {
                float Delta = Atual->GetData().GetDistancia();
                if (Distancia[v] > d + Delta) {
                    Distancia[v] = d + Delta;
                    Queue->Inserir(Tripla(v, p, d + Delta + Pontos[v].Distancia(Pontos[Fim])));
                }
            }
            Atual = Atual->GetNext();
        }
    }
    
    delete Queue;
    return Distancia[Fim];
}