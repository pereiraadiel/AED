#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct encadeada Lista;
Lista *cria_lista();
int insere_elem(Lista **l, int elem);
int remove_elem(Lista **l, int elem);
int insere_elem_ord(Lista **l, int elem);
int remove_elem_ord(Lista **l, int elem);
int remove_tds_ocorrencias(Lista **l, int elem);
int lista_vazia(Lista *l);
void print_lista(Lista *l);
void apaga_lista(Lista *l);
void menu_intercala(Lista **l);


/* 	funcao intercala_ord() faz a fusão de duas listas
	de maneira tal que se obtenha uma ordenação
	dos elementos das duas lista em uma terceira*/
Lista * intercala_ord(Lista **A, Lista **B);

/* 	funcao delay() faz uma pequena parada no fluxo do 
	programa por um determinado tempo n medido em milissegundos*/
void delay(int n);

/*	similar a funcao system("pause") a funcao pause() para o 
	fluxo do programa ate que a tecla ENTER seja apertada */ 
void pause();