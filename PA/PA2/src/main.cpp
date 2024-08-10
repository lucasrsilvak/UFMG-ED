#include <iostream>
#include "Heap.h"

using namespace std;

int main() {
    int n, m;
    cin >> n;
    Heap *H = new Heap(n);
    for (int i = 0; i < n; i++) {
        int j;
        cin >> j;
        H->Inserir(j);
    }
    while (!H->Vazio()) {
        cout << H->Remover() << " ";
    }
    cout << endl;
}