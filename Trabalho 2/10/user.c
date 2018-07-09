#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

int main(){
    int op=-1,elem,swt;
    deque d = cria_deque();
    while(1){
        printf("-----------------------\n");
        printf("        Escolha\n");
        printf("-----------------------\n");
        printf("[0] SAIR\n");
        printf("[1] Imprimir Deque\n");
        printf("[2] Inserir elemento\n");
        printf("[3] Remover elemento\n");
        printf("Opcao: ");
        scanf("%d",&op);
        if(op==0) break;
        switch(op){
            case 1: 
                imp_deque(d);
            break;
            case 2: 
                printf("[1] Inserir no Inicio\n");
                printf("[2] Inserir no Final\n");
                printf("Opcao:"); scanf("%d",&swt);
                printf("Elem:"); scanf("%d",&elem);
                if(swt==1) insere_ini(d,elem);
                else if(swt==2) insere_fim(d,elem);
            break;
            case 3: 
                printf("[1] Remover no Inicio\n");
                printf("[2] Remover no Final\n");
                printf("Opcao:"); scanf("%d",&swt);
                if(swt==1) remove_ini(d,&elem);
                else if(swt==2) remove_fim(d,&elem);
                printf("Elemento removido: %d\n",elem);
            break;
        }
        aguarde();
        system("cls");
    }
    return 0;
}
