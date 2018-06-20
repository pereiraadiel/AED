#define MAX 50
typedef struct fila *Fila;
Fila cria_fila();
int fila_vazia(Fila f);
int fila_cheia(Fila f);
int inserir(Fila f, int elem);
int remover(Fila f, int *elem);
void imprimir(Fila f);