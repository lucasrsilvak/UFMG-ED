#include "Heap.h"

// Construtor
// int n: Define a capacidade da Heap
Heap::Heap(int n) {
    Capacidade = n;
    Data = new Par[Capacidade];
    Tamanho = 0;
}

// Destrutor
Heap::~Heap() {
    delete[] Data;
}

// int GetAncestral: Obtém o ancestral do nó na posição especificada
// int p: Especifica a posição
int Heap::GetAncestral(int p) {
    return (p - 1) / 2;
}

// int GetSucessorEsq: Obtém o filho esquerdo do nó na posição especificada
// int p: Especifica a posição
int Heap::GetSucessorEsq(int p) {
    return 2 * p + 1;
}

// int GetSucessorDir: Obtém o filho direito do nó na posição especificada
// int p: Especifica a posição
int Heap::GetSucessorDir(int p) {
    return 2 * p + 2;
}

// void HeapifyPorCima: Reorganiza a árvore heap por cima a partir da posição especificada
// int p: Especifica a posição
void Heap::HeapifyPorCima(int p) {
    int ancestral = GetAncestral(p);

    if (p > 0 && Data[ancestral].GetDistancia() < Data[p].GetDistancia()) {
        Par aux = Data[p];
        Data[p] = Data[ancestral];
        Data[ancestral] = aux;
        HeapifyPorCima(ancestral);
    }
}

// void HeapifyPorBaixo: Reorganiza a árvore heap por baixo a partir da posição especificada
// int p: Especifica a posição
void Heap::HeapifyPorBaixo(int p) {
    int sucessorEsq = GetSucessorEsq(p);
    int sucessorDir = GetSucessorDir(p);
    int maior = p;

    if (sucessorEsq < Tamanho && Data[sucessorEsq].GetDistancia() > Data[maior].GetDistancia())
        maior = sucessorEsq;

    if (sucessorDir < Tamanho && Data[sucessorDir].GetDistancia() > Data[maior].GetDistancia())
        maior = sucessorDir;

    if (maior != p) {
        Par aux = Data[p];
        Data[p] = Data[maior];
        Data[maior] = aux;
        HeapifyPorBaixo(maior);
    }
}

// void Inserir: Insere uma Par na heap
// int p: Especifica a posição
void Heap::Inserir(Par P) {
    if (Tamanho == Capacidade) {
        return;
    }

    if (Tamanho == 0) {
        Data[0] = P;
        Tamanho++;
        return;
    }

    Data[Tamanho] = P;
    HeapifyPorCima(Tamanho);
    Tamanho++;
}

// bool Vazio: Retorna a informação sobre a heap estar vazia
bool Heap::Vazio() {
    return Tamanho == 0;
}

// int Tamanho
int Heap::GetTamanho() {
    return Tamanho;
}

// Par Remover: Remove o topo da heap
Par Heap::Remover() {
    Par max = Data[0];
    Data[0] = Data[Tamanho - 1];
    Tamanho--;
    HeapifyPorBaixo(0);
    return max;
}

// Par GetElemento: Obtém o elemento na posição especificada
// int p: Especifica a posição
Par Heap::GetElemento(int p) {
    return Data[p];
}

// Par Topo: Retorna o topo da heap
Par Heap::Topo() {
    return Data[0];
}

// void Inverter: Inverte a Heap para um min-heap e ordena ela crescentemente
void Heap::Inverter() {
    int originalTamanho = Tamanho;

    while (Tamanho > 1) {
        Par temp = Data[0];
        Data[0] = Data[Tamanho - 1];
        Data[Tamanho - 1] = temp;

        Tamanho--;
        HeapifyPorBaixo(0);
    }
    Tamanho = originalTamanho;
}