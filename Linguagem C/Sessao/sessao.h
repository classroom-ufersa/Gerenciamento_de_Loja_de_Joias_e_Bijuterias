typedef struct sessao Sessao;

// Fun��o para criar uma nova sess�o.
Sessao *criar_sessao(Sessao *lista);

// EM PENDENCIA: Fun��o para adicionar um acess�rio a uma sess�o
//void adicionar_acessorio(Sessao *atual, Acessorio *novo);

// Fun��o para listar todas as sess�es
void listar_sessoes(Sessao *lista_sessoes);

// Fun��o para liberar a mem�ria alocada para uma sess�o.
void liberar_sessao(Sessao *sessao);
