#include "lista.h"

struct encadeada{
	int elemento;
	struct encadeada *prox;
};

Lista *cria_lista(){
	return 0;//NULL
}
int insere_elem(Lista **l, int elem){
	Lista *temp;
	temp = (Lista *) malloc(sizeof(Lista));
	if(temp==NULL) return 0;
	temp->elemento = elem;
	temp->prox = *l;
	*l=temp;
	return 1;
}

int insere_elem_ord(Lista **l,int elem){
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

int remove_elem(Lista **l,int elem){
	if((*l)==NULL) return 0;//lista vazia
	Lista *temp = *l;
	if(elem==(*l)->elemento){
		*l = temp->prox;
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

int remove_elem_ord(Lista **l, int elem){
	if((*l)==NULL||elem < (*l)->prox->elemento) return 0;//lista vazia
	//ou elemento nao existi.
	Lista *temp;
	Lista *temp_aux;

	temp = *l;
	if(elem==(*l)->elemento){ //primeiro elemento
		*l = temp->prox;
		free(temp);
		return 1;
	}
	
	while(temp->prox!=NULL && temp->prox->elemento < elem){ //geral
		temp = (*l)->prox;
	}
	if(temp->prox==NULL||elem < temp->prox->elemento)//elem nao existe
	return 0;
	temp_aux = temp->prox;
	temp->prox = temp_aux->prox;
	free(temp_aux);
	return 1;
}
int remove_tds_ocorrencias(Lista **l, int elem){
	if((*l)==NULL) return 0;// lista vazia
	Lista *temp;
	Lista *temp_aux;
	int removido=0;
	temp = *l;//apontar o ponteiro pro inicio = "i=0"
	if(elem==(*l)->elemento){ //caso for o primeiro elemento
		*l = temp->prox;
		free(temp);
		removido++;
	}
	while(temp->prox!=NULL){
		if(elem == temp->prox->elemento){
			temp_aux = temp->prox;
			temp->prox = temp_aux->prox;
			free(temp_aux);//removida uma ocorrencia
			removido++;//contador de remoções
			temp = *l;//voltar pro inicio
		}
		else temp = temp->prox;// "i++"
	}
	if(removido) return 1;
	//se o fluxo chegar aqui eh pq o elem
	//nao pertence a esta lista
	return 0;
}
int lista_vazia(Lista *l){
	if(l->prox==NULL) return 1;
	return 0;
	//algo de errado nao esta certo
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