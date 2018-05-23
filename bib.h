#include <stdio.h>
#include <stdlib.h>

typedef struct grafo{
    int nNos;
    int **matriz;
} Grafo;

void criaGrafo(Grafo *grafo, int nNos);
void addAresta(Grafo *grafo, int p1, int p2, float peso);
float calculaPesoLinha(Grafo *grafo, int i, int nNos);
float calculaPesoColuna(Grafo *grafo, int j, int nNos);