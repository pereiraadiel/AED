#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

struct no{
	int elem;
	struct no* prox;
};

Pilha cria_pilha(){
	return NULL;
}	
int pilha_vazia(Pilha p){
	return !p;
}
int empilhar(Pilha *p, int elem){
	Pilha No = (Pilha) malloc(sizeof(struct no));
	if(No){
		No->elem = elem;
		No->prox = *p;
		*p = No;
		return 1;
	}
	return 0;
}
int desempilhar(Pilha *p, int *elem){
	if(pilha_vazia((*p))) return 0;
	Pilha No = *p;
	*elem = No->elem;
	*p = No->prox;
	free(No);
	return 1;
}
int le_topo(Pilha *p, int *elem){
	if(pilha_vazia((*p))) return 0;
	*elem = (*p)->elem;
	return 1;
}

void imprimir(Pilha *p){
	if(pilha_vazia((*p))) {
		printf("Pilha = []\n");
		return;
	}
	printf("Pilha = [");
	Pilha temp = *p;
	while(temp!=NULL){
		printf("%d ",temp->elem);
		temp = temp->prox;
	}
	printf("\b]\n");
}
void imprimir_rev(Pilha *p){
	if(pilha_vazia((*p))) {
		printf("Pilha = []\n");
		return;
	}
	Pilha temp = *p;
	Pilha T = cria_pilha();
	while(temp!=NULL){
		empilhar(&T,temp->elem);
		temp = temp->prox;
	}
	imprimir(&T);
}
int tamanho(Pilha *p){
	if(pilha_vazia((*p))) return 0;
	int i=0;
	Pilha temp = *p;
	while(temp!=NULL){
		i++;
		temp = temp->prox;
	}
	return i;
}
int igualdade(Pilha *a, Pilha *b){
         if(tamanho(a) != tamanho(b)) return 0;
         Pilha aux,auxb;
         aux = *a;
         auxb = *b;
        while(aux!= NULL){
                  if(aux->elem!=auxb->elem) return 0;
                  aux = aux->prox;
                  auxb = auxb->prox;
        }
        return 1;
}
int palindrome(char *str){
	int i=0,j=0;
	Pilha ida = cria_pilha();
	Pilha volta = cria_pilha();

	while(str[i]){
		if(str[i]!=' ')	empilhar(&ida,str[i]);
		i++;
	}
	
	Pilha temp = ida;
	while(temp!=NULL){
		empilhar(&volta,temp->elem);
		temp = temp->prox;
	}

	return igualdade(&ida,&volta);
	
}
