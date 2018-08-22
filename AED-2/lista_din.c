#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
struct no{
	int elemento;
	struct no *prox;
};
int lista_vazia(Lista_din L){
	if(L==NULL) return 1;
	return 0;
}
Lista_din cria_lista_din(void){
	return NULL;
}
int insere_elem_final(Lista_din A, int elem){
	Lista_din no = (Lista_din) malloc(sizeof(struct no));
	Lista_din a temp = A;
	Lista_din temp_aux = A;
	if(no==NULL) return 0;
	no->elemento = elem;
	if(lista_vazia(temp)) {
		no->prox = no;
		temp = no;
		return 1;
	}
	while(temp->prox!=temp_aux){
		//printf("while\n");
		temp = temp->prox;
	}
	no->prox = temp->prox;
	temp->prox = no;
	temp = no;
	return 1;
}//*/
int insere_elem_inicio(Lista_din *A, int elem){
	Lista_din no = (Lista_din) malloc(sizeof(struct no));
	Lista_din temp = *A;
	if(no==NULL) return 0;
	no->elemento = elem;
	if(lista_vazia(temp)) {
		no->prox = no;
		temp = no;
		return 1;
	}
	no->prox = temp->prox;
	temp->prox = no;
	temp = no;
	return 1;
}

int remove_inicio(Lista_din *A,int *a){
	if(lista_vazia(*A)) return 0;
	Lista_din temp = *A;
	*a = temp->elemento;
	(*A) = temp->prox;
	free(temp);
	return 1;
}
void imprimi_lista(Lista_din l){
	if(lista_vazia(l)){
		printf("Lista = {}\n");
		return;
	}
	Lista_din temp = l;
	printf("Lista ={");
	while(temp->prox!=NULL){
		printf("%d ",temp->elemento);
		temp = temp->prox;
	}
	if(tamanho(temp)) printf("\b}\n");
	else printf("}\n");
}
int tamanho(Lista_din L){
	int tam=0;
	Lista_din temp = L;
	if(temp==NULL) return 0;
	while(temp->prox!=L){
		temp = temp->prox;
		tam++;
	}
	return tam;
}
void imprimi_tamanho(Lista_din L){
	int tam=tamanho(L);
	if(!tam){
		printf("Tamanho = 0\n");
		return;
	}
	printf("Tamanho = %d\n",tam);
}