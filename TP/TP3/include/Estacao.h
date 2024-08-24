#ifndef ESTACAO_H
#define ESTACAO_H

#include <string>

using namespace std;

class Estacao {
    private:
        string  ID;
        long    ID_Logradouro;
        string  Sigla;
        string  Logradouro;
        int     Numero;
        string  Bairro;
        string  Regiao;
        int     Cep;
        double  X;
        double  Y;
        bool    Ativa;

    public:
        Estacao();
        Estacao(string ID, long ID_logradouro, string Sigla, string Logradouro, int Numero, string Bairro, string Regiao, int Cep, double X, double Y);
        ~Estacao();

        void Ativar();
        void Desativar();
        bool IsAtiva();

        string GetEndereco();
        double GetX();
        double GetY();
        string GetID();
};

#endif // ESTACAO_H