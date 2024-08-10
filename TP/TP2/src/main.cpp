#include <iostream>
#include <stdexcept>

#include "Ponto.h"
#include "GrafoL.h"
#include "GrafoM.h"

using namespace std;

int main() {
    try {
        float s;
        int n, m, k, q;

        cin >> n >> m >> k;

        Ponto* Pontos = new Ponto[n];
        GrafoM* Floresta = new GrafoM(n);

        for (int i = 0; i < n; i++) {
            float x, y;
            cin >> x >> y;
            Floresta->SetPonto(i, Ponto(x, y));
        }

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            Floresta->SetAdjacente(u, v);
        }

        for (int i = 0; i < k; i++) {
            int u, v;
            cin >> u >> v;
            Floresta->SetPortal(u, v);
        }
        cin >> s >> q;


        float Distancia = Floresta->CalculaDistancia(q);
        if (s >= Distancia) {
            cout << "1 ";
        } else {
            cout << "0 ";
        }

        Distancia = Floresta->AcharCaminho(q);
        if (s >= Distancia) {
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
        }

        delete[] Pontos;
        delete Floresta;
        
    } catch (const char* msg) {
        cout << "Erro: " << msg << endl;
    }
}