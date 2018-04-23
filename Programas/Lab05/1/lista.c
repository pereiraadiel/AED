#include "lista.h"

struct encadeada{
	int elemento;
	struct encadeada *prox;
};

Lista *cria_lista(){
	Lista *l;
	l = (Lista*) malloc(sizeof(Lista));
	if(l!=NULL) l->prox=NULL;
	return l;
}
int insere_elem(Lista *l,int n){
	Lista *aux;
	aux = cria_lista();
	aux->elemento = n;
	aux->prox = l;
	l=aux;
	return 1;
	//return 0;
}
int remove_elem(Lista *l, int n){
	Lista *aux,*aux2;
	aux = l->prox;
	while(aux->prox!=NULL&&aux->elemento!=n){
		aux = l->prox;
	}
	if(aux->prox==NULL) return 0;
	aux2 = aux->prox;
	l = aux2;
	free(aux);
}
int lista_vazia(Lista *l){
	if(l->prox==NULL) return 1;
	return 0;
}
void print_lista(Lista *l){
	int i=0;
	printf("Lista\n{");
	for(i=0;l->prox!=NULL;i++){
		if(l->prox!=NULL)printf("%d ",l->elemento);
		else printf("%d",l->elemento);
	}
	printf("}\n");

}
void apaga_lista(Lista *l){
	//Lista *aux = cria_lista();
	while(l->prox!=NULL){
		remove_elem(l,l->elemento);
	}	
	free(l);
}
void delay(int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<110000;j++);
	}
}