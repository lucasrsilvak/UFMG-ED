#include "Lista.h"

// Construtor

Lista::Lista() {
    tamanho  = 0;
    primeiro = new Node();
    ultimo   = primeiro;
}

// Destrutor

Lista::~Lista() {
    Node* atual   = primeiro;
    Node* proximo = nullptr;

    while (atual != nullptr) {
        proximo = atual->GetNext();
        delete atual;
        atual = proximo;
    }

    primeiro = nullptr;
    ultimo   = nullptr;
    tamanho  = 0;
}

// int GetTamanho: Retorna o número de elementos contidos na lista

int Lista::GetTamanho() {
    return tamanho;
}

// Node* GetPrimeiro: Retorna o primeiro nó da lista

Node* Lista::GetPrimeiro() {
    return primeiro;
}

// void InsereFinal: Insere uma tripla no nó final da lista
// Tripla t: A tripla a ser inserida

void Lista::InsereFinal(Tripla t) {
    Node* nova = new Node(t);
    ultimo->SetNext(nova);
    ultimo = nova;
    tamanho++;
}
