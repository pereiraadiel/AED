#define FALSE 0
#define TRUE 1

typedef struct grafo Grafo;

Grafo * criar_grafo(int num_vertices, int grau_maximo, int eh_ponderado);

void liberar_grafo(Grafo *grafo);

int inserir_aresta(Grafo *grafo, int origem, int destino, int eh_digrafo, float peso);