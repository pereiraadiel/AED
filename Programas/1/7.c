#include <stdio.h>
#include <stdlib.h>

typedef struct Dados{
	int x;
	char nome[30];
}dados;

void manipula(dados *v, int n);
void manipula_par(int *x);
void aloca_struct(dados **v, int n);

int main(){
	int i,n;
	dados *v;
	printf("Quantos dados deseja inserir? ");
	scanf("%d", &n);
	aloca_struct(&v,n);
	setbuf(stdin,NULL);
	manipula(v,n);
	system("pause");
	return 0;
}

void manipula(dados *v, int n){
	int i;
	for(i=0;i<n;i++){
		printf("Digite um numero inteiro: ");
		scanf("%d", &v[i].x);
		setbuf(stdin,NULL);
		printf("Digite uma string: ");
		gets(v[i].nome);
		setbuf(stdin,NULL);
	}
	for(i=0;i<n;i++){
		if(v[i].x%2==0) manipula_par(&v[i].x);
	}
	for(i=0;i<n;i++){
		printf("v[%d]= %d\n", i, v[i].x);
	}
}

void manipula_par(int *x){
	*x/=2;
}

void aloca_struct(dados **v, int n){
	*v=(dados *)malloc(n*sizeof(dados));
}