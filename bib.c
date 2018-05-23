#include <stdio.h>
#include <stdlib.h>
#include "bib.h"

void criaGrafo(Grafo *grafo, int nNos){
    
    grafo->matriz = calloc(nNos, (sizeof(int*)));

    for (int i=0; i < nNos; i++)
        grafo->matriz[i] = calloc (nNos, sizeof(int));
        
    grafo->nNos = nNos;
}

void addAresta(Grafo *grafo, int p1, int p2, float peso){
    grafo->matriz[p1][p2] = peso;
    grafo->matriz[p2][p1] = peso;
}

float calculaPesoLinha(Grafo *grafo, int i, int nNos){
    int somaPeso = 0;
    
    for(int j=0;j<nNos;j++)
        somaPeso = somaPeso + grafo->matriz[i][j];

    return somaPeso;
}

float calculaPesoColuna(Grafo *grafo, int j, int nNos){
    int somaPeso = 0;
    
    for(int i=0;i<nNos;i++)
        somaPeso = somaPeso + grafo->matriz[i][j];

    return somaPeso;
}