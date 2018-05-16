#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
struct no{
	int elemento;
	struct no *prox;
};
int lista_vazia(Lista L){
	if(L==NULL) return 1;
	return 0;
}
Lista cria_lista(void){
	return NULL;
}
int insere_final(Lista *A, int elem){
	Lista no = (Lista) malloc(sizeof(struct no));
	Lista temp = *A;
	Lista temp_aux = *A;
	if(no==NULL) return 0;
	no->elemento = elem;
	if(lista_vazia(temp)) {
		no->prox = no;
		temp = no;
		return 1;
	}
	while(temp->prox!=temp_aux){
		printf("while\n");
		temp = temp->prox;
	}
	no->prox = temp->prox;
	temp->prox = no;
	temp = no;
	return 1;
}//*/
int remove_inicio(Lista *A,int *a){
	if(lista_vazia(*A)) return 0;
	Lista temp = *A;
	*a = temp->elemento;
	(*A) = temp->prox;
	free(temp);
	return 1;
}
void imprimi_lista(Lista l){
	if(lista_vazia(l)){
		printf("Lista = {}\n");
		return;
	}
	Lista temp = l;
	printf("Lista ={");
	while(temp->prox!=NULL){
		printf("%d ",temp->elemento);
		temp = temp->prox;
	}
	if(tamanho(temp)) printf("\b}\n");
	else printf("}\n");
}
int tamanho(Lista L){
	int tam=0;
	Lista temp = L;
	if(temp==NULL) return 0;
	while(temp->prox!=L){
		temp = temp->prox;
		tam++;
	}
	return tam;
}
void imprimi_tamanho(Lista L){
	int tam=tamanho(L);
	if(!tam){
		printf("Tamanho = 0\n");
		return;
	}
	printf("Tamanho = %d\n",tam);
}
void pause(){
	char c;
	setbuf(stdin,NULL);
	printf("Aperte ENTER para continuar...");
	while(c!=10)c = getchar();
}