#include <stdlib.h>
int main(){
	system("gcc -c user.c");
	system("gcc -c lista.c");
	system("gcc user.c lista.c -o exec");
}