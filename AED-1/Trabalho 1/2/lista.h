#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#define MAX 1000
typedef struct lista Lista;
Lista * cria_lista();
int lista_vazia(Lista *l);
int lista_cheia(Lista *l);
int insere_ord(Lista *l, int elem);
int remove_ord(Lista *l, int elem);
void imprimi_lista(Lista *l);
int remove_todos(Lista *l,int elem);
int inserir_inicio(Lista *l, int elem);
int remove_pares(Lista *l);
int maior(Lista *l);
int tamanho(Lista *l);
int iguais(Lista *A, Lista *B);
Lista * concatenar(Lista *A, Lista *B);
void pause();

#endif //lista_h_included
