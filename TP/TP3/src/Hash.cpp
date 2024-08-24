#include "Hash.h"

#include <string>

using namespace std;

// Construtor
// int n: Tamanho pré-definido da Hash
Hash::Hash(int n) {
    tamanho =(1.5 * n);
    tabela = new HashEntry[tamanho];
    for (int i = 0; i < tamanho; i++) {
        tabela[i].temElemento = false;
        tabela[i].foiDeletada = false;
    }
}

// Destrutor
Hash::~Hash() {
    delete[] tabela;
}

// int Chaveamento: Aplica a função Hash que indexa a tabela Hash
// string key: Envia o ID do endereço a ser Hasheado
int Hash::Chaveamento(const string& key) {
    int hash = 0;
    for (char ch : key) {
        hash = (hash * 36 + ch) % tamanho;
    }
    return hash;
}

// bool Inserir: Insere o ID e o Index na struct da tabela Hash
// string id: ID do endereço a ser inserido
// int index: Index da estação na QuadTree
bool Hash::Inserir(const string& id, int index) {
    int hashIndex = Chaveamento(id);
    int originalIndex = hashIndex;

    while (tabela[hashIndex].temElemento && !tabela[hashIndex].foiDeletada) {
        if (tabela[hashIndex].id == id) {
            return false;
        }
        hashIndex = (hashIndex + 1) % tamanho;
        if (hashIndex == originalIndex) {
            return false;
        }
    }

    tabela[hashIndex].id = id;
    tabela[hashIndex].index = index;
    tabela[hashIndex].temElemento = true;
    tabela[hashIndex].foiDeletada = false;
    return true;
}

// int Procurar: Procura o Index do ID inserido na tabela Hash
// string id: ID do endereço a ser procurado
int Hash::Procurar(const string& id) {
    int hashIndex = Chaveamento(id);
    int originalIndex = hashIndex;

    while (tabela[hashIndex].temElemento) {
        if (tabela[hashIndex].id == id && !tabela[hashIndex].foiDeletada) {
            return tabela[hashIndex].index;
        }
        hashIndex = (hashIndex + 1) % tamanho;
        if (hashIndex == originalIndex) {
            return -1;
        }
    }
    return -1;
}