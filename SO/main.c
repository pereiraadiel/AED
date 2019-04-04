#include <stdio.h>

int main(){
	int i,buffer;
	for(buffer=1;buffer<1048577;buffer*=2){
		for(i=1;i<=10;i++){
			printf("-------------------------\n");
			printf("CHAMADA DE SISTEMA\n");
			printf("execucao %d para buffer=%d\n",i,buffer);
			system("sync; echo 3 > /proc/sys/vm/drop_caches");
			system("time ./syscall < datafile > /dev/null");

			printf("-------------------------\n");
			printf("CHAMADA DE BIBLIOTECA\n");
			printf("execucao %d para buffer=%d\n",i,buffer);
			system("sync; echo 3 > /proc/sys/vm/drop_caches");
			system("time ./libcall < datafile > /dev/null");
		}
	}
}