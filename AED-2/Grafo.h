typedef struct grafo Grafo;
Grafo * criaGrafo(int numero_vertices, int grau_MAX, int eh_ponderado);
void liberaGrafo(Grafo *gr);
int insereAresta(Grafo *gr, int origem, int destino,int eh_digrafo,float peso);