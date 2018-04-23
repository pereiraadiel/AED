#include <stdlib.h>
#include <string.h>
int main(int argc, char const *argv[]){
	char vet[100] = {"git commit -m \""};
	char vet2[100] = {"git add "};
	if(argc>1){
		strcat(vet2,argv[1]);
		strcat(vet2,"\\");
		system(vet2);
		strcat(vet,argv[1]);
		strcat(vet,"\"");
		system(vet);
	}
	else {
		system("git commit -m \"Programas\"");
		system("git add Programas/");
	}
	system("git push -u origin master");
	return 0;
}