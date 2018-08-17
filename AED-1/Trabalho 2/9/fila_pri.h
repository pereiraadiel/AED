typedef struct Fila *fila;
fila cria_fila();
int fila_vazia(fila f);
int inserir(fila f, int elem);
int remover(fila f, int *elem);
void imprimir(fila f);
void aguarde();
