#ifndef QUADTREE_H
#define QUADTREE_H

#include "QuadNode.h"
#include "Heap.h"
#include <cmath>
#include <iostream>

#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>

class QuadTree {
    private:
        QuadNode* Nos;
        int Tamanho;

        int InserirInterno(int nodeIndex, Estacao* E);
        void ProcurarInterno(int nodeIndex, double x, double y, int n, Heap& H);
        double CalcularDistanciaMinima(int nodeIndex, double x, double y);

    public:
        QuadTree(double minX, double minY, double maxX, double maxY, int n);
        ~QuadTree();

        int Inserir(Estacao* E);
        void Ativar(int nodeIndex);
        void Desativar(int nodeIndex);
        void Procurar(double x, double y, int n);
    };

#endif // QUADTREE_H