#ifndef LISTA_H
#define LISTA_H

class Lista {
public:
    Lista();
    Lista(const Lista& other);
    Lista& operator=(const Lista& other);
    ~Lista();
    int GetItem(int pos);
    void SetItem(int item, int pos);
    void InsereInicio(int item);
    void InsereFinal(int item);
    void InserePosicao(int item, int pos);
    int RemoveInicio();
    int RemoveFinal();
    int RemovePosicao(int pos);
    int Pesquisa(int c);
    int GetTamanho();
    void Imprime();
    void Limpa();
private:
    class Node {
    public:
        Node() : prox(nullptr) {};
    private:
        int item;
        Node* prox;
        friend class Lista;
    };

    int tamanho;
    Node* primeiro;
    Node* ultimo;
    Node* PosicionaAntes(int pos);
    Node* PosicionaDepois(int pos);
    void CopyFrom(const Lista& other);
};

#endif