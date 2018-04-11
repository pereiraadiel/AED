void cadastrar(int N, Aluno *A){
	for(int i=0;i<N;i++){
		__fpurge(stdin);
		printf("Nome do aluno %d: ",i+1);
		scanf("%29[^\n]s",A[i].nome);
		printf("Matricula do aluno: ");
		scanf("%d",&A[i].matricula);
		printf("Faltas do aluno: ");
		scanf("%d",&A[i].faltas);
		for(int j=0;j<3;j++){
			printf("Nota da prova %d: ", j+1);
			scanf("%f",&A[i].prova[j]);
		}
	}
	printf("\nExito - Alunos cadastrados!\n\n");
}