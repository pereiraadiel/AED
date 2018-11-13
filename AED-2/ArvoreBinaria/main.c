#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "ArvoreBinaria.h"


int main(){
	int nota[3],i; //={1,2,3};
	int mat;
	char nome[25];
	//printf("1\n");
	Aluno a; //= cria_aluno("Aluno",123,nota);
	ArvBin *arvore = cria_ArvBin();
	FILE *f = fopen("alunos.txt","r");
	if(f){//!=NULL
		for(i=0;i<2287;i++)	{
			fscanf(f,"%d %s %d %d %d",&mat,nome,&nota[0],&nota[1],&nota[3]);
			a = cria_aluno(nome,mat,nota);
			insere_ArvBin(arvore,a);
			libera_aluno(a);
		}
	}
	else return 1;
	posOrdem_ArvBin(arvore);
	//printf("2\n");
	//print_aluno(a);
	//printf("3\n");
    return 0;
}
