typedef struct sessao Sessao;

// Função para criar uma nova sessão.
Sessao *criar_sessao(Sessao *lista);

// EM PENDENCIA: Função para adicionar um acessório a uma sessão
//void adicionar_acessorio(Sessao *atual, Acessorio *novo);

// Função para listar todas as sessões
void listar_sessoes(Sessao *lista_sessoes);

// Função para liberar a memória alocada para uma sessão.
void liberar_sessao(Sessao *sessao);
