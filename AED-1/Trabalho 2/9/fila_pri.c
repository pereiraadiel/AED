#include <stdio.h>
#include <stdlib.h>
#include "fila_pri.h"

struct no{
    int info;
    struct no *prox;
};

struct Fila{
    struct no *ini, *fim;
};

fila cria_fila(){
    fila f=(fila)malloc(sizeof(struct Fila));
    if(f) f->ini=f->fim=NULL;
    return f;
}

int fila_vazia(fila f){
    return !f->ini;
}

int inserir(fila f, int elem){
    struct no *aux=(struct no *)malloc(sizeof(struct no));
    if(aux==NULL) return 0;
    aux->info=elem;
    if(fila_vazia(f)){
        f->ini=f->fim=aux;
        aux->prox=NULL;
        return 1;
    }
    if(elem<=f->ini->info){
        aux->prox=f->ini;
        f->ini=aux;
        return 1;
    }
    if(elem>=f->fim->info){
        f->fim->prox=aux;
        aux->prox=NULL;
        f->fim=aux;
        return 1;
    }
    struct no *aux2;
    for(aux2=f->ini;aux2->prox!=NULL &&
     aux2->prox->info<elem;aux2=aux2->prox);
    aux->prox=aux2->prox;
    aux2->prox=aux;
    return 1;
}

int remover(fila f, int *elem){
    if(fila_vazia(f)) return 0;
    struct no *aux=f->ini;
    *elem=aux->info;
    f->ini=aux->prox;
    free(aux);
    return 1;
}

void imprimir(fila f){
    if(fila_vazia(f)) {
    	printf("[FILA VAZIA]\n");
    	return;
    }
    printf("Fila: [");
    for(struct no *aux=f->ini;aux!=NULL;aux=aux->prox)
        printf("%d ", aux->info);
    printf("\b]\n");
    return;
}
void aguarde(){
	printf("Aperte ENTER para continuar...");
	char c;
	setbuf(stdin,NULL);
	while(c!=10) c=getchar();
}