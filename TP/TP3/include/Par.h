#ifndef PAR_H
#define PAR_H

#include "Estacao.h"

class Par {
    private:
        Estacao Ponto;
        double Distancia;

    public:
        Par();
        Par(Estacao Ponto, double Distancia);
        ~Par();

        Estacao GetPonto();
        double GetDistancia();
};

#endif // PAR_H