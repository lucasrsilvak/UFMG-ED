#include "QuadTree.h"
#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>

using namespace std;

// Métodos auxiliares

// double Maximo: Retorna o valor máximo entre a e b
double Maximo(double a, double b) {
    return (a > b) ? a : b;
}

// double Minimo: Retorna o valor mínimo entre a e b
double Minimo(double a, double b) {
    return (a < b) ? a : b;
}

// Construtor
// double minX, maxX, minY, maxY: Limites do retângulo da QuadTree
// int n: Tamanho pré-definido da QuadTree
QuadTree::QuadTree(double minX, double minY, double maxX, double maxY, int n) {
    Nos = new QuadNode[n];
    Nos[0] = QuadNode(minX, minY, maxX, maxY);
    Tamanho = 0;
}

// Destrutor
QuadTree::~QuadTree() {
    for (int i = 0; i <= Tamanho; i++) {
        if (Nos[i].estacao != nullptr) {
            delete Nos[i].estacao;
        }
    }
    delete[] Nos;
}

// void Ativar: Ativa a estação
// int n: Index do nó a ser ativado
void QuadTree::Ativar(int n) {
    return Nos[n].estacao->Ativar();
}

// void Desativar: Desativa a estação
// int n: Index do nó a ser desativado
void QuadTree::Desativar(int n) {
    return Nos[n].estacao->Desativar();
}

// int InserirInterno: Método recursivo da inserção interna na árvore
// int n: Index a ser visitado para possível inserção
// Estacao E: Estação a ser inserida
int QuadTree::InserirInterno(int n, Estacao* E) {
    if (E->GetX() < Nos[n].minX || E->GetX() > Nos[n].maxX || E->GetY() < Nos[n].minY || E->GetY() > Nos[n].maxY) {
        cout << E->GetX() << endl;
        cout << E->GetY() << endl;
        cout << "Estação fora dos limites do nó." << endl;
        return -1;
    }

    if (Nos[n].estacao == nullptr) {
        Nos[n].estacao = E;
        return Tamanho;
    }

    double pontoX = Nos[n].estacao->GetX();
    double pontoY = Nos[n].estacao->GetY();

    if (E->GetX() < pontoX) {
        if (E->GetY() < pontoY) {
            if (Nos[n].SW == -1) {
                Tamanho++;
                Nos[n].SW = Tamanho;
                Nos[Tamanho] = QuadNode(Nos[n].minX, Nos[n].minY, pontoX, pontoY, E);
                return Tamanho;
            } else {
                return InserirInterno(Nos[n].SW, E);
            }
        } else {
            if (Nos[n].NW == -1) {
                Tamanho++;
                Nos[n].NW = Tamanho;
                Nos[Tamanho] = QuadNode(Nos[n].minX, pontoY, pontoX, Nos[n].maxY, E);
                return Tamanho;
            } else {
                return InserirInterno(Nos[n].NW, E);
            }
        }
    } else {
        if (E->GetY() < pontoY) {
            if (Nos[n].SE == -1) {
                Tamanho++;
                Nos[n].SE = Tamanho;
                Nos[Tamanho] = QuadNode(pontoX, Nos[n].minY, Nos[n].maxX, pontoY, E);
                return Tamanho;
            } else {
                return InserirInterno(Nos[n].SE, E);
            }
        } else {
            if (Nos[n].NE == -1) {
                Tamanho++;
                Nos[n].NE = Tamanho;
                Nos[Tamanho] = QuadNode(pontoX, pontoY, Nos[n].maxX, Nos[n].maxY, E);
                return Tamanho;
            } else {
                return InserirInterno(Nos[n].NE, E);
            }
        }
    }
}

// int Inserir: Insere a estação na QuadTree e retorna a posição dela no vetor
// Estacao E: Estação a ser inserida
int QuadTree::Inserir(Estacao* E) {
    return InserirInterno(0, E);
}

// double CalcularDistanciaMinima: Avalia o quadrante e retorna a distância entre o quadrante e o ponto de busca
// int n: Index do quadrante a ser avaliado
// double x: Coordenada x a ser avaliada
// double y: Coordenada y a ser avaliada
double QuadTree::CalcularDistanciaMinima(int n, double x, double y) {
    QuadNode& node = Nos[n];
    double nearestX = Maximo(node.minX, Minimo(x, node.maxX));
    double nearestY = Maximo(node.minY, Minimo(y, node.maxY));
    return sqrt(pow(x - nearestX, 2) + pow(y - nearestY, 2));
}

// void ProcurarInterno: Método recursivo da procura interna na árvore
// int n: Index a ser visitado para procura
// double x: Coordenada x para procurar mais próximos
// double y: Coordenada y para procurar mais próximos
// int k: Número de elementos a serem procurados
// Heap H: Heap a ser utilizada para inserção dos elementos
void QuadTree::ProcurarInterno(int n, double x, double y, int k, Heap& H) {
    if (n == -1) return;
    QuadNode& node = Nos[n];

    // Heurística de Poda
    double maxDist = numeric_limits<double>::infinity();
    double minDist = CalcularDistanciaMinima(n, x, y);
    if (H.GetTamanho() == k) {
        maxDist = H.Topo().GetDistancia();
    }

    if (minDist > maxDist) {
        return;
    }

    // Inserção na Heap
    if (node.estacao != nullptr && node.estacao->IsAtiva()) {
        double distEstacao = sqrt(pow(x - node.estacao->GetX(), 2) + pow(y - node.estacao->GetY(), 2));
        if (H.GetTamanho() < k) {
            H.Inserir(Par(*node.estacao, distEstacao));
        } else if (distEstacao < maxDist) {
            H.Remover();
            H.Inserir(Par(*node.estacao, distEstacao));
        }
    }
    
    // Recursão
    ProcurarInterno(node.SW, x, y, k, H);
    ProcurarInterno(node.NW, x, y, k, H);
    ProcurarInterno(node.SE, x, y, k, H);
    ProcurarInterno(node.NE, x, y, k, H);
}

// void Procurar: Implementa o algoritmo de KNN que encontra as k estações mais próximas
// double x: Coordenada x para procurar mais próximos
// double y: Coordenada y para procurar mais próximos
// int k: Número de estações a serem procurados
void QuadTree::Procurar(double x, double y, int k) {
    Heap H(k);
    ProcurarInterno(0, x, y, k, H);

    H.Inverter();
    for(int i = 0; i < H.GetTamanho(); i++) {
        if (H.GetElemento(i).GetPonto().GetID() != "") {
            cout << fixed << setprecision(3) << H.GetElemento(i).GetPonto().GetEndereco() << " (" << H.GetElemento(i).GetDistancia() << ")" << endl;
        }
    }
}