#include "lista.h"
struct lst{
	int vet[MAX];
	int fim;
};
lista * cria_lista(){
	lista *l;
	l = (lista*) malloc(sizeof(lista));
	if(l!= NULL) l->fim = 0;
	return l;
}
int apaga_lista(lista **l){
	free(*l);
	*l = NULL;
}
int lista_vazia(lista *l){
	if(l->fim==0)return 1;
	return 0;
}

int lista_cheia(lista *l){
	if(l->fim==MAX)return 1;
	return 0;
}
int insere_elem(lista *l,int n){
	int i;
	if(l==NULL||lista_cheia(l)) return 0;
	i = l->fim;
	l->vet[l->fim++]=n;
	if(l->fim>i) return 1;
	return 0;
}
int insere_elem_ord(lista *l,int n){
	if(l==NULL||lista_cheia(l)) return 0;
	int i,j;
	for(i=0;i<l->fim;i++){
		if(n<l->vet[i]) break;
	}
	if(i>l->fim-1){
		l->vet[i]=n;;
		l->fim++;
		return 1;
	}
	else{
		for(j=l->fim;j>i;j--){
			l->vet[j] = l->vet[j-1];
		}
		l->vet[i]=n;
		l->fim++;
		return 1;
	}
	return 0;
}
int remove_elem(lista *l,int n){
	if(l==NULL||lista_vazia(l)) return 0;
	int i,j;
	for(i=0;i<l->fim;i++){
		if(l->vet[i]==n){
			if(i==l->fim){
				l->fim--;
				return 1;
			}
			else{
				for(j=i;j<l->fim;j++){
					l->vet[j] = l->vet[j+1];
				}
				l->fim--;
				return 1;
			}
		}
	}
	return 0;
}
int remove_elem_ord(lista *l, int n){
	if(l==NULL||lista_vazia(l))return 0;
	int i,j;
	for(i=0;i<l->fim;i++){
		if(l->vet[i]==n){
			if(i==l->fim){
				l->fim--;
				return 1;
			}
			else{
				for(j=i;j<l->fim;j++){
					l->vet[j] = l->vet[j+1];
				}
				l->fim--;
				return 1;
			}
		}
	}
	return 0;
}
int remove_todos(lista *l,int n){
	if(l==NULL||lista_vazia(l)) return 0;
	
	int i=0,j,controle=l->fim;

	while(i<l->fim)
	{
		if(l->vet[i]==n){
			if(i==l->fim-1){
				l->fim--;
				return 1;
			}
			else{
				for(j=i;j<l->fim-1;j++){
					l->vet[j] = l->vet[j+1];
				}
				l->fim--;
			}
		}
		else i++;
	}
	if(l->fim<controle) return 1;
	return 0;
}
void print_lista(lista *l){
	int i=0;
	printf("Lista\n{");
	for(i=0;i<l->fim;i++){
		if(i<l->fim-1)printf("%d ",l->vet[i]);
		else printf("%d",l->vet[i]);
	}
	printf("}\n");
}
void delay(int n){
	for(int j=0;j<n;j++){
		for(int i=0;i<100000000;i++);
	}
} 
lista* menu_intercala(lista *c){
	int n,elem=0,num=0,i;
	lista *a,*b,*d;
	a = cria_lista();
	b = cria_lista();
	inicio:
	printf("========================\n");
	printf("        Intercalar\n");
	printf("------------------------\n");
	printf("[0] Sair.\n");
	printf("[1] Usar novas listas.\n");
	printf("[2] Usar lista anterior.\n");
	printf(":");
	scanf("%d",&n);
	switch(n){
		case 1: 
			if(a==NULL||b==NULL) return NULL;
			printf("Quantos elementos na lista 1? ");
			scanf("%d",&elem);
			for(i=0;i<elem;i++){
				printf("Elemento %d: ",i);
				scanf("%d",&num);
				insere_elem(a,num);
			}
			printf("Quantos elementos na lista 2? ");
			scanf("%d",&elem);
			for(i=0;i<elem;i++){
				printf("Elemento %d: ",i);
				scanf("%d",&num);
				insere_elem(b,num);
			}
			d = intercala_ord(a,b);
			apaga_lista(&a);
			apaga_lista(&b);
			return d;
		break;
		case 2: 
			if(c==NULL||b==NULL) return NULL;
			printf("Quantos elementos na lista 2? ");
			scanf("%d",&elem);
			for(i=0;i<elem;i++){
				printf("Elemento %d: ",i);
				scanf("%d",&num);
				insere_elem(b,num);
			}
			d = intercala_ord(b,c);
			apaga_lista(&b);
			apaga_lista(&c);
			return d;
		break;
		case 0: return NULL; break;
		default: goto inicio; break;
	}
	return 0;
}
lista * intercala_ord(lista *A, lista *B){
	lista *C;
	C = cria_lista();
	int i;
	for(i=0;i<A->fim;i++){
		insere_elem_ord(C,A->vet[i]);
	}
	for(i=0;i<B->fim;i++){
		insere_elem_ord(C,B->vet[i]);
	}
	return C;
}