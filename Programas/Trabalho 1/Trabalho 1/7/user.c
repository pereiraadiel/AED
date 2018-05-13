#include <stdio.h>
#include "lista.h"
#include "interface.h"

int main(){
	Lista *A = cria_lista();
	Lista *list;
	int op,sub_op,elem,m;
	while(1){
		menu();

		scanf("%d",&op);
		if(op==0) break;
		switch(op){
			case 1: 
				while(1){
					sub_menu_inserir();
					scanf("%d",&sub_op);
					if(sub_op==0) break;
					switch(sub_op){
						case 1:
							printf("Elemento:");
							scanf("%d",&elem);
							if(insere_elem(A,elem)){
								printf("Elemento inserido com sucesso!\n");
							}
							else printf("Falha - Elemento nao inserido!\n");
							pause();
						break;
					}
				}
			break;
			case 2: 
				while(1){
					sub_menu_remover();
					scanf("%d",&sub_op);
					if(sub_op==0) break;
					switch(sub_op){
						case 1: 
							printf("Elemento:");
							scanf("%d",&elem);
							if(remove_elem(A,elem)){
								printf("Elemento removido com sucesso!\n");
							}
							else printf("Falha - Elemento nao removido!\n");
							pause();
						break;
						case 2: 
							printf("Elemento:");
							scanf("%d",&elem);
							if(remove_todos(A,elem)){
								printf("Elemento removido com sucesso!\n");
							}
							else printf("Falha - Elemento nao removido!\n");
							pause();
						break;
					}
				}
			break;
			case 3: 
				if(remove_maior(A)){
					printf("Maior elemento removido com sucesso!!\n");
				}
				else printf("Falha - Nada foi removido\n");
				pause();
			break;
			case 4:
				printf("chamando mult 3\n");
				list = multiplo_3(A);
				printf("chamando imprim\n");
				if(list) imprimi_lista(list);
				pause();
			break;
			case 5:
				printf("tamanho da lista = %d\n",tamanho(A));
				pause(); 
			break;
			case 6: 
				imprimi_lista(A);
				pause();
			break;
		}
	}
}
