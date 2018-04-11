int Situacao(Aluno A){
	if(A.media>=60.0 && A.faltas<=(72*25)/100) return 1;
	else if(A.faltas>(72*25)/100) return 0;
	else return 2;
}

void aprovacao(Aluno A){
	switch(Situacao(A)){
		case 0: printf("Reprovado por falta!\n"); break;
		case 1: printf("Aprovado!\n"); break;
		case 2: printf("Reprovado por nota!\n"); break;
	}
}

void imprimir_dados(Aluno A[3],int N){
	for(int i=0;i<N;i++){
		printf("-----------------------\n");
		printf("Aluno = %s\n",A[i].nome);
		printf("Media = %.2f\n", Media(A[i]));
		printf("Faltas = %d\n", A[i].faltas);
		aprovacao(A[i]);
	}
}

