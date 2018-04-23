#include "lista.h"
int main(int argc, char const *argv[])
{
	Lista *l;
	l = cria_lista();
	int op,n;
	inicio:
	system("clear");
	printf("------------------------\n");
	printf("        Escolha\n");
	printf("------------------------\n");
	printf("[1] Inserir elemento.\n");
	printf("[2] Remover elemento.\n");
	printf("[3] Mostrar lista.\n");
	printf("[0] Sair\n");
	printf(": ");
	scanf("%d",&op);
	if(op==0){
		apaga_lista(l); 
		return 0;
	}
	switch(op){
		case 1: 
			printf("Elemento: ");
			scanf("%d",&n);
			if(insere_elem(l,n)) printf("Sucesso!!\n");
			else printf("Falha!\n");
			delay(500);
		break;
		case 2: 
			printf("Elemento: ");
			scanf("%d",&n);
			if(remove_elem(l,n)) printf("Sucesso!!\n");
			else printf("Falha!\n");
			delay(500);
		break;
		case 3:
			print_lista(l);
			delay(800);
		break;
	}
	goto inicio;
}