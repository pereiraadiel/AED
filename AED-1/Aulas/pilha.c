#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct no{
	int elem;
	struct no* prox;
};

Pilha cria_pilha(){
	return NULL;
}

int pilha_vazia(Pilha p){
	if(p==NULL) return 1;
	return 0;
}

int push(Pilha *p, int elem){
	Pilha temp = (Pilha) malloc(sizeof(struct no));
	if(temp){
		temp->elem = elem;
		temp->prox = *p;
		*p= temp;
		return 1;
	}
	return 0;
}

int pop(Pilha *p, int *elem){
	if(pilha_vazia((*p))) return 0;
	Pilha temp = *p;
	if(temp){
		*elem = temp->elem;
		*p = temp->prox;
		return 1;
	}
	return 0;
}
int ler_topo(Pilha *p,int *elem){
	if(pilha_vazia((*p))) return 0;
	*elem = (*p)->elem;
	return 1;
}
void print(Pilha *p){
	if(pilha_vazia((*p))) {
		printf("pilha: []\n");
		return;
	}
	Pilha temp = (*p);
	printf("pilha: [");
	while(temp!=NULL){
		printf("%d ",temp->elem);
		temp = temp->prox;
	}
	printf("\b]\n");
}
