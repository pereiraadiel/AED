#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
struct fila{
	int elem[MAX];
	int inicio,fim;
};
Fila cria_fila(){
	Fila f = (Fila) malloc(sizeof(struct fila));
	if(f){
		f->fim=f->inicio=0;
	}
	return f;
}
int fila_vazia(Fila f){
	if(f){
		if(f->fim==0) return 1;
	}
	return 0;
}
int fila_cheia(Fila f){
	if(f){
		if(f->fim==MAX) return 1;
	}
	return 0;
}
int inserir(Fila f, int elem){
	if(f==NULL) return 0;
	if(!fila_cheia(f)){
		f->elem[f->fim++]=elem;
		return 1;
	}
	return 0;
}
int remover(Fila f, int *elem){
	if(f==NULL) return 0;
	if(!fila_vazia(f)){
		*elem = f->elem[f->inicio];
		int i;
		for(i=0;i<f->fim;i++) f->elem[i]=f->elem[i+1];
		f->fim--;
		return 1;
	}
	return 0;
}
void imprimir(Fila f){
	if(f==NULL) return;
	if(fila_vazia(f)){
		printf("Fila: []\n");
		return;
	}	
	int i;
	printf("Fila: [");
	for(i=0;i<f->fim;i++){
		printf("%d ",f->elem[i]);
	}
	printf("\b]\n");
}