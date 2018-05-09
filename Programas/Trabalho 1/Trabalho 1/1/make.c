#include <stdlib.h>
int main(){
	system("rm executavel");
	system("gcc -c interface.c lista.c user.c");
	system("gcc -o executavel interface.o lista.o user.o");
	return 0;
}