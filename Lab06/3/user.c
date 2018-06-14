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
	printf("[3] Inserir Ordenado.\n");
	printf("[4] Remover ordenado.\n");
	printf("[5] Remover Tds Ocorrencias.\n");
	printf("[6] Mostrar lista.\n");
	printf("[0] Sair\n");
	printf(":");
	scanf("%d",&op);
	if(op==0){
		apaga_lista(l);
		//pause(); 
		return 0;
	}
	switch(op){
		case 1: 
			printf("Elemento: ");
			scanf("%d",&n);
			if(insere_elem(&l,n)) printf("Sucesso!!\n");
			else printf("Falha!\n");
			delay(500);
			//pause();
		break;
		case 2: 
			printf("Elemento: ");
			scanf("%d",&n);
			if(remove_elem(&l,n)) printf("Sucesso!!\n");
			else printf("Falha!\n");
			delay(500);
			//pause();
		break;
		case 3: 
			printf("Elemento: ");
			scanf("%d",&n);
			if(insere_elem_ord(&l,n)) printf("Sucesso!!\n");
			else printf("Falha!\n");
			delay(500);
			//pause();
		break;
		case 4: 
			printf("Elemento: ");
			scanf("%d",&n);
			if(remove_elem_ord(&l,n)) printf("Sucesso!!\n");
			else printf("Falha!\n");
			delay(500);
			//pause();
		break;
		case 5:
			printf("Elemento: ");
			scanf("%d",&n);
			if(remove_tds_ocorrencias(&l,n)) printf("Sucesso!!\n");
			else printf("Falha!\n");
			delay(500);
			//pause();
		break;
		case 6:
			print_lista(l);
			pause();
		break;
	}
	goto inicio;
}