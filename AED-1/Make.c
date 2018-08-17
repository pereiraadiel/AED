#include <stdio.h>
#include <stdlib.h>
int main(){
	system("rm exec");
	system("gcc -c *.c");
	system("gcc *.o -o exec");
	return 0;
}