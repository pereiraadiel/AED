#include "cabecalho.h"
#include "racional.c"

int main(int argc, char const *argv[])
{
	Racional *R,*S,*T;
	R = generate();
	S = generate();
	T = generate();
	int n,d;
	printf("Digite um numero racional\n");
	printf("numerador:");
	scanf("%d",&n);	
	printf("denominador:");
	scanf("%d",&d);
	set_value(R,n,d);
	printf("Digite outro numero racional\n");
	printf("numerador:");
	scanf("%d",&n);	
	printf("denominador:");
	scanf("%d",&d);
	set_value(S,n,d);
	T = sum(R,S);
	delete(&R);
	delete(&S);
	print_value(T);
	delete(&T);	
	return 0;
}