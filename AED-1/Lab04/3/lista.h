#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
typedef struct lsta lista;
lista * cria_lista();
int lista_vazia(lista *l);
int lista_cheia(lista *l);
int insere_elem(lista *l,int n);
int insere_elem_ord(lista *l,int n);
int remove_elem(lista *l,int n);
int remove_elem_ord(lista *l, int n);
int apaga_lista(lista **l);
void delay(int n);