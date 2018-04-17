#include "lista.h"
struct lista{
	String* vet;
	int fim;
};

Lista* cria_lista(){
	Lista *S;
	S = (Lista*) malloc(sizeof(Lista));
	S->vet = (char**)malloc(MAX*sizeof(char*));
	for (int i = 0; i < MAX; i++) {
		S->vet[i] = (char*) malloc(MAX*sizeof(char));
	}
	if(S!=NULL)	S->fim=0;
	return S;
}
void apaga_lista(Lista **l){
	free(*l);
	*l = NULL;
}
int lista_vazia(Lista *l){
	if(l->fim==0) return 1;
	return 0;
}
int lista_cheia(Lista *l){
	if(l->fim==MAX) return 1;
	return 0;
}
int insere_elem(Lista *l,String s){
	int i;
	if(l==NULL||lista_cheia(l)) return 0;
	i = l->fim;
	printf("%s\n",s);
	strcpy(l->vet[l->fim++],s);
	printf("%s\n",l->vet[l->fim-1]);
	if(l->fim>i) return 1;
	return 0;
}
int remove_elem(Lista *l,String s){
	if(l==NULL||lista_vazia(l)) return 0;
	int i,j;
	for(i=0;i<l->fim;i++){
		if(strcmp(l->vet[i],s)==0){
			if(i==l->fim){
				l->fim--;
				return 1;
			}
			else{
				for(j=i;j<l->fim;j++){
					strcpy(l->vet[j],l->vet[j+1]);
				}
				l->fim--;
				return 1;
			}
		}
	}
	return 0;
}
void print_lista(Lista *l){
	int i=0;
	printf("Lista\n{");
	for(i=0;i<l->fim;i++){
		if(i<l->fim-1)printf("%s ",l->vet[i]);
		else printf("%s",l->vet[i]);
	}
	printf("}\n");
}
void delay(int n){
	for(int j=0;j<n;j++){
		for(int i=0;i<100000000;i++);
	}
}