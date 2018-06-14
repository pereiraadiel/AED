#ifndef LISTA_H
#define LISTA_H
	typedef struct no *Lista;
	Lista cria_lista();
	int lista_vazia(Lista L);
	int insere_elem(Lista *L, int elem);
	int remove_elem(Lista *L, int elem);
	void imprime_lista(Lista L);
	void pause();
	int tamanho(Lista L);
#endif