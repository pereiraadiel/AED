#include "lista.h"

struct encadeada{
	int elemento;
	struct encadeada *prox;
};

Lista *cria_lista(){
	return 0;//NULL
}
int insere_elem(Lista **l, int n){
	Lista *temp;
	temp = (Lista *) malloc(sizeof(Lista));
	if(temp==NULL) return 0;
	temp->elemento = n;
	temp->prox = *l;
	*l=temp;
	return 1;
}
/*
int insere_elem_ord(Lista **l,int n){
	Lista *temp = (Lista *) malloc(sizeof(Lista));
	if(temp==NULL) return 0;
	temp->elemento = n;
	Lista *aux = *l;
	while(aux->prox!=NULL&&aux->prox->elemento<n){
		aux = aux->prox;
	}
	temp->prox = aux->prox;
	aux->elemento = n;
	return 1;
}
*/
int remove_elem(Lista **l,int n){
	if(lista_vazia(*l)) return 0;
	Lista *temp = *l;
	if(n==(*l)->elemento){
		*l = temp->prox;
		free(temp);
		return 1;
	}
	while(temp->prox!=NULL && temp->prox->elemento!=n) temp = temp->prox;
	if(temp->prox==NULL) return 0;
	Lista *temp_aux = temp->prox;
	temp->prox = temp_aux->prox;
	free(temp_aux);
	return 1;
}
/*
int remove_elem_ord(Lista **l, int n){
	if(lista_vazia(*l)) return 0;
	Lista *aux,*aux2;
	aux = (*l)->prox;
	while(aux->prox!=NULL&&aux->elemento!=n){
		aux = (*l)->prox;
	}
	if(aux->prox==NULL) return 0;
	aux2 = aux->prox;
	*l = aux2;
	free(aux);
	return 1;
}
*/
int lista_vazia(Lista *l){
	if(l->prox==NULL) return 1;
	return 0;
}
void print_lista(Lista *l){
	Lista * temp;
	temp = l;
	printf("Lista = {");
	while(temp!=NULL){
		if(temp->prox!=NULL)printf("%d ",temp->elemento);
		else printf("%d",temp->elemento);
		temp = temp->prox;
	}
	printf("}\n");

}
void apaga_lista(Lista *l){
	//Lista *aux = cria_lista();
	while(l->prox!=NULL){
		remove_elem(&l,l->elemento);
	}	
	free(l);
}
void delay(int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<150000;j++);
	}
}