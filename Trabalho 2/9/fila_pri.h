typedef struct no *Fila;
Fila cria_fila();
int fila_vazia(Fila *f);
int inserir(Fila *f, int elem,int pri);
int remover_menor_prioridade(Fila *f, int *elem);
int remover_maior_prioridade(Fila *f, int *elem);
int remover(Fila *f, int *elem, int tipo);
void imprimir(Fila *f);
void aguarde();
