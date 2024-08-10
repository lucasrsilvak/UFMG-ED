typedef struct s_edge{
    int u;
    int v;
    int custo;
} Aresta;

#ifndef HEAP_H
#define HEAP_H

class Heap {
    public:
        Heap(int maxsize);
        ~Heap();

        void Inserir(Aresta x);
        Aresta Remover();

        bool Vazio();

    private:
        int GetAncestral(int posicao);
        int GetSucessorEsq(int posicao);
        int GetSucessorDir(int posicao);

        int tamanho;
        Aresta* data;

        void HeapifyPorBaixo(int posicao);
        void HeapifyPorCima(int posicao);
};

#endif