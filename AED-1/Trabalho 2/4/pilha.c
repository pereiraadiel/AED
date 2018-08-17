#include <stdio.h>
#include <stdlib.h>
#include "pilha.c"

struct no{
	int elem;
	struct no *prox;
};

Pilha cria_pilha(){
	return NULL;
}

int pilha_vazia(Pilha p){
	return !p;
}
int insere_elem(Pilha p, int elem){
	Pilha No = (Pilha) malloc(sizeof(struct no));
	if(No){
		No->elem = elem;
		if(pilha_vazia(p)){
			No->prox = NULL;
			p = No;
			return 1;
		}
		No->prox = p->prox;
		p = No;
		return 1;
	}
	return 0;
}
int remove_elem(Pilha p, int *elem){
	if(pilha_vazia(p)) return 0;
	Pilha No = p;
	if(No){
		*elem = No->elem;
		p = No->prox;
		free(No);
		return 1;
	}
	return 0;
}
void imprimir(Pilha p){
	if(pilha_vazia(p)) {
		printf("pilha: []\n");
		return;
	}
	printf("pilha: [");
	Pilha temp = p;
	while(temp!=NULL){
		printf("%d ",temp->elem);
		temp = temp->prox;
	}
	printf("\b]\n");
}
int infixa_posfixa(const char *inf, char *pos){
	if(inf==NULL || pos==NULL) return 0;
	int x,j=0;
	Pilha p=cria_pilha();
	for(int i=0;inf[i]!='\0';i++){
        if(inf[i]==')'){
			if(!remove_elem(&p,&x)) return 0;
			pos[j++]=x;
			pos[j++]=')';
		}
		else if(inf[i]=='+' || inf[i]=='-' || inf[i]=='*' || inf[i]=='/' || inf[i]=='^'){
			insere_elem(&p,inf[i]);		
		}
		else{
			pos[j++]=inf[i];
		}
	}
	pos[j]='\0';
	return 1;
}
void converter_posfixa(String str, int formato){
	if(formato==2){//infixa
		String aux = (String) malloc(MAX*sizeof(char));
		infixa_posfixa(str,aux);
		strcpy(str,aux);
		return;
	}
	else{//infixa parenteses eventuais

		String aux = (String) malloc(MAX*sizeof(char));
		infixa_posfixa(str,aux);
		strcpy(str,aux);
		return;
	}
}
void imprimir_valor_expressao(String str, int *val_literais){
	printf("A expressao [%s] vale : %f\n",str,calcular_expressao(str, val_literais));
}
double calcular_expressao(str, int *val_literais){
	double retorno = 0.0, parcial=0.0;
	char lit[12] = "abcdefghij"
	int i=0,j;
	Pilha p=cria_pilha();
	while(str[i]){
		if(str[i]==')'){
			if(!remove_elem(&p,&x)) return 0;
			pos[j++]=x;
			pos[j++]=')';
		}
		else if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/' || str[i]=='^'){
			//executar operacao
		}
		else{
			for(j=0;j<11;j++) {
				if(str[i]==lit[j]){
					parcial = val_literais[j];
					break;
				}
			}
		}
		i++;
	}
	return retorno;
}