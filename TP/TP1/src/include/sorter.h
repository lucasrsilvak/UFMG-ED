#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Sort Utils

void Swap(int* Pos1, int* Pos2) {
    int PosAux = *Pos1;
    *Pos1 = *Pos2;
    *Pos2 = PosAux;
}

// Sorter

// n²

void BubbleSort(int* Vector, int Length) {
    if (Length <= 1) {
        return;
    }
    int i, j;
    int f_swapped = 0;

    for (i = 0; i < Length - 1; i++) {
        for (j = 1; j < Length - i; j++) {
            if (Vector[j] < Vector[j-1]) {
                Swap(&Vector[j], &Vector[j-1]);
                f_swapped++;
            }
        }
        if (!f_swapped) {
            break;
        }
    }
}

void InsertionSort(int* Vector, int Length) {
    if (Length <= 1) {
        return;
    }
    int i, j, k;

    for (i = 1; i < Length; i++) {
        k = Vector[i];
        j = i - 1;
        while ((j >= 0) && k < Vector[j]) {
            Vector[j+1] = Vector[j];
            j--;
        }
        Vector[j+1] = k;
    }
}

void SelectionSort(int* Vector, int Length) {
    if (Length <= 1) {
        return;
    }
    int i, j, Minimo;

    for (i = 0; i < Length - 1; i++) {
        Minimo = i;
        for (j = i + 1; j < Length; j++) {
            if (Vector[j] < Vector[Minimo]) {
                Minimo = j;
            }
        }
        if (Minimo != i) {
            Swap(&Vector[i], &Vector[Minimo]);
        }
    }
}

// nlog(n)

void MergeJoin(int* Vector, int E, int M, int D) {
    int i, j, k;
    int LengthE = M - E + 1;
    int LengthD = D - M;

    int* VE = malloc(LengthE * sizeof(int));
    int* VD = malloc(LengthD * sizeof(int));

    for (i = 0; i < LengthE; i++) {
        VE[i] = Vector[E + i];
    }

    for (j = 0; j < LengthD; j++) {
        VD[j] = Vector[M + 1 + j];
    }

    i = 0;
    j = 0;
    k = E; 

    while (i < LengthE && j < LengthD) {
        if (VE[i] <= VD[j]) {
            Vector[k] = VE[i];
            i++;
        } else {
            Vector[k] = VD[j];
            j++;
        }
        k++;
    }
    
    while (i < LengthE) {
        Vector[k] = VE[i];
        i++;
        k++;
    }

    while (j < LengthD) {
        Vector[k] = VD[j];
        j++;
        k++;
    }
    free(VD);
    free(VE);
}

void MergeSplit(int* Vector, int E, int D) {
    if (E < D) {
        int M = (E + D)/2;
        MergeSplit(Vector, E, M);
        MergeSplit(Vector, M + 1, D);
        MergeJoin(Vector, E, M, D);
    }
}

void MergeSort(int* Vector, int Length) {
    if (Length <= 1) {
        return;
    }
    MergeSplit(Vector, 0, Length-1);
}

void ShellSort(int* Vector, int Length) {
    if (Length <= 1) {
        return;
    }
    int Passo = 3;
    for (int i = Length / Passo; i > 0; i /= Passo) {
        for (int j = i; j < Length; j++) {
            int VT = Vector[j];
            int k;
            for (k = j; k >= i && Vector[k-i] > VT; k -= i) {
                Vector[k] = Vector[k - i];
            }
        Vector[k] = VT;
        }
    }
}

int Mediana(int A, int B, int C) {
    if ((A > B) ^ (A > C))
        return A;
    else if ((B < A) ^ (B < C))
        return B;
    else
        return C;
}

void quickPartition(int* Vector, int E, int D, int* L, int* R) {
    *L = E;
    *R = D;
    int pivotIndex = Mediana(E, D, (E+D)/2);
    int Pivot = Vector[pivotIndex];

    do {
        while (Vector[*L] < Pivot) {
            (*L)++;
        }
        while (Vector[*R] > Pivot) {
            (*R)--;
        }
    
        if (*L <= *R) {
            Swap(&Vector[*L], &Vector[*R]);
            (*L)++;
            (*R)--;
        }
    } while (*L <= *R);
}

void quickSplit(int* Vector, int E, int D) {
    if (E < D) {
        int L = E, R = D;
        quickPartition(Vector, E, D, &L, &R);
        
        if (E < R) {
            quickSplit(Vector, E, R);
        } 
        if (L < D) {
            quickSplit(Vector, L, D);
        }
    }
}

void QuickSort(int* Vector, int Length) {
    quickSplit(Vector, 0, Length - 1);
}

// n

void CountingSort(int* Vector, int Length, int Maximo) {
    if (Length <= 1) {
        return;
    }
    int* Count = calloc(Maximo + 1, sizeof(int));

    for (int i = 0; i < Length; i++) {
        Count[Vector[i]]++;
    }

    int Indice = 0;
    for (int i = 0; i < Maximo; i++) {
        while (Count[i] > 0) {
            Vector[Indice++] = i;
            Count[i]--;
        }
    }
    free(Count);
}

void BucketSort(int* Vector, int Length, int Minimo, int Maximo) {
    if (Length <= 1) {
        return;
    }

    int BucketCount = ceil(sqrt(Length)) + 1000;
    int BucketRange = (Maximo-Minimo)/BucketCount - 10;

    int** Buckets = (int**)malloc(BucketCount * sizeof(int*));
    int* BucketSizes = (int*)calloc(BucketCount, sizeof(int));

    for (int i = 0; i < BucketCount; i++) {
        Buckets[i] = (int*)malloc(Length * sizeof(int));
    }

    for (int i = 0; i < Length; i++) {
        int BucketIndex = (Vector[i] - Minimo) / BucketRange;
        if (BucketIndex >= BucketCount) {
            BucketIndex = BucketCount - 1;
        }
        Buckets[BucketIndex][BucketSizes[BucketIndex]++] = Vector[i];
    }

    int Index = 0;
    for (int i = 0; i < BucketCount; i++) {
        if (BucketSizes[i] > 0) {
            InsertionSort(Buckets[i], BucketSizes[i]);
            for (int j = 0; j < BucketSizes[i]; j++) {
                Vector[Index++] = Buckets[i][j];
            }
        }
        free(Buckets[i]);
    }

    free(Buckets);
    free(BucketSizes);
}

int getDigit(int x, int w) {
    return (x >> w) & 1;
}

void RadixQuickSort(int Vector[], int E, int D, int B) {
    int i = E, j = D;
    if (D <= E || B < 0) { 
        return;
    }

    while (j != i) {
        while (getDigit(Vector[i], B) == 0 && i < j) i++;
        while (getDigit(Vector[j], B) == 1 && j > i) j--;
        if (i < j) {
            Swap(&Vector[i], &Vector[j]);
        }
    }

    if (getDigit(Vector[D], B) == 0) {
        j++;
    }
    
    RadixQuickSort(Vector, E, j - 1, B - 1);
    RadixQuickSort(Vector, j, D, B - 1);
}

void RadixSort(int*Vector, int Length) {
    int Bits = sizeof(int) * 8 - 1;

    RadixQuickSort(Vector, 0, Length - 1, Bits);
}