#include "Tripla.h"
#include <iostream>

// Construtor padrão

Tripla::Tripla() {
    Vertice   = 0;
    Distancia = 0;
}

// Construtor com informação
// int   v: Vértice
// bool  p: Portal
// float d: Distância

Tripla::Tripla(int v, bool p, float d) {
    Vertice   = v;
    Portal    = p;
    Distancia = d;
}

// Destrutor

Tripla::~Tripla() {}

// Getters

int Tripla::GetVertice() {
    return this->Vertice;
}

bool Tripla::GetPortal() {
    return this->Portal;
}

float Tripla::GetDistancia() {
    return this->Distancia;
}