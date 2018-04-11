#include <stdio.h> 
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int matricula,faltas,situacao;
	float prova[3],media;
	char nome[30];
}Aluno;

float Media(Aluno A);
int Situacao(Aluno A);
void aprovacao(Aluno A);
void imprimir_dados(Aluno A[3],int N);
void letra_E(Aluno A[3],int N);
void cadastrar(int N, Aluno *A);