#include <iostream>
#include "Grafo.h"

using namespace std;

void ProcessarComando(Grafo& G, const string& C) {
    if (C == "-d") {
        cout << G.QuantidadeVertices() << endl;
        cout << G.QuantidadeArestas() << endl;
        cout << G.GrauMinimo() << endl;
        cout << G.GrauMaximo() << endl;
    } else if (C == "-n") {
        for (int i = 0; i < G.QuantidadeVertices(); i++) {
            G.ImprimeVizinhos(i);
        }
    } else if (C == "-k") {
        cout << ((G.QuantidadeVertices()-1) == G.GrauMinimo()) << endl;
    }
}

int main(int argc, char* argv[]) {
    try {
        if (argc < 2) {
            throw "Erro";
        }

        string comando = argv[1];

        int n;
        cin >> n;

        Grafo *G = new Grafo();
        for (int i = 0; i < n; i++) {
            int m;
            cin >> m;
            G->InsereVertice();
            for (int j = 0; j < m; j++) { 
                int k;
                cin >> k;
                G->InsereAresta(i, k);
            }
        }

        ProcessarComando(*G, comando);
    } catch (const char* msg) {
        cout << "Erro: " << msg << endl;
    }
}