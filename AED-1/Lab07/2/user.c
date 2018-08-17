#include <stdio.h>
#include "lista.h"
int main(){
	Lista *L = cria_lista();
	imprimi_lista(L);
	pause();
	insere_ord(L,5);
	insere_ord(L,4);
	insere_ord(L,1);
	insere_ord(L,6);
	insere_ord(L,3);
	imprimi_lista(L);
	pause();
	imprimi_tamanho(L);
	pause();
	remove_ord(L,1);
	imprimi_lista(L);
	pause();
	imprimi_tamanho(L);
	pause();
	printf("maior elemento: %d\n",maior(L));
	return 0;
}