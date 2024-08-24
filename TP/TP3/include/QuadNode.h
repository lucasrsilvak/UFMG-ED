#ifndef QUADNODE_H
#define QUADNODE_H

#include "Estacao.h"

class QuadNode {
    public:
        double minX, minY, maxX, maxY;
        Estacao* estacao;
        int SW, NW, SE, NE;

        QuadNode() : minX(0), minY(0), maxX(0), maxY(0), estacao(nullptr), SW(-1), NW(-1), SE(-1), NE(-1) {}
        QuadNode(double minX, double minY, double maxX, double maxY) : minX(minX), minY(minY), maxX(maxX), maxY(maxY), estacao(nullptr), SW(-1), NW(-1), SE(-1), NE(-1) {}
        QuadNode(double minX, double minY, double maxX, double maxY, Estacao* e) : minX(minX), minY(minY), maxX(maxX), maxY(maxY), estacao(e), SW(-1), NW(-1), SE(-1), NE(-1) {}
        bool TemFilhos() const {
            return SW != -1 || NW != -1 || SE != -1 || NE != -1;
        }
};

#endif // QUADNODE_H
