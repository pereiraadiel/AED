#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(){
	Fila f = cria_fila();
	int elem[4]={63,23,569,9},i,rem;
	if(f){
		printf("Fila iniciada!\n");
		imprimir(f);
		printf("Inserindo elementos...\n");
		for(i=0;i<4;i++){
			inserir(f,elem[i]);
			imprimir(f);
		}
		printf("Elementos inseridos.\n");
		imprimir(f);
		while(!fila_vazia(f)){
			printf("Removendo elemento do inicio..\n");
			remover(f,&rem);
			printf("Elemento removido: %d\n",rem);
			imprimir(f);
		}
	}
	else printf("Erro - Alocacao de memoria falhou!\n");
	return 0;
}