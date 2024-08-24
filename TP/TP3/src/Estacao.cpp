#include "Estacao.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

// Construtor padrão
Estacao::Estacao() {
    ID = "";
    ID_Logradouro = 0;
    Sigla = "";
    Logradouro = "";
    Numero = 0;
    Bairro = "";
    Regiao = "";
    Cep = 0;
    X = 0.0;
    Y = 0.0;
    Ativa = false;
}

// Construtor com informação
Estacao::Estacao(string id, long id_logradouro, string sigla, string logradouro, int numero, string bairro, string regiao, int cep, double coord_x, double coord_y) {
    ID = id;
    ID_Logradouro = id_logradouro;
    Sigla = sigla;
    Logradouro = logradouro;
    Numero = numero;
    Bairro = bairro;
    Regiao = regiao;
    Cep = cep;
    X   = coord_x;
    Y   = coord_y;
    Ativa = true;
}

// Destrutor
Estacao::~Estacao() {}

// void Ativar: Ativa a estação se estiver desativada e imprime se mudou o estado
void Estacao::Ativar() {
    if (!Ativa) {
        this->Ativa = true;
        cout << "Ponto de recarga " << ID << " ativado." << endl;
    } else {
        cout << "Ponto de recarga " << ID << " já estava ativo." << endl;
    }
}

// void Desativar: Desativa a estação se estiver desativada e imprime se mudou o estado
void Estacao::Desativar() {
    if (Ativa) {
        this->Ativa = false;
        cout << "Ponto de recarga " << ID << " desativado." << endl;
    } else {
        cout << "Ponto de recarga " << ID << " já estava desativado." << endl;
    }
}

// bool IsAtiva: Retorna a informação se a estação está ativa
bool Estacao::IsAtiva() {
    return this->Ativa;
}

// string GetEndereco: Retorna informações sobre o endereço da estação
string Estacao::GetEndereco() {
    return Sigla + " " + Logradouro + ", " + to_string(Numero) + ", " + Bairro + ", " + Regiao + ", " + to_string(Cep);
}

// Getters

string Estacao::GetID() {
    return this->ID;
}

double Estacao::GetX() {
    return this->X;
}

double Estacao::GetY() {
    return this->Y;
}