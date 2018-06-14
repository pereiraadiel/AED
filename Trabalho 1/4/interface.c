#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "interface.h"
void menu(){
	system("clear");
	setlocale(LC_ALL,"Portuguese");
	printf("==============================================\n");
	printf("  TAD Lista Ordenada Dinâmicamente Encadeada\n");
	printf("==============================================\n");
	printf("\n");
	printf("----------------------------------------------\n");
	printf("              Escolha uma opção\n");
	printf("----------------------------------------------\n");
	printf("[0] SAIR\n");
	printf("[1] Inserir elemento(s)\n");
	printf("[2] Remover elemento(s)\n");
	printf("[3] Remover impares\n");
	printf("[4] Menor elemento\n");
	printf("[5] Tamanho da lista\n");
	printf("[6] Igualdade entre listas\n");
	printf("[7] Concatenar\n");
	printf("[8] Imprimir lista\n");
	printf(":");
}
void sub_menu_inserir(){
	system("clear");
	printf("----------------------------\n");
	printf("     Inserir Elemento\n");
	printf("----------------------------\n");
	printf("[0] Voltar\n");
	printf("[1] Inserir ordenado\n");
	//printf("[2] Inserir no inicio da lista\n");
	printf(":");
}
void sub_menu_remover(){
	system("clear");
	printf("----------------------------\n");
	printf("     Remover Elemento\n");
	printf("----------------------------\n");
	printf("[0] Voltar\n");
	printf("[1] Remover primeira ocorrencia\n");
	//printf("[2] Remover todas ocorrencias\n");
	printf(":");
}
void sub_menu_concatena(){
	system("clear");
	printf("----------------------------\n");
	printf("         Concatenar\n");
	printf("----------------------------\n");
	printf("[0] Voltar\n");
	printf("[1] Usar lista atual\n");
	printf("[2] Criar novas listas\n");
	printf(":");
}
void sub_menu_igualdade(){
	system("clear");
	printf("----------------------------\n");
	printf("         Igualdade\n");
	printf("----------------------------\n");
	printf("[0] Voltar\n");
	printf("[1] Comparar uma lista com a atual\n");
	printf("[2] Comparar duas novas listas\n");
	printf(":");
}