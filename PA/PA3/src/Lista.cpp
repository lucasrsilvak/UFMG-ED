#include "Lista.h"
#include <iostream>

Lista::Lista() {
    primeiro = new Node();
    ultimo = primeiro;
    tamanho = 0;
}

Lista::Lista(const Lista& other) {
    primeiro = new Node();
    ultimo = primeiro;
    tamanho = 0;
    CopyFrom(other);
}

Lista& Lista::operator=(const Lista& other) {
    if (this != &other) {
        Limpa();
        CopyFrom(other);
    }
    return *this;
}

Lista::~Lista() {
    Limpa();
    delete primeiro;
}

void Lista::CopyFrom(const Lista& other) {
    Node* current = other.primeiro->prox;
    while (current != nullptr) {
        InsereFinal(current->item);
        current = current->prox;
    }
}

Lista::Node* Lista::PosicionaAntes(int pos) {
    Node *p = primeiro;
    for(int i = 0; i < pos; i++){
        if (p->prox == nullptr)
            throw "ERRO: Posicao Invalida!";
        p = p->prox;
    }
    return p;
}

Lista::Node* Lista::PosicionaDepois(int pos) {
    Node *p = primeiro;
    for(int i = 1; i < pos; i++){
        if (p->prox == nullptr)
            throw "ERRO: Posicao Invalida!";
        p = p->prox;
    }
    return p;
}

int Lista::GetItem(int pos){
    Node *p = PosicionaAntes(pos);
    return p->prox->item;
}

void Lista::SetItem(int item, int pos) {
    Node *p = PosicionaAntes(pos);
    p->prox->item = item;
}

void Lista::InsereInicio(int item) {
    Node *nova = new Node();
    nova->item = item;
    nova->prox = primeiro->prox;
    primeiro->prox = nova;
    tamanho++;
    if(nova->prox == nullptr)
        ultimo = nova;
}

void Lista::InsereFinal(int item) {
    Node *nova = new Node();
    nova->item = item;
    ultimo->prox = nova;
    ultimo = nova;
    tamanho++;
}

void Lista::InserePosicao(int item, int pos) {
    Node *p = PosicionaAntes(pos); 
    Node *nova = new Node();
    nova->item = item;
    nova->prox = p->prox;
    p->prox = nova;
    tamanho++;
    if(nova->prox == nullptr)
        ultimo = nova;
}

int Lista::RemoveInicio() {
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";
    Node *p = primeiro->prox;
    primeiro->prox = p->prox;
    tamanho--;
    if(primeiro->prox == nullptr)
        ultimo = primeiro;
    int aux = p->item;
    delete p;
    return aux;
}

int Lista::RemoveFinal() {
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";
    Node *p = PosicionaAntes(tamanho-1);
    int aux = ultimo->item;
    delete ultimo;
    ultimo = p;
    ultimo->prox = nullptr;
    tamanho--;
    return aux;
}

int Lista::RemovePosicao(int pos) {
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";
    Node *p = PosicionaAntes(pos);
    Node *q = p->prox;
    p->prox = q->prox;
    tamanho--;
    int aux = q->item;
    delete q;
    if(p->prox == nullptr)
        ultimo = p;
    return aux;
}

int Lista::Pesquisa(int c) {
    Node *p = primeiro->prox;
    while (p != nullptr) {
        if (p->item == c) {
            return c;
        }
        p = p->prox;
    }
    return -1;
}

void Lista::Imprime() {
    Node *p = primeiro->prox;
    while (p != nullptr) {
        std::cout << p->item << " ";
        p = p->prox;
    }
    std::cout << std::endl;
}

void Lista::Limpa() {
    Node *p = primeiro->prox;
    while (p != nullptr) {
        primeiro->prox = p->prox;
        delete p;
        p = primeiro->prox;
    }
    ultimo = primeiro;
    tamanho = 0;
}

int Lista::GetTamanho() {
    return tamanho;
}
