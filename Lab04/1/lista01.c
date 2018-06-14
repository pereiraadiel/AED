#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
typedef struct {
	int vet[MAX];
	int fim;
}lista;
lista * cria_lista();
int lista_vazia(lista *l);
int lista_cheia(lista *l);
int insere_elem(lista *l,int n);
int remove_elem(lista *l,int n);
int apaga_lista(lista **l);
void delay(int n);

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
int remove_elem(lista *l,int n){
	if(l==NULL||lista_vazia(l)) return 0;
	int i,j;
	for(i=0;i<l->fim;i++){
		if(l->vet[i]==n){
			if(i==l->fim-1){
				l->fim--;
				return 1;
			}
			else{
				for(j=i;j<l->fim;j++){
					l->vet[j] = l->vet[j+1];
					l->fim--;
				}
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
int main(int argc, char const *argv[])
{
	lista *l;
	l = cria_lista();
	int op,n;
	inicio:
	system("clear");
	printf("------------------------\n");
	printf("        Escolha\n");
	printf("------------------------\n");
	printf("[1] Inserir elemento.\n");
	printf("[2] Remover elemento.\n");
	printf("[3] Mostrar lista.\n");
	printf("[0] Sair\n");
	printf(": ");
	scanf("%d",&op);
	switch(op){
		case 0: apaga_lista(&l);break;
		case 1: 
			printf("Elemento: ");
			scanf("%d",&n);
			if(insere_elem(l,n)) printf("Sucesso!!\n");
			else printf("Falha!\n");
			delay(1);
			goto inicio;
		break;
		case 2: 
			printf("Elemento: ");
			scanf("%d",&n);
			if(remove_elem(l,n)) printf("Sucesso!!\n");
			else printf("Falha!\n");
			delay(1);
			goto inicio;
		break;
		case 3:
			print_lista(l);
			delay(8);
			goto inicio;
		break;
		default: goto inicio; break;
	}
	return 0;
}