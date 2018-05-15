#include <stdio.h>
#include "lista.h"
#include "interface.h"

int main(){
	Lista *A = cria_lista();
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
							if(insere_ord(&A,elem)){
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
							if(remove_ord(&A,elem)){
								printf("Elemento removido com sucesso!\n");
							}
							else printf("Falha - Elemento nao removido!\n");
							pause();
						break;
					}
				}
			break;
			case 3: 
				if(remove_impares(&A)){
					printf("Numeros impares removidos com sucesso!!\n");
				}
				else printf("Falha - Nada foi removido\n");
				pause();
			break;
			case 4:
				m = menor(A);
				if(m!=0){
					printf("Menor elemento = %d\n", m-1); 
					pause();
				}
			break;
			case 5:
				printf("tamanho da lista = %d\n",tamanho(A));
				pause(); 
			break;
			case 6: 
				sub_menu_igualdade();
				scanf("%d",&sub_op);
				if(sub_op==0) break;
				int n_elem_igual;
				Lista *B_igual = cria_lista();
				
				switch(sub_op){
					case 1: 
						printf("Quantos elementos para lista B? ");
						scanf("%d",&n_elem_igual);
						while(n_elem_igual--){
							printf("Elemento:");
							scanf("%d",&elem);
							insere_ord(&B_igual,elem);
						}
					break;
					case 2: 
						//free(A);
						A = cria_lista();
						printf("Quantos elementos para lista A? ");
						scanf("%d",&n_elem_igual);
						while(n_elem_igual--){
							printf("Elemento:");
							scanf("%d",&elem);
							insere_ord(&A,elem);
						}
						printf("Quantos elementos para lista B? ");
						scanf("%d",&n_elem_igual);
						while(n_elem_igual--){
							printf("Elemento:");
							scanf("%d",&elem);
							insere_ord(&B_igual,elem);
						}
					break;
				}
				//printf("chamada da func concat\n");
				printf("Lista A: ");
				imprimi_lista(A);
				printf("Lista B: ");
				imprimi_lista(B_igual);
				if(iguais(A,B_igual)) printf("Listas iguais!!\n");
				else printf("Listas diferentes!!\n");
				fim_igual:
				pause();
			break;
			case 7:
				sub_menu_concatena();
				scanf("%d",&sub_op);
				if(sub_op==0) break;
				int n_elem;
				Lista *B = cria_lista();
				switch(sub_op){
					case 1: 
						printf("Quantos elementos para lista B? ");
						scanf("%d",&n_elem);
						while(n_elem--){
							printf("Elemento:");
							scanf("%d",&elem);
							insere_ord(&B,elem);
						}
					break;
					case 2: 
						//free(A);
						A = cria_lista();
						printf("Quantos elementos para lista A? ");
						scanf("%d",&n_elem);
						while(n_elem--){
							printf("Elemento:");
							scanf("%d",&elem);
							insere_ord(&A,elem);
						}
						printf("Quantos elementos para lista B? ");
						scanf("%d",&n_elem);
						while(n_elem--){
							printf("Elemento:");
							scanf("%d",&elem);
							insere_ord(&B,elem);
						}
					break;
				}
				//printf("chamada da func concat\n");
				A = concatenar(&A,&B);
				if(!lista_vazia(A)) printf("Sucesso!!\n");
				else printf("Falha!!\n");
				fim:
				pause();
			break;
			case 8: 
				imprimi_lista(A);
				pause();
			break;
		}
	}
}
