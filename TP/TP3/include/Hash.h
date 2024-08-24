#ifndef HASH_H
#define HASH_H

#include "Estacao.h"
#include <string>

using namespace std;

class Hash {
    private:
        struct HashEntry {
            string id;
            int index;
            bool temElemento;
            bool foiDeletada;
        };

        HashEntry* tabela;
        int tamanho;

        int Chaveamento(const string& key);

    public:
        Hash(int N);
        ~Hash();

        bool Inserir(const string& id, int index);
        int Procurar(const string& id);
};

#endif // HASH_H