#ifndef HEAP_H
#define HEAP_H

#include "Tripla.h"

class Heap {
    public:
        Heap(int v);
        ~Heap();

        void Inserir(Tripla P);
        Tripla Remover();

        bool Vazio();

    private:
        int GetAncestral(int posicao);
        int GetSucessorEsq(int posicao);
        int GetSucessorDir(int posicao);

        int tamanho;
        int capacidade;
        Tripla* data;

        void HeapifyPorBaixo(int posicao);
        void HeapifyPorCima(int posicao);
        void Redimensionar();
};

#endif