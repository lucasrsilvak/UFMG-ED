#include "ListaAdjacencia.h"

ListaAdjacencia::ListaAdjacencia() {
    primeiro = new NodeAdjacencia();
    ultimo = primeiro;
    tamanho = 0;
}

ListaAdjacencia::~ListaAdjacencia() {
    Limpa();
    delete primeiro;
}

ListaAdjacencia::NodeAdjacencia* ListaAdjacencia::PosicionaAntes(int pos) {
    NodeAdjacencia *p = primeiro;
    for (int i = 0; i < pos; i++) {
        if (p->prox == nullptr)
            throw "ERRO: Posicao Invalida!";
        p = p->prox;
    }
    return p;
}

ListaAdjacencia::NodeAdjacencia* ListaAdjacencia::PosicionaDepois(int pos) {
    NodeAdjacencia *p = primeiro;
    for (int i = 0; i < pos; i++) {
        if (p->prox == nullptr)
            throw "ERRO: Posicao Invalida!";
        p = p->prox;
    }
    return p;
}

Lista ListaAdjacencia::GetItem(int pos) {
    NodeAdjacencia *p = PosicionaAntes(pos);
    return p->prox->item;
}

void ListaAdjacencia::SetItem(Lista item, int pos) {
    NodeAdjacencia *p = PosicionaAntes(pos);
    p->prox->item = item;
}

void ListaAdjacencia::InsereInicio(Lista item) {
    NodeAdjacencia *nova = new NodeAdjacencia();
    nova->item = item;
    nova->prox = primeiro->prox;
    primeiro->prox = nova;
    tamanho++;
    if(nova->prox == nullptr)
        ultimo = nova;
}

void ListaAdjacencia::InsereFinal(Lista item) {
    NodeAdjacencia* nova = new NodeAdjacencia();
    nova->item = item;
    nova->prox = nullptr;
    if (ultimo != nullptr) {
        ultimo->prox = nova;
    } else {
        primeiro = nova;
    }
    ultimo = nova;
    tamanho++;
}

void ListaAdjacencia::InserePosicao(Lista item, int pos) {
    NodeAdjacencia *p = PosicionaAntes(pos);
    NodeAdjacencia *nova = new NodeAdjacencia();
    nova->item = item;
    nova->prox = p->prox;
    p->prox = nova;
    tamanho++;
    if(nova->prox == nullptr)
        ultimo = nova;
}

Lista ListaAdjacencia::RemoveInicio() {
    if (tamanho == 0)
        throw "ERRO: ListaAdjacencia vazia!";
    NodeAdjacencia *p = primeiro->prox;
    primeiro->prox = p->prox;
    tamanho--;
    if (primeiro->prox == nullptr)
        ultimo = primeiro;
    Lista aux = p->item;
    delete p;
    return aux;
}

Lista ListaAdjacencia::RemoveFinal() {
    if (tamanho == 0)
        throw "ERRO: ListaAdjacencia vazia!";
    NodeAdjacencia *p = PosicionaAntes(tamanho-1);
    Lista aux = ultimo->item;
    delete ultimo;
    ultimo = p;
    ultimo->prox = nullptr;
    tamanho--;
    return aux;
}

Lista ListaAdjacencia::RemovePosicao(int pos) {
    if (tamanho == 0)
        throw "ERRO: ListaAdjacencia vazia!";
    NodeAdjacencia *p = PosicionaAntes(pos);
    NodeAdjacencia *q = p->prox;
    p->prox = q->prox;
    tamanho--;
    Lista aux = q->item;
    delete q;
    if (p->prox == nullptr)
        ultimo = p;
    return aux;
}

void ListaAdjacencia::Limpa() {
    NodeAdjacencia *p = primeiro->prox;
    while (p != nullptr) {
        primeiro->prox = p->prox;
        delete p;
        p = primeiro->prox;
    }
    ultimo = primeiro;
    tamanho = 0;
}

int ListaAdjacencia::GetTamanho() {
    return tamanho;
}
