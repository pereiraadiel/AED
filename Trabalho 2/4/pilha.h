#define char* String
#define MAX 100
typedef struct no *Pilha;
Pilha cria_pilha();
int pilha_vazia(Pilha p);
int insere_elem(Pilha p, int elem);
int remove_elem(Pilha p, int *elem);
void imprimir(Pilha p);
void converter_posfixa(String str, int formato);
void imprimir_valor_expressao(String str);
double calcular_expressao(str);
