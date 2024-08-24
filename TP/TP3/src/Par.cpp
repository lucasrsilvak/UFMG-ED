#include "Par.h"
#include <iostream>

// Construtor padrão

Par::Par() {
    Distancia = 0;
}

// Construtor com informação
// Estacao E: Vértice
// double  d: Distância
Par::Par(Estacao E, double d) {
    Ponto     = E;
    Distancia = d;
}

// Destrutor
Par::~Par() {}

// Getters

Estacao Par::GetPonto() {
    return this->Ponto;
}

double Par::GetDistancia() {
    return this->Distancia;
}