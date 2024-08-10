#ifndef LISTA_H
#define LISTA_H

#include "Tripla.h"
#include "Node.h"

class Lista {
private:
    int tamanho;

    Node* primeiro;
    Node* ultimo;

public:
    Lista();
    ~Lista();
    
    Tripla GetItem(int pos);
    Node* GetPrimeiro();

    int GetTamanho();
    void InsereFinal(Tripla item);
};

#endif
