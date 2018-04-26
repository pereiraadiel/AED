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

int insere_elem_ord(Lista **l,int n){
	Lista *temp = (Lista *) malloc(sizeof(Lista));
	if(temp==NULL) return 0;
	temp->elemento = n;
	
	if((*l)==NULL||n>=(*l)->elemento){
		temp->prox = *l;
		*l = temp;
		return 1;
	}

	Lista *aux = *l;
	while(aux->prox!=NULL&&aux->prox->elemento>n){
		aux = aux->prox;
	}
	temp->prox = aux->prox;
	aux->prox = temp;
	return 1;
}

int remove_elem(Lista **l,int n){
	if((*l)==NULL) return 0;//lista vazia
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

int remove_elem_ord(Lista **l, int n){
	if((*l)==NULL||n < (*l)->prox->elemento) return 0;//lista vazia
	//ou elemento nao existi.
	Lista *temp;
	Lista *temp_aux;

	temp = *l;
	if(n==(*l)->elemento){ //primeiro elemento
		*l = temp->prox;
		free(temp);
		return 1;
	}
	
	while(temp->prox!=NULL && temp->prox->elemento < n){ //geral
		temp = (*l)->prox;
	}
	if(temp->prox==NULL||n < temp->prox->elemento)//elem nao existe
	return 0;
	temp_aux = temp->prox;
	temp->prox = temp_aux->prox;
	free(temp_aux);
	return 1;
}

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
	
}

void delay(int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<250000;j++);
	}
}
void pause(){
	char c;
	setbuf(stdin,NULL);
	printf("Aperte ENTER para continuar...");
	while(c!=10) c = getchar();//ate apertar o '\n'
}