#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>

#include "include/sorter.h"
#include "include/utils.h"


int main(int argc, char *argv[]) {
    srand(time(NULL));

    float Ordenacao = 100;
    int Crescente = 1;

    if (argc < 3) {
        printf("Usage: %s <algorithm> <length>\n", argv[0]);
        return 1;
    }

    const char* algorithm = argv[1];
    int Length = atoi(argv[2]);

    if (Length <= 0) {
        printf("Invalid array length.\n");
        return 1;
    }

    int* Vector = CreateVectorInt(Length, Ordenacao, Crescente);
    if (Vector == NULL) {
        printf("Failed to allocate memory for vector.\n");
        return 1;
    }

    int Maximo = getMaximo(Vector, Length);
    int Minimo = getMinimo(Vector, Length);

    clock_t Inicio, Fim;
    Inicio = clock();

    if (strcmp(algorithm, "bubble") == 0) {
        BubbleSort(Vector, Length);
    } else if (strcmp(algorithm, "insertion") == 0) {
        InsertionSort(Vector, Length);
    } else if (strcmp(algorithm, "selection") == 0) {
        SelectionSort(Vector, Length);
    } else if (strcmp(algorithm, "merge") == 0) {
        MergeSort(Vector, Length);
    } else if (strcmp(algorithm, "quick") == 0) {
        QuickSort(Vector, Length);
    } else if (strcmp(algorithm, "shell") == 0) {
        ShellSort(Vector, Length);
    } else if (strcmp(algorithm, "counting") == 0) {
        CountingSort(Vector, Length, Maximo);
    } else if (strcmp(algorithm, "bucket") == 0) {
        BucketSort(Vector, Length, Maximo, Minimo);
    } else if (strcmp(algorithm, "radix") == 0) {
        RadixSort(Vector, Length);
    } else {
        printf("Invalid sorting algorithm specified.\n");
        free(Vector);
        return 1;
    }

    Fim = clock();
    printf("%d ", Length);
    MedirTempo(Inicio, Fim);
    free(Vector);
    return 0;
}