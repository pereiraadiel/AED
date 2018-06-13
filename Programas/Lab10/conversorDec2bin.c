#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void add_to_string(char *string,char c){
	int tam = strlen(string);	
	int i;
	if(c) c='1';
	else c='0';
	string[tam]=c;
	string[tam+1]=0;
}

int conversor_dec_to_bin(int numero, char *string){
	Pilha p = cria_pilha();	
	int c;
	while(numero){
		push(&p,numero%2);
		numero/=2;
	}
	while(!pilha_vazia(p)){
		pop(&p,&c);
		//printf("%d",c);
		add_to_string(string,c);
	}
	return 1;
}
