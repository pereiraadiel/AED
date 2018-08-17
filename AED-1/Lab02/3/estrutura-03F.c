#include <stdio.h> 
#include <stdio_ext.h>
#include <string.h>

typedef struct{
	int matricula,faltas,situacao;
	float prova[3],media;
	char nome[16];
}Aluno;

float Media(Aluno A);
int Situacao(Aluno A);
void aprovacao(Aluno A);
void imprimir_dados(Aluno A[3]);
void letra_E(Aluno A[3]);

int main(int argc, char const *argv[])
{
	Aluno a[3];
	char op,nomes[3][25]={"Adiel Pereira","Adiel Prado","Pereira Prado"};
	float notas[3][3]={70.0,50.2,80.3,40.5,90.6,70.8,60.7,50.5,30.1};
	int i,j,faltas[3] = {21,5,3},situacao[3]={0,1,2},num=0;
	int matricula[3]={1008,1009,1010};
	for(i=0;i<3;i++){
		strcpy(a[i].nome,nomes[i]);
		for(j=0;j<3;j++){
			a[i].prova[j]=notas[i][j];
		}
		a[i].faltas=faltas[i];
		a[i].matricula=matricula[i];
	}
	for(i=0;i<3;i++){
		a[i].media = Media(a[i]);
	}
	do{
		impressao:
		imprimir_dados(a);
		letra_E(a);
		printf("Editar aluno? (Y/n): ");
		__fpurge(stdin);
		scanf("%c",&op);
		if(op=='Y'||op=='y'){
			printf("Matricula: ");
			scanf("%d",&num);
			for(i=0;i<3;i++){
				if(a[i].matricula==num) break;
			}

			for(j=0;j<3;j++){ //notas
				printf("Nota da prova %d: ",j+1);
				scanf("%f",&a[i].prova[j]);
			}
			for(i=0;i<3;i++){
				a[i].media = Media(a[i]);
				a[i].situacao=Situacao(a[i]);
			}
			goto impressao;
		}
	}while(op=='Y'||op=='y');
	return 0;
}

float Media(Aluno A){
	return (A.prova[0]+A.prova[1]+A.prova[2])/3.0;
}

int Situacao(Aluno A){
	if(A.media>=60.0 && A.faltas<=(72*25)/100) return 1;
	else if(A.faltas>(72*25)/100) return 0;
	else return 2;
}

void aprovacao(Aluno A){
	switch(Situacao(A)){
		case 0: printf("Reprovado por falta!\n"); break;
		case 1: printf("Aprovado!\n"); break;
		case 2: printf("Reprovado por nota!\n"); break;
	}
}

void imprimir_dados(Aluno A[3]){
	for(int i=0;i<3;i++){
		printf("-----------------------\n");
		printf("Aluno = %s\n",A[i].nome);
		printf("Media = %.2f\n", Media(A[i]));
		printf("Faltas = %d\n", A[i].faltas);
		aprovacao(A[i]);
	}
}

void letra_E(Aluno A[3]){
	float maior=A[0].prova[0],menor=100.0,media_turma=0.0;
	int i,j,pos=0, pos_menor=0;
	for(j=0;j<3;j++){
		printf("\n----------------------------\n");
		printf("Maior nota na prova %d: \n",j+1);
		for(i=0;i<3;i++){
			if(A[i].prova[j]>maior){
				maior=A[i].prova[j];
				pos = i;
				media_turma+=A[i].prova[j];
			}
		}
		printf("Aluno: %s\nNota: %.2f\n",A[pos].nome,maior);
		maior = 0.0;
		media_turma/=3.0;
	}
	printf("\n--------------------------------\n");
	printf("Maior media geral:\n");
	maior=0.0;
	pos=0;
	for(i=0;i<3;i++){
		if(A[i].media>maior){
			maior = A[i].media;
			pos = i;
		}
		if(A[i].media<menor){
			menor = A[i].media;
			pos_menor = i;
		}
	}
	printf("Aluno: %s\nMedia: %.2f\n",A[pos].nome,maior);
	printf("\n-----------------------------------\n");
	printf("Menor Media geral:\n");
	printf("Aluno: %s\nMedia: %.2f\n",A[pos_menor].nome,menor);
	
	printf("\n-------------------------------------------------\n");
	printf("Media da turma: %.2f\n",media_turma);
	printf("Alunos com media maior igual a media da turma:\n");
	for(i=0;i<3;i++){
		if(A[i].media>=media_turma)printf("Aluno: %s\tMedia: %.2f\n",A[i].nome,A[i].media);
	}
}
