#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(){
	char str[30];
	printf("Digite uma string para saber se ela eh palindromo: ");
	scanf("%[^\n]s",str);
	if(palindrome(str)==1) printf("Sim, eh palindromo\n");
	else printf("Nao, nao é palindromo\n");
	return 0;
}