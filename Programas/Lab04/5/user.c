#include "lista.h"
#include "lista.c"
int main(){
	int n,m;
	lista *l;
	l = criar_lista();
	inicio:
	menu();
	scanf("%d",&n);
	m=escolha(&l,n);
	if(!m) return 0;
	else{
		delay(m);
		goto inicio;
	}
}
