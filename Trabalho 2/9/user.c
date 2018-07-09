#include <stdio.h>
#include <stdlib.h>
#include "fila_pri.h"

int main(){
    int op=-1,elem,pri;
    Fila f;
    while(1){
        printf("-----------------------\n");
        printf("        Escolha\n");
        printf("-----------------------\n");
        printf("[0] SAIR\n");
        printf("[1] Imprimir Fila\n");
        printf("[2] Inserir elemento\n");
        printf("[3] Remover elemento\n");
        printf("Opcao: ");
        scanf("%d",&op);
        if(op==0) break;
        switch(op){
            case 1: 
                imprimir(&f);
            break;
            case 2: 
                printf("Elem:"); scanf("%d",&elem);
                printf("Prioridade:"); scanf("%d",&pri);
                inserir(&f,elem,pri);
            break;
            case 3: 
                printf("[1] Maior prioridade\n");
                printf("[2] Menor prioridade\n");
                printf("Opcao;"); scanf("%d",&pri);
                remover(&f,&elem,pri);
                printf("Elemento removido: %d\n",elem);
            break;
        }
        aguarde();
        system("clear");
    }
    return 0;
}
