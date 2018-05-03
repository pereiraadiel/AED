typedef struct lista Lista;
Lista * cria_lista();
int lista_vazia(Lista *l);
int insere_elem(Lista *l, int elem);
int remove_elem(Lista *l, int elem);
int tamanho(Lista *l);
void imprimi_lista(Lista *l);
void imprimi_tamanho(Lista *L);
void pause();