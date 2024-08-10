#ifndef GRAFOM_H
#define GRAFOM_H

#include "Ponto.h"
#include "Tripla.h"

class GrafoM {
    private:
        int      Vertices;
        Ponto*   Pontos;
        Tripla** Adjacente;

    public:
        GrafoM(int n);
        ~GrafoM();
        
        void SetAdjacente(int u, int v);
        void SetPortal(int u, int v);
        void SetPonto(int u, Ponto P);

        float CalculaDistancia(int numPortal);
        float AcharCaminho(int numPortal);
};

#endif