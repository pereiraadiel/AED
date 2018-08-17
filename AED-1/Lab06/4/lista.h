#include <stdio.h>
#include <stdlib.h>
#define MAX 100

/* Definicao do tipo estruturado lista*/
typedef struct encadeada Lista;

/* Retorna um ponteiro para o TAD lista*/
Lista *cria_lista();

/* Insere um elemento no final da lista*/
int insere_elem(Lista **l, int elem);

/* Remove o primeiro elemento da lista que
   corresponder ao elemento a ser removido*/
int remove_elem(Lista **l, int elem);

/* Insere um elemento na lista de maneira ordenada*/
int insere_elem_ord(Lista **l, int elem);

/* Remove o primeiro elemento da lista que
   corresponder ao elemento a ser removido
   de modo que se mantenha a ordenaçao*/
int remove_elem_ord(Lista **l, int elem);

/* Remove todos os elementos da lista que 
   corresponderem ao elemento a ser removido*/
int remove_tds_ocorrencias(Lista **l, int elem);

/* Verifica se a lista esta vazia*/
int lista_vazia(Lista *l);

/* Exibi na tela todos os elementos da lista*/
void print_lista(Lista *l);

/* Libera o espaço usado na alocacao da lista*/
void apaga_lista(Lista **l);

/* Interface para a funcao intercala*/
void menu_intercala(Lista **l);

/* 	funcao intercala_ord() faz a fusão de duas listas
	de maneira tal que se obtenha uma ordenação
	dos elementos das duas lista em uma terceira*/
Lista * intercala_ord(Lista **A, Lista **B);

/*	similar a funcao system("pause") a funcao pause() para o 
	fluxo do programa ate que a tecla ENTER seja apertada */ 
void pause();