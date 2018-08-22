#include "lista.c"
#include "lista.h"
#include "lista_din.c"
#include "lista_din.h"
#include <time.h>

int main(int argc, char const *argv[])
{
	clock_t inicio,fim;
	unsigned long int tempo;
	int seed_max=0,i,Num = 100000;
	inicio=clock();

	lista *l,*m;
	l = cria_lista();
	Lista_din L = cria_lista_din();

	for(i=0;i<Num;i++)insere_elem_ini(l,1);

	fim = clock();
	tempo = (fim - inicio)*1000/CLOCKS_PER_SEC;
	printf("tempo insere_elem_ini (EST): %lu milissegundos\n",tempo);

	inicio = clock();
	for(i=0;i<Num;i++)insere_elem_fim(l,0);
	fim = clock();
	tempo = (fim - inicio)*1000/CLOCKS_PER_SEC;
	printf("tempo insere_elem_fim (EST):%lu milissegundos\n",tempo);

	inicio = clock();
	seed_max=l->fim;
	srand(time(NULL));
	for(i=0;i<Num;i++)pesquisa_pos(l,(int)rand()%seed_max);
	fim = clock();
	tempo = (fim - inicio)*1000/CLOCKS_PER_SEC;
	printf("tempo pesquisa_pos (EST): %lu milissegundos\n",tempo);
	
	//--------------------------

	inicio = clock();
	for(i=0;i<Num;i++)insere_elem_inicio(L,1);
	fim = clock();
	tempo = (fim - inicio)*1000/CLOCKS_PER_SEC;
	printf("tempo insere_elem_ini (DIN): %lu milissegundos\n",tempo);

	inicio = clock();
	for(i=0;i<Num;i++)insere_elem_fim(L,0);
	fim = clock();
	tempo = (fim - inicio)*1000/CLOCKS_PER_SEC;
	printf("tempo insere_elem_fim (DIN):%lu milissegundos\n",tempo);

	inicio = clock();
	seed_max=tamanho(L);
	srand(time(NULL));
	for(i=0;i<Num;i++)pesquisa_pos(L,(int)rand()%seed_max);
	fim = clock();
	tempo = (fim - inicio)*1000/CLOCKS_PER_SEC;
	printf("tempo pesquisa_pos (DIN): %lu milissegundos\n",tempo);
	return 0;
}