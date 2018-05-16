typedef struct no *Lista;

int lista_vazia(Lista L);
Lista cria_lista(void);
int insere_final(Lista *A, int elem);
int remove_inicio(Lista *A,int *a);
void imprimi_lista(Lista l);
Lista ordenacao_radix(Lista A);
int tamanho(Lista L);
void imprimi_tamanho(Lista L);
void pause();