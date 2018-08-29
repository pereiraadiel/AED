#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fib(int num){
	int i=0,a=1,b=0,ret=0;
	for(i=0;i<num-1;i++){
		ret = a + b;
		b = a;
		a = ret;
	}
	return ret;
}
int fib_rec(int num){
	if(num==0) return 0;
	if(num==1) return 1;
	return (fib_rec(num -1) + fib_rec(num -2));
}

int recorrencia(int num){
	int ret,i,c;

}
int recorrencia_rec(int num){
	if(num == 0) return 1;
	return (2/num)*(recorrencia_rec(num-1)+num);
}

int main(int argc, char const *argv[]){
	clock_t inicio,fim;
	unsigned long int tempo;
	int num,res;

	printf("digite o numero da sequencia de fibonacci desejado:");
	scanf("%d",&num);

	inicio=clock();
		res = fib_rec(num);
	fim=clock();
	tempo = (fim - inicio)*1000/CLOCKS_PER_SEC;
	FILE *f = fopen("tempo.txt","a");
	if(f){
		fprintf(f, "Recursivo: %lu\n",tempo );
		fclose(f);
	}
	//printf("Resultado: %d\n",res);

	inicio=clock();
		res = fib(num);
	fim=clock();
	tempo = (fim - inicio)*1000/CLOCKS_PER_SEC;
	f = fopen("tempo.txt","a");
	if(f){
		fprintf(f, "Com laco: %lu\n",tempo );
		fclose(f);
	}
	//printf("Resultado: %d\n",res);


	//-------------

	inicio=clock();
		res = recorrencia_rec(num);
	fim=clock();
	tempo = (fim - inicio)*1000/CLOCKS_PER_SEC;
	f = fopen("recorrencia.txt","a");
	if(f){
		fprintf(f, "Recursivo: %lu\n",tempo );
		fclose(f);
	}
	printf("Recorrencia recursiva: %d\n",res);
	return 0;
}