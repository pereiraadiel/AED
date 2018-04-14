struct list{
	char vet[MAX][MAX];
	int fim;
};
lista *criar_lista(){
	lista * r;
	r = (lista*) malloc(sizeof(lista));
	return r;
}
int lista_vazia(lista *l){
	if(l==NULL) return 0;
	if(l->fim==0) return 1;
	return 0;
}
int lista_cheia(lista *l){
	if(l==NULL) return 0;
	if(l->fim>=MAX) return 1;
	return 0;
}
int insere_elem(lista *l,char *vet){
	if(l==NULL||lista_cheia(l)) return 0;
	strcpy(l->vet[l->fim++],vet);
	return 1;
}
int remove_elem(lista *l,char *vet){
	if(l==NULL) return 0;
	int i,j;
	for(i=0;i<l->fim;i++){
		if(strcmp(l->vet[i],vet)==0) break;
	}
	if(i==l->fim) return 0;
	for(j=i;j<l->fim;j++){
		strcpy(l->vet[j],"");
		strcpy(l->vet[j],l->vet[j+1]);
	}
	l->fim--;
	return 1;
}
void print_lista(lista *l){
	printf("Lista = {");
	for(int i=0;i<l->fim;i++){
		if(i<l->fim-1) printf("%s #",l->vet[i]);
		else printf("%s}",l->vet[i]);
	}
}
void menu(){
	system("clear");
	printf("=============================\n");
	printf("          Escolha\n");
	printf("[0] Sair\n");
	printf("[1] Add elemento\n");
	printf("[2] Remove elemento\n");
	printf("[3] Mostrar lista\n");
	printf(":");
}
int escolha(lista *l, int n){
	if(n==0) return 1;
	char str[MAX];
	switch(n){
		case 1: 
			printf("String: ");
			setbuf(stdin,NULL);
			scanf("%[^\n]s",str);
			if(insere_elem(l,str)) printf("Inserido!\n");
			else printf("Falha ao inserir!\n");
			return 300;
		break;
		case 2:
			printf("String: ");
			setbuf(stdin,0);
			scanf("%[^\n]s",str);
			if(remove_elem(l,str)) printf("Removido!\n");
			else printf("Falha ao remover!\n");
			return 300; 
		break; 
		case 3:
			print_lista(l);
			return 1000;
		break;
	}
	return 0;
}
void delay(int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<10000;j++);
	}
}	
