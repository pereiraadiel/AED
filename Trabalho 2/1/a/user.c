#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(){

	Pilha p;
	int qnt,n,i;
	char op;

	p = cria_pilha();
	printf("Pilha criada:");
	imprimir(&p);
	printf("\n");

	printf("Deseja inserir quantos elementos na pilha? ");
	scanf("%d",&qnt);

	for(i=0;i<qnt;i++){
		printf("Elemento %d: ",i+1);
		scanf("%d",&n);
		empilhar(&p,n);

	}

	printf("\nPilha:\n\n");
	imprimir(&p);
	printf("\n");

	setbuf(stdin,NULL);
	printf("Deseja remover o elemento do topo? (Y=Sim e N=NAO) ");
	scanf("%c",&op);
	if(op=='y' || op=='Y') {
		desempilhar(&p,&n); 
		printf("Elemento removido: %d\n",n);
	}

	printf("\nPilha modificada:\n\n");
	imprimir(&p);
	printf("\n");

	printf("\nPilha ordem reversa:\n\n");
	imprimir_rev(&p);
	printf("\n");
	return 0;
}