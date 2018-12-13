#define FALSE 0
#define TRUE 1

typedef struct grafo Grafo;

Grafo * criar_grafo(int TAM);

void liberar_grafo(Grafo *grafo);

int inserir_aresta(Grafo *grafo, int origem , int destino, int eh_digrafo);