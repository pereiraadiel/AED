#include <stdio.h>

int main(){
	char buffer;
	int i;
	i = fread(&buffer,1,1,stdin);
	while(i>0){
		fwrite(&buffer,1,1,stdout);
		i = fread(&buffer,1,1,stdin);
	}
}