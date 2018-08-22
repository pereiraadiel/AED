#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	clock_T inicio,fim;
	unsigned long int tempo;
	inicio=clock();
	/*Code Here*/
	fim = clock();
	tempo = (fim - inicio)*1000/CLOCKS_PER_SEC;
	printf("tempo: %lu milissegundos\n",tempo);
	return 0;
}