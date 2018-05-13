#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "interface.h"
void menu(){
	system("clear");
	setlocale(LC_ALL,"Portuguese");
	printf("==============================================\n");
	printf("     TAD Lista Não Ordenada Dinâmica com\n");
	printf("            Encadeamento Duplo\n");
	printf("==============================================\n");
	printf("\n");
	printf("----------------------------------------------\n");
	printf("              Escolha uma opção\n");
	printf("----------------------------------------------\n");
	printf("[0] SAIR\n");
	printf("[1] Inserir elemento(s)\n");
	printf("[2] Remover elemento(s)\n");
	printf("[3] Remover maior elemento\n");
	printf("[4] Multiplos de 3\n");
	printf("[5] Tamanho da lista\n");
	printf("[6] Imprimir lista\n");
	printf(":");
}
void sub_menu_inserir(){
	system("clear");
	printf("----------------------------\n");
	printf("     Inserir Elemento\n");
	printf("----------------------------\n");
	printf("[0] Voltar\n");
	printf("[1] Inserir no inicio da lista\n");
	printf(":");
}
void sub_menu_remover(){
	system("clear");
	printf("----------------------------\n");
	printf("     Remover Elemento\n");
	printf("----------------------------\n");
	printf("[0] Voltar\n");
	printf("[1] Remover primeira ocorrencia\n");
	printf("[2] Remover todas as ocorrencias\n");
	//printf("[3] Remover maior elemento\n");
	printf(":");
}
