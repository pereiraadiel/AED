#include <stdio.h>
#include "pilha.h"
void menu(){
	printf("------------------------\n");
	printf("        Escolha\n");
	printf("------------------------\n");
	printf("[1] pre-fixa\n");
	printf("[2] infixa\n");
	printf("[3] pos-fixa\n");
	printf("[0] SAIR\n");
	printf("-------------------------\n");
	printf("opcao: ");
}
int executar(){
	char lit[12] = "abcdefghij"
	int op, literais, val_litereais[11];
	int formato=0,i; //armazena o formato da expressao: 1 prefixa 2 infixa 3 prefixa
	String str;
	str = (String) malloc(MAX*sizeof(char));
	while(op<0 || op>3){
		menu();//escolha do formato de expressao
		scanf("%d",&op);
	}
	if(op==0) return 0;
	formato = op;
	while(literais<1 || literais >11){
		printf("quantos literais a expressao possui? ");
		scanf("%d",&literais);
	}
	for(i=0;i<literais;i++){
		printf("valor do literal \'%c\' : ",lit[i] );
		scanf("%d",&val_litereais[i]);
	}
	printf("Digite a expressao: ");
	scanf("%s",str);
	if(formato!=1){
		str = converter_posfixa(str,formato);
		printf("Expressao na forma pos-fixa: %s\n",str);
	}
	imprimir_valor_expressao(str,val_litereais);
	return 1;
}
int main(){
	while(executar());
	return 0;
}