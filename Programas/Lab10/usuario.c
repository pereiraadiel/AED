#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "conversorDec2bin.h"

int main(){
	int numero;
	char string[max]="";
	printf("CONVERSOR DECIMAL2BINARIO\n");
	printf("--------------------------\n");
	printf("Digite o decimal:");
	scanf("%d",&numero);
	conversor_dec_to_bin(numero,string);
	printf("---------------------------\n");
	printf("Binario: %s\n",string);
}