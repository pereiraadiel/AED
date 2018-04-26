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
void delay(int n);
void pause();