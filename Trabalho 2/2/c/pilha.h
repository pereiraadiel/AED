typedef struct no * Pilha;
Pilha cria_pilha();
int pilha_vazia(Pilha p);
int empilha(Pilha *p, int elem);
int desempilhar(Pilha *p, int * elem);
int topo(Pilha *p, int * elem);
void imprimir(Pilha *p);
int pares_impares(Pilha *base, Pilha *par, Pilha *impar);
void aguarde();
