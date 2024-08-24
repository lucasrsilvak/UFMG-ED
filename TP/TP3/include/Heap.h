#ifndef HEAP_H
#define HEAP_H

#include "Par.h"

class Heap {
    private:
        int Tamanho;
        int Capacidade;
        Par* Data;

        int GetAncestral(int Posicao);
        int GetSucessorEsq(int Posicao);
        int GetSucessorDir(int Posicao);

        void HeapifyPorBaixo(int Posicao);
        void HeapifyPorCima(int Posicao);
        void Redimensionar();

    public:
        Heap(int Tamanho);
        ~Heap();

        void Inserir(Par P);
        void Inverter();
        Par Remover();

        bool Vazio();
        int GetTamanho();
        Par Topo();
        Par GetElemento(int Posicao);
};

#endif // HEAP_H