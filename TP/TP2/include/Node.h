#ifndef NODE_H
#define NODE_H

#include "Tripla.h"

class Node {
private:
    Tripla data;
    Node*  next;

public:
    Node() : next(nullptr) {}
    Node(Tripla p) : data(p), next(nullptr) {}
    ~Node() {}

    Tripla GetData() const { return data; }
    Node* GetNext() const { return next; }

    void SetNext(Node* node) { next = node; }

    friend class Lista;
};

#endif
