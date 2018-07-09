typedef struct Deque *deque;

deque cria_deque();
int deque_vazia(deque d);
int insere_ini(deque d, int elem);
int insere_fim(deque d, int elem);
int remove_ini(deque d, int *elem);
int remove_fim(deque d, int *elem);
int imp_deque(deque d);
void aguarde();