typedef struct aluno *Aluno;
Aluno cria_aluno(char *nome,int mat, int notas[3]);
void libera_aluno(Aluno a);
void print_aluno(Aluno a);