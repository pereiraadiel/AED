void letra_E(Aluno A[3],int N){
	float maior=A[0].prova[0],menor=100.0,media_turma=0.0;
	int i,j,pos=0, pos_menor=0;
	for(j=0;j<3;j++){
		printf("\n----------------------------\n");
		printf("Maior nota na prova %d: \n",j+1);
		for(i=0;i<N;i++){
			if(A[i].prova[j]>maior){
				maior=A[i].prova[j];
				pos = i;
				media_turma+=A[i].prova[j];
			}
		}
		printf("Aluno: %s\nNota: %.2f\n",A[pos].nome,maior);
		maior = 0.0;
		media_turma/=N;
	}
	printf("\n--------------------------------\n");
	printf("Maior media geral:\n");
	maior=0.0;
	pos=0;
	for(i=0;i<N;i++){
		if(A[i].media>maior){
			maior = A[i].media;
			pos = i;
		}
		if(A[i].media<menor){
			menor = A[i].media;
			pos_menor = i;
		}
	}
	printf("Aluno: %s\nMedia: %.2f\n",A[pos].nome,maior);
	printf("\n-----------------------------------\n");
	printf("Menor Media geral:\n");
	printf("Aluno: %s\nMedia: %.2f\n",A[pos_menor].nome,menor);
	
	printf("\n-------------------------------------------------\n");
	printf("Media da turma: %.2f\n",media_turma);
	printf("Alunos com media maior igual a media da turma:\n");
	for(i=0;i<N;i++){
		if(A[i].media>=media_turma)printf("Aluno: %s\tMedia: %.2f\n",A[i].nome,A[i].media);
	}
}