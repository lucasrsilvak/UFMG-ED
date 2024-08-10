#ifndef GRAFOL_H
#define GRAFOL_H

#include "Lista.h"
#include "Ponto.h"

class GrafoL {
    private:
        int    Vertices;
        Lista* Adjacente;
        Ponto* Pontos;

    public:
        GrafoL(int n);
        ~GrafoL();

        void SetAdjacente(int u, int v);
        void SetPortal(int u, int v);
        void SetPonto(int u, Ponto P);
        
        float CalculaDistancia(int numPortal);
        float AcharCaminho(int numPortal);
};

#endif