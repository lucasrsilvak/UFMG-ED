#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>

#include "Hash.h"
#include "Estacao.h"
#include "QuadTree.h"

using namespace std;

// void LerEstacoes: Adiciona as estações do arquivo no programa
// ifstream arquivo: Arquivo a ser lido
// QuadTree Q: QuadTree para inserir as estações
// Hash H: Tabela Hash para inserir as estações
// int n: Número de linhas que possui o arquivo
void LerEstacoes(ifstream& arquivo, QuadTree& Q, Hash& H, int n) {
    for (int i = 0; i < n; i++) {
        string linha;
        if (!getline(arquivo, linha)) {
            cerr << "Erro ao ler a linha " << i + 1 << " do arquivo" << endl;
            break;
        }

        istringstream iss(linha);
        string id, sigla, logradouro, bairro, regiao;
        long id_logradouro;
        int numero, cep;
        double coord_x, coord_y;

        getline(iss, id, ';');
        iss >> id_logradouro;
        iss.ignore();
        getline(iss, sigla, ';');
        getline(iss, logradouro, ';');
        iss >> numero;
        iss.ignore();
        getline(iss, bairro, ';');
        getline(iss, regiao, ';');
        iss >> cep;
        iss.ignore();
        iss >> coord_x;
        iss.ignore();
        iss >> coord_y;

        Estacao* estacao = new Estacao(id, id_logradouro, sigla, logradouro, numero, bairro, regiao, cep, coord_x, coord_y);
        
        int EstacaoIndex = Q.Inserir(estacao);
        H.Inserir(id, EstacaoIndex);
    }
}

// void ProcessarComandos: Processa os comandos a serem executados no programa
// ifstream arquivo: Arquivo a ser lido
// QuadTree Q: QuadTree para execução dos comandos
// Hash H: Tabela Hash para execução dos comandos
void ProcessarComandos(ifstream& arquivo, QuadTree& Q, Hash& H) {
    string linha;
    while (getline(arquivo, linha)) {        
        istringstream iss(linha);
        char tipo;
        string id;
        double x, y;
        int z;

        iss >> tipo;
        if (tipo == 'A') {
            iss >> id;
            cout << "A " << id << endl;
            int Index = H.Procurar(id);
            Q.Ativar(Index);
        } else if (tipo == 'D') {
            iss >> id;
            cout << "D " << id << endl;
            int Index = H.Procurar(id);
            Q.Desativar(Index);
        } else if (tipo == 'C') {            
            iss >> x >> y >> z;
            cout << fixed << setprecision(6) << "C " << x << " " << y << " " << z << endl;
            Q.Procurar(x, y, z);
        }
    }
}

int main(int argc, char *argv[]){
    string baseFile  = "geracarga.base";
    string eventFile = "geracarga.ev";

    if (argc >= 5) {
        baseFile = argv[2];
        eventFile = argv[4];
    }

    ifstream arquivo_base(baseFile);
    string numeroEstacoes;
    getline(arquivo_base, numeroEstacoes);
    int n = stoi(numeroEstacoes);

    QuadTree Q(598000, 7785000, 620000, 7813000, n);
    Hash H(n);

    LerEstacoes(arquivo_base, Q, H, n);
    arquivo_base.close();

    ifstream arquivo_comandos(eventFile);
    string numeroComandos;
    getline(arquivo_comandos, numeroComandos);
    int m = stoi(numeroComandos);

    ProcessarComandos(arquivo_comandos, Q, H);
    arquivo_comandos.close();

    return 0;
}