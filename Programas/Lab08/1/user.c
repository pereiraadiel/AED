#include <stdio.h>
#include "lista.h"
int main(){
	Lista L = cria_lista();
	int a,n;
	imprimi_lista(L);
	pause();
	printf("Numero de elementos para inserir: ");
	scanf("%d",&n);
	while(n-->0) {
		scanf("%d",&a);
		insere_final(&L,a);
	}
	imprimi_lista(L);
	pause();
	imprimi_tamanho(L);
	pause();
	if(remove_inicio(&L,&a)){
		printf("Elemento removido = %d\n",a);
	}
	else printf("Nada removido!\n");

	imprimi_lista(L);
	pause();
	imprimi_tamanho(L);
	pause();
	return 0;
}