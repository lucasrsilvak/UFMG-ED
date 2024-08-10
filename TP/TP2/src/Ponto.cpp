#include "Ponto.h"
#include <iostream>
#include <math.h>

// Construtor padrão

Ponto::Ponto() {}

// Construtor com coordenadas
// float x: Recebe a coordenada x do ponto num plano 2D
// float y: Recebe a coordenada y do ponto num plano 2D

Ponto::Ponto(float x, float y) {
    this->x = x;
    this->y = y;
}

// Destrutor

Ponto::~Ponto() {}

// float Distancia: Calcula a distância entre o ponto atual e o fornecido
// Ponto p: Fornece o outro ponto

float Ponto::Distancia(Ponto p) {
    return sqrt((pow(this->x - p.GetX(), 2) + pow(this->y - p.GetY(), 2)));
}

// Getters e Setters 

void Ponto::SetX(float x) {
    this->x = x;
}

void Ponto::SetY(float y) {
    this->y = y;
}

float Ponto::GetX() {
    return this->x;
}

float Ponto::GetY() {
    return this->y;
}