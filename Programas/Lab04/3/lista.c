#include "lista.h"
struct lsta{
	int vet[MAX];
	int fim;
};
lista * cria_lista(){
	lista *l;
	l = (lista*) malloc(sizeof(lista));
	if(l!= NULL) l->fim = 0;
	return l;
}
int apaga_lista(lista **l){
	free(*l);
	*l = NULL;
}
int lista_vazia(lista *l){
	if(l->fim==0)return 1;
	return 0;
}

int lista_cheia(lista *l){
	if(l->fim==MAX)return 1;
	return 0;
}
int insere_elem(lista *l,int n){
	int i;
	if(l==NULL||lista_cheia(l)) return 0;
	i = l->fim;
	l->vet[l->fim++]=n;
	if(l->fim>i) return 1;
	return 0;
}
int insere_elem_ord(lista *l,int n){
	if(l==NULL||lista_cheia(l)) return 0;
	int i,j;
	for(i=0;i<l->fim;i++){
		if(n<l->vet[i]) break;
	}
	if(i>l->fim-1){
		l->vet[i]=n;;
		l->fim++;
		return 1;
	}
	else{
		for(j=l->fim;j>i;j--){
			l->vet[j] = l->vet[j-1];
		}
		l->vet[i]=n;
		l->fim++;
		return 1;
	}
	return 0;
}
int remove_elem(lista *l,int n){
	if(l==NULL||lista_vazia(l)) return 0;
	int i,j;
	for(i=0;i<l->fim;i++){
		if(l->vet[i]==n){
			if(i==l->fim){
				l->fim--;
				return 1;
			}
			else{
				for(j=i;j<l->fim;j++){
					l->vet[j] = l->vet[j+1];
				}
				l->fim--;
				return 1;
			}
		}
	}
	return 0;
}
int remove_elem_ord(lista *l, int n){
	if(l==NULL||lista_vazia(l))return 0;
	int i,j;
	for(i=0;i<l->fim;i++){
		if(l->vet[i]==n){
			if(i==l->fim){
				l->fim--;
				return 1;
			}
			else{
				for(j=i;j<l->fim;j++){
					l->vet[j] = l->vet[j+1];
				}
				l->fim--;
				return 1;
			}
		}
	}
	return 0;
}
void print_lista(lista *l){
	int i=0;
	printf("Lista\n{");
	for(i=0;i<l->fim;i++){
		if(i<l->fim-1)printf("%d ",l->vet[i]);
		else printf("%d",l->vet[i]);
	}
	printf("}\n");
}
void delay(int n){
	for(int j=0;j<n;j++){
		for(int i=0;i<100000000;i++);
	}
}