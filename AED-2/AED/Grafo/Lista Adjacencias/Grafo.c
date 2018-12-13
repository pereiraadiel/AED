#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Grafo.h"

struct grafo{
    int eh_ponderado;
    int num_vertices;
    int  grau_maximo;
    int    **arestas;
    float    **pesos;
    int        *grau;
};

Grafo * criar_grafo(int num_vertices, int grau_maximo, int eh_ponderado){
    Grafo * grafo = (Grafo *) malloc(sizeof(Grafo));
    if(grafo){
        int i;
        grafo->num_vertices = num_vertices;
        grafo->grau_maximo = grau_maximo;
        grafo->eh_ponderado = eh_ponderado==0?0:1;
        grafo->grau = (int *) calloc(grafo->num_vertices,sizeof(int));
        grafo->arestas = (int**) malloc(sizeof(int*)*grafo->num_vertices);
        for(int i=0; i<grafo->grau_maximo; i++)
            grafo->arestas[i] = (int *) malloc(sizeof(int) * grafo->grau_maximo);
        
        if(grafo->eh_ponderado){
            grafo->pesos = (float **) malloc(sizeof(float**)*grafo->num_vertices);
            for(i=0;i<grafo->grau_maximo;i++)
                grafo->pesos[i] = (float*) malloc(sizeof(float*) * grafo->grau_maximo);
        }
    }
    return grafo;
}

void liberar_grafo(Grafo *grafo){
    if(grafo==NULL) return;
    int i;
    for(i=0;i<grafo->grau_maximo;i++)
        free(grafo->arestas[i]);
    free(grafo->arestas);

    if(grafo->eh_ponderado){
        for(i=0;i<grafo->grau_maximo;i++)
            free(grafo->pesos[i]);
        free(grafo->pesos);
    }

    free(grafo->grau);
    free(grafo);
}

int inserir_aresta(Grafo *grafo, int origem, int destino, int eh_digrafo, float peso){
    if(grafo==NULL) return FALSE;
    if(origem<0 || origem >= grafo->num_vertices) return FALSE;
    if(destino<0 || destino >= grafo->num_vertices) return FALSE;
    grafo->arestas[origem][grafo->grau[origem]] = destino;
    if(grafo->eh_ponderado) grafo->pesos[origem][grafo->grau[origem]] = peso;
    grafo->grau[origem] ++;
    if(!eh_digrafo) inserir_aresta(grafo,destino,origem,1,peso);
    return TRUE;
}