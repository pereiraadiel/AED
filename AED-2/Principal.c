#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

int main(int argc, char const *argv[]){
	Grafo *gr;
	gr = criaGrafo(10,7,0);
	insereAresta(gr,0,1,0,0);
	insereAresta(gr,1,3,0,0);
	liberaGrafo(gr);
	return 0;
}