#ifndef TRIPLA_H
#define TRIPLA_H

class Tripla {
    private:
        int   Vertice;
        bool  Portal;
        float Distancia;

    public:
        Tripla();
        ~Tripla();
        Tripla(int Vertice, bool Portal, float Distancia);

        int GetVertice();
        bool GetPortal();
        float GetDistancia();
};

#endif