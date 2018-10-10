#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

struct grafo{
	int eh_ponderado;
	int numero_vertices;
	int grau_MAX;
	int ** arestas;
	float **pesos;
	int *grau;
};

Grafo * criaGrafo(int numero_vertices, int grau_MAX, int eh_ponderado){
	Grafo *gr = (Grafo*) malloc(sizeof(struct grafo));
	if(gr!=NULL){
		int i;
		gr->numero_vertices = numero_vertices;
		gr->grau_MAX = grau_MAX;
		gr->eh_ponderado = eh_ponderado;
		gr->grau = (int*) calloc(numero_vertices,sizeof(int));
		gr->arestas = (int**) malloc(numero_vertices*sizeof(int*));
		for(i=0;i<numero_vertices;i++) gr->arestas[i] = (int*) malloc(grau_MAX*sizeof(int));
		if(gr->eh_ponderado){
			gr->pesos=(float**) malloc(numero_vertices*sizeof(float*));
			for(i=0;i<numero_vertices;i++) gr->pesos[i] = (float*) malloc(grau_MAX*sizeof(float));
		}
	}
	return gr;
}

void liberaGrafo(Grafo *gr){
	if(gr!=NULL){
		int i;
		for(i=0;i<gr->numero_vertices;i++) free(gr->arestas[i]);
		free(gr->arestas);
		if(gr->eh_ponderado){
			for(i=0;i<gr->numero_vertices;i++) free(gr->pesos[i]);
			free(gr->pesos);
		}
		free(gr->grau);
		free(gr);
	}
}

int insereAresta(Grafo *gr, int origem, int destino,int eh_digrafo,float peso){
	if(gr == NULL) return 0;
	if(origem<0||origem>=gr->numero_vertices||destino<0||destino>=gr->numero_vertices) return 0;
	gr->arestas[origem][gr->grau[origem]]=destino;
	if(gr->eh_ponderado) gr->pesos[origem][gr->grau[origem]] = peso;
	gr->grau[origem]++;
	if(!eh_digrafo) insereAresta(gr,destino,origem,1,peso);
}