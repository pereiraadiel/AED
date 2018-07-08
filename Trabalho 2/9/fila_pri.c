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
	if((*f)==NULL)return 1;
	return 0;
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
