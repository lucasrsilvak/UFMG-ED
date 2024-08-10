#ifndef GRAFO_H
#define GRAFO_H

#include "ListaAdjacencia.h"

class Grafo{
    public:
        Grafo();
        ~Grafo();
        void InsereVertice();
        void InsereAresta(int v, int w);
        int QuantidadeVertices();
        int QuantidadeArestas();
        int GrauMinimo();
        int GrauMaximo();
        void ImprimeVizinhos(int v);
    private:
        ListaAdjacencia Vertices;
};

#endif // GRAFO_H
