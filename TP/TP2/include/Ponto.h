#ifndef PONTO_H
#define PONTO_H

class Ponto {
    private:
        float x;
        float y;

    public:
        Ponto();
        ~Ponto();
        Ponto(float x, float y);
        float Distancia(Ponto Ponto);

        void  SetX(float x);
        void  SetY(float y);
        float GetX();
        float GetY();
};

#endif