#include <stdio.h>
#include "lista.h"
#include "interface.h"

int main(){
	Lista *A = cria_lista();
	int op,sub_op,elem,m,posicao;
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
							if(insere_inicio(&A,elem)){
								printf("Elemento inserido com sucesso!\n");
							}
							else printf("Falha - Elemento nao inserido!\n");
							pause();
						break;
						case 2: 
							printf("Elemento:");
							scanf("%d",&elem);
							if(insere_elem(A,elem)){
								printf("Elemento inserido com sucesso!\n");
							}
							else printf("Falha - Elemento nao inserido!\n");
							pause();
						break;
						case 3: 
							printf("Elemento:");
							scanf("%d",&elem);
							printf("Posicao:");
							scanf("%d",&posicao);
							if(insere_posicao(A,elem,posicao)){
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
							if(remove_elem(&A,elem)){
								printf("Elemento removido com sucesso!\n");
							}
							else printf("Falha - Elemento nao removido!\n");
							pause();
						break;
						case 2: 
							printf("Posicao:");
							scanf("%d",&posicao);
							if(remove_posicao(&A,posicao)){
								printf("Elemento removido com sucesso!\n");
							}
							else printf("Falha - Elemento nao removido!\n");
							pause();
						break;
					}
				}
			break;
			case 3:
				m = maior(A);
				if(m!=0){
					printf("Maior elemento = %d\n", m-1); 
					pause();
				}
			break;
			case 4:
				printf("tamanho da lista = %d\n",tamanho(A));
				pause(); 
			break;
			case 5: 
				imprimi_lista(A);
				pause();
			break;
		}
	}
}
