#include <stdlib.h>
#include <stdio.h>
#include "lista.h"
struct no{
	int elemento;
	struct no * prox;
};
Lista *cria_lista(){
	return NULL;
}
int lista_vazia(Lista *l){
	if(l==NULL) return 1;
	return 0;
}

int insere_ord(Lista **l, int elem){
	Lista *temp = (Lista *) malloc(sizeof(Lista));
	if(temp==NULL) return 0;
	temp->elemento = elem;
	
	if((*l)==NULL||elem>=(*l)->elemento){
		temp->prox = *l;
		*l = temp;
		return 1;
	}

	Lista *aux = *l;
	while(aux->prox!=NULL&&aux->prox->elemento>elem){
		aux = aux->prox;
	}
	temp->prox = aux->prox;
	aux->prox = temp;
	return 1;
}
int remove_ord(Lista **l, int elem){//nao remove o ultimo
	if((*l)==NULL) return 0;
	Lista *temp = *l;
	if(elem==(*l)->elemento){
		(*l) = temp->prox;
		free(temp);
		return 1;
	}
	while(temp!=NULL && temp->prox->elemento!=elem) temp = temp->prox;
	if(temp->prox==NULL) {
		return 0;
	}
	Lista *temp_aux = temp->prox;
	temp->prox = temp_aux->prox;
	free(temp_aux);
	return 1;
}
void imprimi_lista(Lista *l){
	//if(lista_vazia(l)) return;
	printf("Lista = {");
	Lista *temp= l;
	while(temp!=NULL){
		printf(" %d ",temp->elemento);
		temp = temp->prox;
	}
	printf("}\n");
}

Lista * concatenar(Lista **A, Lista **B){
	Lista *C = cria_lista();
	Lista *temp = *A;
	Lista *temp_aux = *B;
	while(temp!=NULL){
		insere_ord(&C,temp->elemento);
		temp = temp->prox;
		//free(temp);
	}
	while(temp_aux!=NULL){
		insere_ord(&C,temp_aux->elemento);
		temp_aux = temp_aux->prox;
		//free(temp_aux);
	}
	return C;
}
int tamanho(Lista *L){
	if(lista_vazia(L)) return 0;
	Lista *temp = L;
	int contador = 0;
	while(temp!=NULL){
		temp = temp->prox;
		contador++;
	}
	return contador;
}
int iguais(Lista *A, Lista *B){
	if(lista_vazia(A)&&lista_vazia(B)) return 1;
	int iguais = 0;
	if(tamanho(A)!=tamanho(B)) return 0;
	Lista *temp = A, *temp_aux = B;
	while(temp!=NULL){
		if(temp->elemento!=temp_aux->elemento) return 0;
		temp = temp->prox;
		temp_aux = temp_aux->prox;
		iguais++;
	}
	if(iguais==tamanho(A)) return 1;
	return 0;
}
int remove_impares(Lista **A){//nao esta removendo todos os impares
	Lista *temp = *A->prox;
	Lista *temp_aux = *A;
	if(lista_vazia(temp)) return 0;
	int removido=0;
	if(temp_aux->elemento%2!=0){
		free(temp_aux);
		temp_aux = temp;
	}
	while(temp!=NULL){
		if(temp->elemento%2!=0){
			temp_aux->prox = temp->prox;
			free(temp);
			temp = temp_aux->prox;
			removido++;
		}
		else{
			temp = temp->prox;
		}
		temp_aux = temp_aux->prox;
	}
	return removido;
}
int menor(Lista *A){
	Lista *temp = A;
	if(lista_vazia(temp)) return 0;
	int menor = temp->elemento;
	while(temp!=NULL){
		if(temp->elemento<menor)menor = temp->elemento;
		temp = temp->prox;
	}
	return menor+1;//mais 1 pq a lista pode conter o elemento zero assim n pode existir o elemento -1
}
void pause(){
	char c;
	setbuf(stdin,NULL);
	printf("Aperte ENTER para continuar...\n");
	while(c!=10) c=getchar();
}