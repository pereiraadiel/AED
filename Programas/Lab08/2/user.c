#include <stdio.h>
#include "lista.h"
int main(){
	Lista A = cria_lista();
	printf("Tamanho da Lista = %d\n",tamanho(A));
	pause();
	insere_elem(&A,5);
	insere_elem(&A,4);
	insere_elem(&A,5);
	insere_elem(&A,6);
	insere_elem(&A,3);
	imprime_lista(A);
	printf("Tamanho da Lista = %d\n",tamanho(A));
	pause();
	remove_elem(&A,5);
	imprime_lista(A);
	printf("Tamanho da Lista = %d\n",tamanho(A));
	pause();
	remove_elem(&A,5);
	imprime_lista(A);
	printf("Tamanho da Lista = %d\n",tamanho(A));
	pause();
	return 0;
}