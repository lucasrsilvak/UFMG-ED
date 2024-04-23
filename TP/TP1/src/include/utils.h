#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Aleatorizar(int *Vector, int Length, float Aleatoriedade) {
    int Aleatorizadas = (int)(Length * (1.0 - Aleatoriedade / 100.0));

    for (int i = 0; i < Aleatorizadas; i++) {
        int j = rand() % Length;
        int k = rand() % Length;
        int temp = Vector[j];
        Vector[j] = Vector[k];
        Vector[k] = temp;
    }
}

int* CreateVectorInt(int Length, float Aleatoriedade, int Crescente) {
    int* Vector = malloc(Length * sizeof(int));
    if (!Vector) return NULL; 

    for (int i = 0; i < Length; i++) {
        Vector[i] = rand() % 1000;
        //Vector[i] = 1000000 + rand() % 9000000;
    }

    int Maximo = getMaximo(Vector, Length);

    int* Count = calloc(Maximo + 1, sizeof(int));

    for (int i = 0; i < Length; i++) {
        Count[Vector[i]]++;
    }

    int Indice = 0;
    if (Crescente) {
        for (int i = 0; i < Maximo; i++) {
            while (Count[i] > 0) {
                Vector[Indice++] = i;
                Count[i]--;
            }
        }
    } else {
        for (int i = Maximo; i > 0; i--) {
            while (Count[i] > 0) {
                Vector[Indice++] = i;
                Count[i]--;
            }
        }
    }
    free(Count);

    Aleatorizar(Vector, Length, Aleatoriedade);

    return Vector;
}

void PrintVectorInt(int *Vector, int Length) {
    printf("\nShowing Vector...\n");

    for (int i = 0; i < Length; i++){
        printf("%d ", Vector[i]);
    }
    printf("\n");
}

void MedirTempo(clock_t Inicio, clock_t Fim) {
    double Tempo = ((double) (Fim - Inicio)) / CLOCKS_PER_SEC;

    printf("%f\n", Tempo);
}

int getMaximo(int *Vector, int Length) {
    int Maximo = Vector[0];
    for (int i = 1; i < Length; i++) {
        if (Vector[i] > Maximo) {
            Maximo = Vector[i];
        }
    }
    return Maximo;
}

int getMinimo(int *Vector, int Length) {
    int Minimo = Vector[0];
    for (int i = 1; i < Length; i++) {
        if (Vector[i] < Minimo) {
            Minimo = Vector[i];
        }
    }
    return Minimo;
}