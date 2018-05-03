#include <stdio.h>
#include "lista.h"
int main(){
	Lista *L = cria_lista();
	imprimi_lista(L);
	pause();
	insere_elem(L,5);
	insere_elem(L,4);
	insere_elem(L,1);
	insere_elem(L,6);
	insere_elem(L,3);
	imprimi_lista(L);
	pause();
	imprimi_tamanho(L);
	pause();
	remove_elem(L,1);
	imprimi_lista(L);
	pause();
	imprimi_tamanho(L);
	pause();
	return 0;
}