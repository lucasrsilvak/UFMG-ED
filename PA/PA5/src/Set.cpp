#include "Set.hpp"
#include <iostream>
#include <string>

using namespace std;

StringSet::StringSet(int tamanho) {
    tamanhoOriginal = tamanho;
    tamanhoTabela = tamanho;
    tamanhoConjunto = 0;
    tabela = new ElementoTabela[tamanhoTabela];
    for (int i = 0; i < tamanhoTabela; ++i) {
        tabela[i].vazio = true;
        tabela[i].retirada = false;
    }
}

StringSet::~StringSet() {
    delete[] tabela;
}

int StringSet::Hash(string s) {
    int hash = 0;
    for (char c : s) {
        hash = (hash * 26 + c) % tamanhoTabela;
    }
    return hash;
}

void StringSet::Rehash(int pos) {
    int tamanhoTabelaAntigo = tamanhoTabela;
    ElementoTabela* tabelaAntiga = tabela;
    
    tamanhoTabela *= 2;
    tabela = new ElementoTabela[tamanhoTabela];
    for (int i = 0; i < tamanhoTabela; ++i) {
        tabela[i].vazio = true;
        tabela[i].retirada = false;
    }
    
    tamanhoConjunto = 0;
    
    for (int i = 0; i < tamanhoTabelaAntigo; ++i) {
        if (!tabelaAntiga[i].vazio and !tabelaAntiga[i].retirada) {
            Inserir(tabelaAntiga[i].dado);
        }
    }
    
    delete[] tabelaAntiga;
}

void StringSet::Inserir(string s) {
    if (tamanhoConjunto >= tamanhoTabela / 2) {
        Rehash(tamanhoConjunto);
    }
    
    int pos = Hash(s);
    while (!tabela[pos].vazio and !tabela[pos].dado.empty() and tabela[pos].dado != s) {
        pos = (pos + 1) % tamanhoTabela;
    }
    
    if (tabela[pos].vazio or tabela[pos].retirada) {
        tabela[pos].dado = s;
        tabela[pos].vazio = false;
        tabela[pos].retirada = false;
        tamanhoConjunto++;
    }
}

void StringSet::Remover(string s) {
    int pos = Hash(s);
    while (!tabela[pos].vazio) {
        if (tabela[pos].dado == s and !tabela[pos].retirada) {
            tabela[pos].retirada = true;
            tamanhoConjunto--;
            return;
        }
        pos = (pos + 1) % tamanhoTabela;
    }
}

bool StringSet::Pertence(string s) {
    int pos = Hash(s);
    while (!tabela[pos].vazio) {
        if (tabela[pos].dado == s and !tabela[pos].retirada) {
            return true;
        }
        pos = (pos + 1) % tamanhoTabela;
    }
    return false;
}

StringSet* StringSet::Intersecao(StringSet* S) {
    StringSet* resultado = new StringSet(tamanhoTabela);
    for (int i = 0; i < tamanhoTabela; ++i) {
        if (!tabela[i].vazio and !tabela[i].retirada and S->Pertence(tabela[i].dado)) {
            resultado->Inserir(tabela[i].dado);
        }
    }
    return resultado;
}

StringSet* StringSet::Uniao(StringSet* S) {
    StringSet* resultado = new StringSet(tamanhoTabela + S->tamanhoTabela);
    for (int i = 0; i < tamanhoTabela; ++i) {
        if (!tabela[i].vazio and !tabela[i].retirada) {
            resultado->Inserir(tabela[i].dado);
        }
    }
    for (int i = 0; i < S->tamanhoTabela; ++i) {
        if (!S->tabela[i].vazio and !S->tabela[i].retirada) {
            resultado->Inserir(S->tabela[i].dado);
        }
    }
    return resultado;
}

StringSet* StringSet::DiferencaSimetrica(StringSet* S) {
    StringSet* resultado = new StringSet(tamanhoTabela + S->tamanhoTabela);
    for (int i = 0; i < S->tamanhoTabela; ++i) {
        if (!S->tabela[i].vazio and !S->tabela[i].retirada and !Pertence(S->tabela[i].dado)) {
            resultado->Inserir(S->tabela[i].dado);
        }
    }
    for (int i = 0; i < tamanhoTabela; ++i) {
        if (!tabela[i].vazio and !tabela[i].retirada and !S->Pertence(tabela[i].dado)) {
            resultado->Inserir(tabela[i].dado);
        }
    }
    return resultado;
}

void StringSet::Imprimir() {
    string* elementos = new string[tamanhoTabela];
    int count = 0;
    for (int i = 0; i < tamanhoTabela; ++i) {
        if (!tabela[i].vazio and !tabela[i].retirada) {
            elementos[count++] = tabela[i].dado;
        }
    }

    for (int i = 0; i < count - 1; ++i) {
        for (int j = i + 1; j < count; ++j) {
            if (elementos[i] > elementos[j]) {
                string temp = elementos[i];
                elementos[i] = elementos[j];
                elementos[j] = temp;
            }
        }
    }

    cout << "{ ";
    for (int i = 0; i < count; ++i) {
        cout << elementos[i];
        if (i < count - 1) {
            cout << ", ";
        }
    }
    cout << " }" << endl;

    delete[] elementos;
}
