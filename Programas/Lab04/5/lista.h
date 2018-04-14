#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct list lista;
lista *criar_lista();
int lista_vazia(lista *l);
int lista_cheia(lista *l);
int insere_elem(lista *l,char *vet);
int remove_elem(lista *l,char *vet);
void menu();
int escolha(lista *l,int n);
void delay(int n);
