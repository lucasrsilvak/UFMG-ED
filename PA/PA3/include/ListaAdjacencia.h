#ifndef LISTAADJ_H
#define LISTAADJ_H

#include "Lista.h"

class ListaAdjacencia {
private:
    class NodeAdjacencia {
    public:
        NodeAdjacencia() : prox(nullptr) {};
    private:
        Lista item;
        NodeAdjacencia* prox;
        friend class ListaAdjacencia;
    };

public:
    ListaAdjacencia();
    ~ListaAdjacencia();
    Lista GetItem(int pos);
    void SetItem(Lista item, int pos);
    void InsereInicio(Lista item);
    void InsereFinal(Lista item);
    void InserePosicao(Lista item, int pos);
    Lista RemoveInicio();
    Lista RemoveFinal();
    Lista RemovePosicao(int pos);
    Lista Pesquisa(int c);
    int GetTamanho();
    void Imprime();
    void Limpa();

private:
    int tamanho;
    NodeAdjacencia* primeiro;
    NodeAdjacencia* ultimo;
    NodeAdjacencia* PosicionaAntes(int pos);
    NodeAdjacencia* PosicionaDepois(int pos);
};

#endif
