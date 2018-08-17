#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

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
	if(pilha_vazia((*p))) return 0;
	Pilha No=(*p);
	*elem=No->elem;
	return 1;
}
void imprimir(Pilha *p){
    if(pilha_vazia((*p))) {
        printf("[PILHA VAZIA]\n");
        return;
    }
    printf("Pilha: [");
    Pilha temp = (*p);
    while(temp!=NULL) {
        printf("%d ",temp->elem);
        temp = temp->prox;
    }
    printf("\b]\n");
}
int pares_impares(Pilha *base, Pilha *par, Pilha *impar){
    if(pilha_vazia((*base))) return 0;
    Pilha P=cria_pilha();
    Pilha I=cria_pilha();
    Pilha aux = *base;
    while(aux!=NULL){
        if(aux->elem%2==0) empilha(&P,aux->elem);
        else empilha(&I,aux->elem);
        aux=aux->prox;
    }
    *par = P;
    *impar = I;
    return 1;
}
void aguarde(){
    printf("Aperte ENTER para continuar...");
    char c=65;
    setbuf(stdin,NULL);
    while(c!=10) c=getchar();
}
