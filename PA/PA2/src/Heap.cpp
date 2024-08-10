#include "Heap.h"

Heap::Heap(int maxsize) {
    data = new int[maxsize];
    tamanho = 0;
}

Heap::~Heap() {
    delete[] data;
}

int Heap::GetAncestral(int posicao) {
    return (posicao - 1) / 2;
}

int Heap::GetSucessorEsq(int posicao) {
    return 2 * posicao + 1;
}

int Heap::GetSucessorDir(int posicao) {
    return 2 * posicao + 2;
}

void Heap::HeapifyPorCima(int posicao) {
    int ancestral = GetAncestral(posicao);

    if (posicao > 0 && data[ancestral] > data[posicao]) {
        int aux = data[posicao];
        data[posicao] = data[ancestral];
        data[ancestral] = aux;
        HeapifyPorCima(ancestral);
    }
}

void Heap::HeapifyPorBaixo(int posicao) {
    int sucessorEsq = GetSucessorEsq(posicao);
    int sucessorDir = GetSucessorDir(posicao);
    int menor = posicao;

    if (sucessorEsq < tamanho && data[sucessorEsq] < data[menor])
        menor = sucessorEsq;

    if (sucessorDir < tamanho && data[sucessorDir] < data[menor])
        menor = sucessorDir;

    if (menor != posicao) {
        int aux = data[posicao];
        data[posicao] = data[menor];
        data[menor] = aux;
        HeapifyPorBaixo(menor);
    }
}

void Heap::Inserir(int x) {
    if (tamanho == 0) {
        data[0] = x;
        tamanho++;
        return;
    }

    data[tamanho] = x;
    HeapifyPorCima(tamanho);
    tamanho++;
}

bool Heap::Vazio() {
    return tamanho == 0;
}

int Heap::Remover() {
    int min = data[0];
    data[0] = data[tamanho - 1];
    tamanho--;
    HeapifyPorBaixo(0);
    return min;
}