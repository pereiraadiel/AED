#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
typedef struct lst lista;
lista * cria_lista();
int lista_vazia(lista *l);
int lista_cheia(lista *l);
int insere_elem(lista *l,int n);
int remove_elem(lista *l,int n);
int remove_todos(lista *l,int n);
int apaga_lista(lista **l);
void delay(int n);