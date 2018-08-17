#include <stdlib.h>
#include <stdio.h>
#include "lista.h"
struct lista{
	int elemento;
	struct lista *prox;
};

Lista * cria_lista(){
	Lista * C = (Lista *) malloc(sizeof(Lista));
	if(C==NULL) return NULL;
	C->elemento=0;
	C->prox = NULL;
	return C;
}

int lista_vazia(Lista *l){
	if(l->elemento == 0)return 1;
	return 0;
}
/*int insere_elem(Lista *l, int elem){
	if(l == NULL) return 0;
	Lista *cabecalho = l;
	Lista *temp_aux = (Lista*) malloc(sizeof(Lista));
	temp_aux->elemento = elem;
	temp_aux->prox = cabecalho->prox;
	cabecalho->prox = temp_aux;
	cabecalho->elemento++;
	return 1;
}*/
int insere_ord(Lista *l, int elem){
	Lista *temp = (Lista *) malloc(sizeof(Lista));
	if(temp==NULL) return 0;
	temp->elemento = elem;
	
	if(l==NULL||elem>=l->elemento){
		temp->prox = l;
		l = temp;
		return 1;
	}

	Lista *aux = l;
	while(aux->prox!=NULL&&aux->prox->elemento>elem){
		aux = aux->prox;
	}
	temp->prox = aux->prox;
	aux->prox = temp;
	return 1;
}
/*
int remove_elem(Lista *l, int elem){
	if(lista_vazia(l)) return 0;
	Lista *temp = l;
	if(elem==l->elemento){
		l = temp->prox;
		free(temp);
		return 1;
	}
	while(temp->prox!=NULL && temp->prox->elemento!=elem) temp = temp->prox;
	if(temp->prox==NULL) return 0;
	Lista *temp_aux = temp->prox;
	temp->prox = temp_aux->prox;
	free(temp_aux);
	return 1;
}*/
int remove_ord(Lista *l, int elem){
	if(lista_vazia(l)) return 0;
	Lista *temp = l;
	if(elem==l->elemento){
		l = temp->prox;
		free(temp);
		return 1;
	}
	while(temp->prox!=NULL && temp->prox->elemento!=elem) temp = temp->prox;
	if(temp->prox==NULL) return 0;
	Lista *temp_aux = temp->prox;
	temp->prox = temp_aux->prox;
	free(temp_aux);
	return 1;
}
int tamanho(Lista *l){
	if(lista_vazia(l)) return 0;
	int i=0;
	while(l!=NULL){
		i++;
		l = l->prox;
	}
	return i;
}
void imprimi_lista(Lista *l){
	Lista * temp;
	temp = l;
	printf("Lista = {");
	while(temp->prox!=NULL){
		if(temp->prox->prox!=NULL)printf("%d ",temp->prox->elemento);
		else printf("%d",temp->prox->elemento);
		temp = temp->prox;
	}
	printf("}\n");
}
void imprimi_tamanho(Lista *L){
	printf("Tamanho = %d\n",tamanho(L));
}
void pause(){
	char c;
	setbuf(stdin,NULL);
	while(c!=10){
		c = getchar();
	}
	system("clear");
}
int maior(Lista *l){
	if(l==NULL || lista_vazia(l)) return 0;
	Lista *temp = l;
	int i,maior = temp->prox->elemento;
	while(temp->prox!=NULL){
		if(temp->prox->elemento > maior)maior=temp->prox->elemento;
	}
	return maior+1;// +1 pq  a lista pode ter o elem 0
}