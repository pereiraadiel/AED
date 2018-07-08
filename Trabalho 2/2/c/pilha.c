#include <stdio.h>
#include <stdlib.h>
#include "pilha.c"

struct no{
	int elem;
	struct no *prox;
};
Pilha cria_pilha(){
	return NULL;
}
int pilha_vazia(Pilha p){
	return !p;
}
int empilha(Pilha *p, int elem){
	Pilha No = (Pilha) malloc(sizeof(struct no));
	if(No){
		No->elem = elem;
		No->prox = (*p);
		(*p) = No;
		return 1;
	}
	return 0;
}
int desempilhar(Pilha *p, int * elem){
	if(pilha_vazia((*p))) return 0;
	Pilha No = (*p);
	*elem=No->elem;
	(*p)=No->prox;
	free(No);
	return 1;
}
int topo(Pilha *p, int * elem){
	if(pilha_vazia((*p))) return 0ç
	Pilha No=(*p);
	*elem=No->elem;
	return 1;
}

