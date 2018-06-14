#include "libs.h"
#include "cadastrar.c"
#include "medias.c"
#include "imprimir.c"
int main(int argc, char const *argv[])
{
	int n,i,j,num;
	printf("Numero de alunos a serem cadastrados: ");
	scanf("%d",&n);
	Aluno *a;
	a = (Aluno *) malloc(n*sizeof(Aluno));
	cadastrar(n,a);
	for(i=0;i<n;i++){
		a[i].media = Media(a[i]);
		a[i].situacao= Situacao(a[i]);
	}
	char op;
	do{
		impressao:
		imprimir_dados(a,n);
		letra_E(a,n);
		printf("Editar aluno? (Y/n): ");
		__fpurge(stdin);
		scanf("%c",&op);
		if(op=='Y'||op=='y'){
			mat:
			printf("Matricula: ");
			scanf("%d",&num);
			for(i=0;i<n;i++){
				if(a[i].matricula==num) break;
			}
			if(i>n){
				printf("Matricula invalida!\n");
				goto mat; 
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
	free(a);
	return 0;
}

float Media(Aluno A){
	return (A.prova[0]+A.prova[1]+A.prova[2])/3.0;
}