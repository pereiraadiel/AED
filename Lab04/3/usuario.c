#include "lista.h"
#include "lista.c"
int main(int argc, char const *argv[])
{
	lista *l;
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
	printf("[4] Insere ordenado.\n");
	printf("[5] Remove ordenado\n");
	printf("[0] Sair\n");
	printf(": ");
	scanf("%d",&op);
	switch(op){
		case 0: apaga_lista(&l);break;
		case 1: 
			printf("Elemento: ");
			scanf("%d",&n);
			if(insere_elem(l,n)) printf("Sucesso!!\n");
			else printf("Falha!\n");
			delay(1);
			goto inicio;
		break;
		case 2: 
			printf("Elemento: ");
			scanf("%d",&n);
			if(remove_elem(l,n)) printf("Sucesso!!\n");
			else printf("Falha!\n");
			delay(1);
			goto inicio;
		break;
		case 3:
			print_lista(l);
			delay(8);
			goto inicio;
		break;
		case 4:
			printf("Elemento: ");
			scanf("%d",&n);
			if(insere_elem_ord(l,n)) printf("Sucesso!!\n");
			else printf("Falha!\n");
			delay(1);
			goto inicio;
		break;
		case 5: 
			printf("Elemento: ");
			scanf("%d",&n);
			if(remove_elem_ord(l,n)) printf("Sucesso!!\n");
			else printf("Falha!\n");
			delay(1);
			goto inicio;
		break;
		default: goto inicio; break;
	}
	return 0;
}