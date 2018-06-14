#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
struct no{
	int elemento;
	struct no *prox;
	struct no* ant;
};

Lista cria_lista(){
	return NULL;
}
int lista_vazia(Lista L){
	if(L==NULL) return 1;
	return 0;
}

int insere_elem(Lista *L, int elem){
	Lista no = (Lista) malloc(sizeof(struct no));
	if(no == NULL) return 0;
	no->elemento = elem;
	no->ant = NULL;
	no->prox = (*L);
	if(!lista_vazia(*L)) (*L)->ant = no;
	(*L) = no;
	return 1;
}

int remove_elem(Lista *L, int elem){
	Lista temp = *L;
	if(lista_vazia(*L)) return 0;
	while(temp!=NULL && temp->elemento != elem){
		temp = temp->prox;
	}
	if(temp==NULL) return 0; //elem n pertence a lista
	if(temp->prox!=NULL){
		//caso geral
		if(temp->elemento==elem){
			temp->prox->ant = temp->ant;
			temp->ant->prox = temp->prox;
			free(temp);
			return 1;
		}
	}
	//elemento é o ultimo
	temp->ant->prox = temp->prox;
	free(temp);
	return 1;
}
void imprime_lista(Lista L){
	if(lista_vazia(L)){
		printf("Lista = {}\n");
		return;
	}
	Lista temp = L;
	printf("Lista ={");
	while(temp!=NULL){
		printf("%d ",temp->elemento);
		temp = temp->prox;
	}
	if(tamanho(L))printf("\b}\n");
	else printf("}\n");
	pause();
}
void pause(){
	char c;
	setbuf(stdin,NULL);
	printf("Aperte ENTER para continuar...");
	while(c!=10) c = getchar();
}
int tamanho(Lista L){
	Lista temp = L;
	int tam=0;
	while(temp!=NULL){
		temp = temp->prox;
		tam++;
	}
	return tam;
}