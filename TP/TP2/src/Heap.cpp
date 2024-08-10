#include "Heap.h"

// Construtor
// int v: Número de vértices

Heap::Heap(int v) {
    capacidade = v;
    data       = new Tripla[capacidade];
    tamanho    = 0;
}

// Destrutor

Heap::~Heap() {
    delete[] data;
}

// int GetAncestral: Obtém o ancestral do nó na posicão especificada
// int p: Especifica a posição

int Heap::GetAncestral(int p) {
    return (p - 1) / 2;
}

// int GetSucessorEsq: Obtém o filho esquerdo do nó na posicão especificada
// int p: Especifica a posição

int Heap::GetSucessorEsq(int p) {
    return 2 * p + 1;
}

// int GetSucessorDir: Obtém o filho esquerdo do nó na posicão especificada
// int p: Especifica a posição

int Heap::GetSucessorDir(int p) {
    return 2 * p + 2;
}

// void HeapifyPorCima: Reorganiza a árvore heap por cima a partir da posição especificada
// int p: Especifica a posição

void Heap::HeapifyPorCima(int p) {
    int ancestral = GetAncestral(p);

    if (p > 0 && data[ancestral].GetDistancia() > data[p].GetDistancia()) {
        Tripla aux = data[p];
        data[p] = data[ancestral];
        data[ancestral] = aux;
        HeapifyPorCima(ancestral);
    }
}

// void HeapifyPorBaixo: Reorganiza a árvore heap por baixo a partir da posição especificada
// int p: Especifica a posição

void Heap::HeapifyPorBaixo(int p) {
    int sucessorEsq = GetSucessorEsq(p);
    int sucessorDir = GetSucessorDir(p);
    int menor = p;

    if (sucessorEsq < tamanho && data[sucessorEsq].GetDistancia() < data[menor].GetDistancia())
        menor = sucessorEsq;

    if (sucessorDir < tamanho && data[sucessorDir].GetDistancia() < data[menor].GetDistancia())
        menor = sucessorDir;

    if (menor != p) {
        Tripla aux = data[p];
        data[p] = data[menor];
        data[menor] = aux;
        HeapifyPorBaixo(menor);
    }
}

// void Inserir: Insere uma tripla na heap
// Tripla t: Tripla a ser inserida

void Heap::Inserir(Tripla t) {
    if (tamanho == capacidade) {
        Redimensionar();
        Inserir(t);
    }

    if (tamanho == 0) {
        data[0] = t;
        tamanho++;
        return;
    }

    data[tamanho] = t;
    HeapifyPorCima(tamanho);
    tamanho++;
}

// bool Vazio: Retorna a informação sobre a heap estar vazia

bool Heap::Vazio() {
    return tamanho == 0;
}

// Tripla Remover: Remove o topo da heap

Tripla Heap::Remover() {
    Tripla min = data[0];
    data[0] = data[tamanho - 1];
    tamanho--;
    HeapifyPorBaixo(0);
    return min;
}

// void Redimensionar: Reorganiza a heap caso a capacidade seja estourada

void Heap::Redimensionar() {
    capacidade *= 2;
    Tripla* newData = new Tripla[capacidade];

    for (int i = 0; i < tamanho; ++i) {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
}