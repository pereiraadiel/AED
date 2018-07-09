#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(){
    int op=-1,elem;
    Pilha p,par,impar;
    while(1){
        printf("-----------------------\n");
        printf("        Escolha\n");
        printf("-----------------------\n");
        printf("[0] SAIR\n");
        printf("[1] Imprimir Pilha\n");
        printf("[2] Empilhar\n");
        printf("[3] Desempilhar\n");
        printf("[4] Elem do Topo\n");
        printf("[5] Par ou Impar\n");
        printf("Opcao: ");
        scanf("%d",&op);
        if(op==0) break;
        switch(op){
            case 1: 
                imprimir(&p);
            break;
            case 2: 
                printf("Elem:"); scanf("%d",&elem);
                empilha(&p,elem);
            break;
            case 3: 
                desempilhar(&p,&elem);
                printf("Elemento removido: %d\n",elem);
            break;
            case 4: 
                topo(&p,&elem);
                printf("Elemento no topo: %d\n",elem);
            break;
            case 5: 
                pares_impares(&p,&par,&impar);
                printf("Elementos pares: \n");
                imprimir(&par);
                printf("Elementos impares:\n");
                imprimir(&impar);
            break;
        }
        aguarde();
        system("clear");
    }
    return 0;
}
