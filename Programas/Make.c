#include <stdio.h>
#include <stdlib.h>
int main(){
	system("rm exec");
	system("gcc -c lista.c");
	system("gcc -c user.c");
	system("gcc user.c lista.c -o exec");
	return 0;
}