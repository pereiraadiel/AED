#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

struct grafo{
    int **matriz;
    int      TAM;
};

Grafo * criar_grafo(int TAM){
    Grafo * grafo = (Grafo*) malloc(sizeof(Grafo));
    if(grafo){
        grafo->TAM = TAM;
        int i,j;
        grafo->matriz = (int **) malloc(sizeof(int *) * grafo->TAM);
        for(i=0;i<grafo->TAM;i++)
            grafo->matriz[i] = (int *) malloc(sizeof(int) * grafo->TAM);
        for(i=0;i<grafo->TAM;i++){
            for(j=0;j<grafo->TAM;j++)
                grafo->matriz[i][j] = 0;
        }
    }
    return grafo;
}

void liberar_grafo(Grafo *grafo){
    if(grafo==NULL) return;

    int i;
    for(i=0;i<grafo->TAM;i++)
        free(grafo->matriz[i]);
    free(grafo->matriz);
    free(grafo);
}

int inserir_aresta(Grafo *grafo, int origem , int destino, int eh_digrafo){
    if(grafo==NULL) return FALSE;
    if(origem<0 || origem >= grafo->TAM) return FALSE;
    if(destino<0 || destino >= grafo->TAM) return FALSE;
    grafo->matriz[origem][destino] ++;
    if(!eh_digrafo) inserir_aresta(grafo,destino,origem,1);
    return TRUE;
}
int remover_aresta(Grafo *grafo, int origem, int destino, int eh_digrafo){
    if(grafo==NULL) return FALSE; // grafo nao alocado
    if(origem<0 || origem >= grafo->TAM) return FALSE; // origem invalida
    if(destino<0 || destino >= grafo->TAM) return FALSE; // destino invalido
    if(grafo->matriz[origem][destino]==0) return FALSE; // nao ha nada 
    grafo->matriz[origem][destino] --; 
    if(!eh_digrafo) remover_aresta(grafo, destino, origem, 1);
    return TRUE; // remocao efetuada
}
