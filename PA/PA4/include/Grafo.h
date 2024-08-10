#ifndef GRAFO_H
#define GRAFO_H

class Grafo {
    public:
        Grafo(int V);
        ~Grafo();
        void InsereAresta(int v, int w, int D);
        int MinimaGeradora();
    private:
        int Vertices;
        int** MatrizAdjacencia;
};

#endif // GRAFO_H
