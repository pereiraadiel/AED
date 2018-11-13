#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
struct aluno{
	char nome[25];
	int matricula;
	int notas[3];
};
Aluno cria_aluno(char *nome,int mat, int notas[3]){
	//printf("#0\n");
	Aluno al = (Aluno) malloc(sizeof(struct aluno));
	int i;
	//printf("#1\n");
	if(al!=NULL){
	//	printf("#2\n");
		al->matricula = mat;
	//	printf("#3\n");
		for(i=0;i<3;i++) al->notas[i] = notas[i];
	//	printf("#4\n");
		strcpy(al->nome,nome);
	//	printf("#5\n");
		return al;
	}
	return NULL;
}
void libera_aluno(Aluno a){
	if(a==NULL) return;
	free(a);
	a = NULL;
}

void print_aluno(Aluno a){
	if(a==NULL) return;
	int i;
	printf("----------------------\n");
	printf("Nome: %s\n",a->nome);
	printf("Matricula: %d\n",a->matricula);
	for(i=0;i<3;i++) printf("Nota[%d]: %d\n",i,a->notas[i]);
	//printf("\n");
	printf("----------------------\n");
}