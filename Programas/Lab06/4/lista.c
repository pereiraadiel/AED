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

/*int remove_elem_ord(Lista **l, int elem){
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
	
	while(temp!=NULL && temp->prox->elemento < elem){ //geral
		temp = (*l)->prox;
	}
	if(temp->prox==NULL||elem < temp->prox->elemento)//elem nao existe
	return 0;
	temp_aux = temp->prox;
	temp->prox = temp_aux->prox;
	free(temp_aux);
	return 1;
}*/
int remove_elem_ord(Lista **l, int elem){
	if((*l)==NULL) return 0;
	Lista *temp = *l;
	if(elem==(*l)->elemento){
		(*l) = temp->prox;
		free(temp);
		return 1;
	}
	while(temp!=NULL && temp->elemento!=elem) temp = temp->prox;
	if(temp->prox==NULL) return 0;
	Lista *temp_aux = temp->prox;
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
void menu_intercala(Lista **l){
	int op,num,i,elem;
	Lista *temp;
	Lista *temp_aux;
	while(1){
		system("clear");
		printf("------------------------\n");
		printf("       Intercalar       \n");
		printf("------------------------\n");
		printf("[1] Usar lista existente\n");
		printf("[2] Criar novas lista\n");
		printf("[3] Mostrar Lista intecalada.\n");
		printf("[0] Cancelar/Voltar\n");
		scanf("%d",&op);
		if(op==0) break;//comando de parada
		switch(op){
			case 1: //inserir elem da lista 2 
				temp=cria_lista();
				printf("Numero de elementos da Lista 2: ");
				scanf("%d",&num);
				for(i=0;i<num;i++){
					printf("Elem [%d]: ",i+1);
					scanf("%d",&elem);
					insere_elem(&temp,elem);
				}
				(*l) = intercala_ord(&temp,l);
			break;
			case 2: //inserir elem nas 2 novas listas
				temp=cria_lista();
				temp_aux=cria_lista();
				printf("Numero de elementos da Lista 1: ");
				scanf("%d",&num);
				for(i=0;i<num;i++){
					printf("Elem [%d]: ",i+1);
					scanf("%d",&elem);
					insere_elem(&temp,elem);
				}
				printf("Numero de elementos da Lista 2: ");
				scanf("%d",&num);
				for(i=0;i<num;i++){
					printf("Elem [%d]: ",i+1);
					scanf("%d",&elem);
					insere_elem(&temp_aux,elem);
				}
				(*l) = intercala_ord(&temp,&temp_aux);
			break;
			case 3:
				print_lista(*l);
				pause();
			break;
		}
	}
}
Lista * intercala_ord(Lista **A, Lista **B){
	Lista *C = cria_lista();
	Lista *temp;
	Lista *temp_aux;
	int controle=0;
	temp = (*A);
	while(temp!=NULL){
		insere_elem_ord(&C,temp->elemento);
		temp = temp->prox;
	}
	temp_aux = (*B);
	while(temp_aux!=NULL){
		insere_elem_ord(&C,temp_aux->elemento);
		temp_aux = temp_aux->prox;
	}
	return C;
}
void apaga_lista(Lista **l){
	Lista *temp = (*l);
	free(temp);
	temp = NULL;
}
void pause(){
	char c;
	setbuf(stdin,NULL);
	printf("Aperte ENTER para continuar...");
	while(c!=10) c = getchar();//ate apertar o '\n'
}