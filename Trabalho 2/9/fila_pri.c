#include <stdio.h>
#include <stdlib.h>
#include "fila_pri.h"

struct no{
	int elem,pri;
	struct no* prox;
};

Fila cria_fila(){
	return NULL;
}
int fila_vazia(Fila *f){
	return !(*f);
}
int inserir(Fila *f, int elem,int pri){
	Fila No = (Fila) malloc(sizeof(struct no));
	if(No==NULL)return 0;
	No->elem=elem;
	No->pri=pri;
	if(fila_vazia(f)){
		(*f)=No;
		No->prox=NULL;
		return 1;
	}
	Fila temp = (*f);
	while(temp->prox!=NULL){
		if(temp->prox->pri>=pri) break;
		temp=temp->prox;
	}
	No->prox=temp->prox;
	temp->prox=No;
	return 1;
}

int remover_menor_prioridade(Fila *f, int *elem){
	if(fila_vazia(f)) return 0;
	Fila No = (*f);
	*elem=No->elem;
	(*f)=No->prox;
	free(No);
	return 1;
}

int remover_maior_prioridade(Fila *f, int *elem){
	if(fila_vazia(f)) return 0;
	Fila No = (*f);
	while(No->prox!=NULL) No=No->prox;
	*elem=No->elem;
    No=No->prox;
	return 1;
}

int remover(Fila *f, int *elem, int tipo){
    if(tipo==1) remover_maior_prioridade(f,elem);
    else remover_menor_prioridade(f,elem);
    return 1;
}

void imprimir(Fila *f){
    if(fila_vazia(f)) {
        printf("[FILA VAZIA]\n");
        return;
    }
    printf("Fila: [");
    Fila temp = (*f);
    while(temp!=NULL) {
        printf("%d ",temp->elem);
        temp = temp->prox;
    }
    printf("\b]\n");
}

void aguarde(){
    printf("Aperte ENTER para continuar...");
    char c=65;
    setbuf(stdin,NULL);
    while(c!=10) c=getchar();
}
