#include "Heap.h"
#include <stdexcept>

Heap::Heap(int maxsize) : tamanho(0) {
    data = new Aresta[maxsize];
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

    if (posicao > 0 && data[ancestral].custo > data[posicao].custo) {
        std::swap(data[posicao], data[ancestral]);
        HeapifyPorCima(ancestral);
    }
}

void Heap::HeapifyPorBaixo(int posicao) {
    int sucessorEsq = GetSucessorEsq(posicao);
    int sucessorDir = GetSucessorDir(posicao);
    int menor = posicao;

    if (sucessorEsq < tamanho && data[sucessorEsq].custo < data[menor].custo)
        menor = sucessorEsq;

    if (sucessorDir < tamanho && data[sucessorDir].custo < data[menor].custo)
        menor = sucessorDir;

    if (menor != posicao) {
        std::swap(data[posicao], data[menor]);
        HeapifyPorBaixo(menor);
    }
}

void Heap::Inserir(Aresta x) {
    data[tamanho] = x;
    HeapifyPorCima(tamanho);
    tamanho++;
}

bool Heap::Vazio() {
    return tamanho == 0;
}

Aresta Heap::Remover() {
    Aresta min = data[0];
    data[0] = data[tamanho - 1];
    tamanho--;
    HeapifyPorBaixo(0);
    return min;
}