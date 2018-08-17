#include <stdio.h> 
#include <string.h>

typedef struct{
	int matricula,faltas,situacao;
	float prova[3],media;
	char nome[16];
}Aluno;

int main(int argc, char const *argv[])
{
	Aluno a[3];
	char nomes[3][25]={"Adiel Pereira","Adiel Prado","Pereira Prado"};
	float notas[3][3]={7.0,5.2,8.3,4.5,9.6,7.8,6.7,5.5,3.1};
	int i,j,faltas[3] = {0,5,3},situacao[3]={0,1,2};
	for(i=0;i<3;i++){
		strcpy(a[i].nome,nomes[i]);
		for(j=0;j<3;j++){
			a[i].prova[j]=notas[i][j];
		}
		a[i].faltas=faltas[i];
	}
	for(i=0;i<3;i++){
		a[i].media = (a[i].prova[0]+a[i].prova[1]+a[i].prova[2])/3.0;
	}
	return 0;
}