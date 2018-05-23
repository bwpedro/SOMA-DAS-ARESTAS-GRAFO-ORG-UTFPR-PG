#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include "bib.h"

int main(){
    
    int nNos;
    float pesoLinha = 0, pesoColuna = 0, peso = 0;
    printf("Informe o número de nós: ");
    scanf("%d",&nNos);

    srand(time(NULL));

    Grafo grafo;
    criaGrafo(&grafo, nNos);
    
    for(int i=0;i<nNos;i++){
        for(int j=i;j<nNos;j++){
            peso = rand()%9;
            addAresta(&grafo,i,j,peso);
        }
    }

    // inicio linha
    double ti = 0, 
           tf = 0, 
           tempo = 0;

    struct timeval tempo_inicio, tempo_fim;
    gettimeofday(&tempo_inicio, NULL);

    for(int i=0;i<nNos;i++)
        pesoLinha = pesoLinha + calculaPesoLinha(&grafo, i, nNos);

    gettimeofday(&tempo_fim, NULL);
    tf = (double)tempo_fim.tv_usec + ((double)tempo_fim.tv_sec * (1000000.0));
    ti = (double)tempo_inicio.tv_usec + ((double)tempo_inicio.tv_sec * (1000000.0));

    tempo = (tf - ti) / 1000;
    printf("Tempo gasto para linha em milisegundos %.3f\n", tempo);
    // fim linha

    // inicio coluna
    ti = 0, 
    tf = 0, 
    tempo = 0;

    gettimeofday(&tempo_inicio, NULL);

    for(int j=0;j<nNos;j++)
        pesoColuna = pesoColuna + calculaPesoColuna(&grafo, j, nNos);

    gettimeofday(&tempo_fim, NULL);
    tf = (double)tempo_fim.tv_usec + ((double)tempo_fim.tv_sec * (1000000.0));
    ti = (double)tempo_inicio.tv_usec + ((double)tempo_inicio.tv_sec * (1000000.0));

    tempo = (tf - ti) / 1000;
    printf("Tempo gasto para coluna em milisegundos %.3f\n", tempo);
    // fim coluna

    return 0;
}