#include "lista.h"
int main(int argc, char const *argv[])
{
	Lista *l;
	l = cria_lista();
	int op;
	char s[MAX];
	inicio:
	system("clear");
	printf("------------------------\n");
	printf("        Escolha\n");
	printf("------------------------\n");
	printf("[1] Inserir elemento.\n");
	printf("[2] Remover elemento.\n");
	printf("[3] Mostrar lista.\n");
	printf("[4] Inserir ordenado.\n");
	printf("[0] Sair\n");
	printf(": ");
	scanf("%d",&op);
	switch(op){
		case 0: apaga_lista(&l);break;
		case 1: 
			printf("String: ");
			setbuf(stdin,NULL);
			scanf("%[^\n]s",s);
			if(insere_elem(l,s)) printf("Sucesso!!\n");
			else printf("Falha!\n");
			delay(1);
			goto inicio;
		break;
		case 2: 
			printf("String: ");
			setbuf(stdin,NULL);
			scanf("%[^\n]s",s);
			if(remove_elem(l,s)) printf("Sucesso!!\n");
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
			printf("String: ");
			setbuf(stdin,NULL);
			scanf("%[^\n]s",s);
			if(insere_elem_ord(l,s)) printf("Sucesso!!\n");
			else printf("Falha!\n");
			delay(1);
			goto inicio;
		break;
		default: goto inicio; break;
	}
	return 0;
}