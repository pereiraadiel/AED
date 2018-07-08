typedef struct no * Pilha;
Pilha cria_pilha();
int pilha_vazia(Pilha p);
int empilhar(Pilha *p, int elem);
int desempilhar(Pilha *p, int *elem);
void imprimir(Pilha *p);
int le_topo(Pilha *p, int *elem);
void imprimir_rev(Pilha *p);