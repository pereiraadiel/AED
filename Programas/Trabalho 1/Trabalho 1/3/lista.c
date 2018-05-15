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
int insere_elem(Lista **l, int elem){
	Lista *temp = (Lista *) malloc(sizeof(Lista));
	if(temp==NULL) return 0;
	temp->elemento = elem;
	temp->prox = *l;
	*l = temp;
	return 1;
}
int insere_final(Lista *l, int elem){
	Lista *temp = (Lista *) malloc(sizeof(Lista));
	if(temp==NULL) return 0;
	temp->elemento = elem;
	
	if(l==NULL){
		temp->prox = l;
		l = temp;
		return 1;
	}

	Lista *aux = l;
	while(aux->prox!=NULL){
		aux = aux->prox;
	}
	temp->prox = aux->prox;
	aux->prox = temp;
	return 1;
}
/*
int remove_ord(Lista **l, int elem){
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
}*/
int remove_elem(Lista **l, int elem){
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
int remove_todos(Lista **l, int elem){
	Lista *temp = *l;
	if(lista_vazia(temp)) return 0;
	int removido=0;
	while(temp!=NULL){
		if(temp->elemento==elem){
			remove_elem(l,temp->elemento);
			removido++;
		}
		temp = temp->prox;
	}
	return removido;
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
		insere_elem(&C,temp->elemento);
		temp = temp->prox;
		//free(temp);
	}
	while(temp_aux!=NULL){
		insere_elem(&C,temp_aux->elemento);
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
int remove_pares(Lista **A){
	Lista *temp = *A;
	if(lista_vazia(temp)) return 0;
	int removido=0;
	while(temp!=NULL){
		if(temp->elemento%2==0){
			remove_elem(A,temp->elemento);
			removido++;
		}
		temp = temp->prox;
	}
	return removido;
}
int maior(Lista *A){
	Lista *temp = A;
	if(lista_vazia(temp)) return 0;
	int maior = temp->elemento;
	while(temp!=NULL){
		if(temp->elemento>maior)maior = temp->elemento;
		temp = temp->prox;
	}
	return maior+1;//mais 1 pq a lista pode conter o elemento zero
}
void pause(){
	char c;
	setbuf(stdin,NULL);
	printf("Aperte ENTER para continuar...\n");
	while(c!=10) c=getchar();
}