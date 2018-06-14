#ifndef LISTA_H
#define LISTA_H
	typedef struct no Lista;
	Lista * cria_lista();
	int lista_vazia(Lista *l);
	int insere_ord(Lista **l, int elem);
	int remove_ord(Lista **l, int elem);
	void imprimi_lista(Lista *l);
	Lista * concatenar(Lista **A, Lista **B);
	int tamanho(Lista *L);
	int iguais(Lista *A, Lista *B);
	int remove_impares(Lista **A);
	int menor(Lista *A);
	void pause();
#endif