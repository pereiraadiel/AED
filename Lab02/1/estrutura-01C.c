#include <stdio.h> 
#include <string.h>

typedef struct{
	int matricula,faltas,situacao;
	float prova[3],media;
	char nome[16];
}Aluno;

float Media(Aluno A);
int situacao(Aluno A);
void aprovacao(Aluno A[3]);

int main(int argc, char const *argv[])
{
	Aluno a[3];
	char nomes[3][25]={"Adiel Pereira","Adiel Prado","Pereira Prado"};
	float notas[3][3]={70.0,50.2,80.3,40.5,90.6,70.8,60.7,50.5,30.1};
	int i,j,faltas[3] = {0,5,3},situacao[3]={0,1,2};
	for(i=0;i<3;i++){
		strcpy(a[i].nome,nomes[i]);
		for(j=0;j<3;j++){
			a[i].prova[j]=notas[i][j];
		}
		a[i].faltas=faltas[i];
	}
	for(i=0;i<3;i++){
		a[i].media = Media(a[i]);
	}
	aprovacao(a);
	return 0;
}

float Media(Aluno A){
	return (A.prova[0]+A.prova[1]+A.prova[2])/3.0;
}

int situacao(Aluno A){
	if(A.media>=60.0 && A.faltas<=(72*25)/100) return 1;
	else if(A.faltas>(72*25)/100) return 0;
	else return 2;
}

void aprovacao(Aluno A[3]){
	for(int i=0;i<3;i++){
		switch(situacao(A[i])){
			case 0: printf("Reprovado por falta!\n"); break;
			case 1: printf("Aprovado!\n"); break;
			case 2: printf("Reprovado por nota!\n"); break;
		}
	}
}