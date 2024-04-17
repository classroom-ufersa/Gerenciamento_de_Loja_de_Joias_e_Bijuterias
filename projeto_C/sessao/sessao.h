#ifndef SESSAO_H
#define SESSAO_H
#include "../acessorio/acessorio.c"


// definição de um novo tipo de dado chamado Sessao
typedef struct sessao Sessao;

/*
* @brief Função para criar uma nova sessão
* @return Retorna um ponteiro para a nova sessão
* @return NULL caso não seja possível alocar memória
*/
Sessao *criar_sessao(void);

/*
* @brief Função para inserir uma nova sessão na lista de sessões
* @param s Ponteiro para a lista de sessões
* @return Retorna um ponteiro para a nova sessão
*/
Sessao *inserir_sessao(Sessao *s);

/*
* @brief Função para listar todas as sessões
* @param inicio Ponteiro para a lista de sessões
* @return void

*/
void listar_sessoes(Sessao *inicio);

/*
* @brief Função para adicionar um acessório a uma sessão
* @param inicio Ponteiro para a lista de sessões
* @param nome_sessao Nome da sessão que deseja adicionar o acessório
* @param novo_acessorio Ponteiro para o acessório que deseja adicionar
* @return void
*/
void adicionar_acessorio_sessao(Sessao *inicio, char nome_sessao[], Acessorio *novo_acessorio);

/*
* @brief Função para remover uma sessão da lista de sessões
* @param inicio Ponteiro para a lista de sessões
* @return void
*/
void remover_sessao(Sessao **inicio);

/*
* @brief Função para remover um acessório de uma sessão
* @param inicio Ponteiro para a lista de sessões
* @return void
*/
void remover_acessorio(Sessao *sessao);


/*
* @brief Função para realizar uma venda de um acessório
* @param inicio Ponteiro para a lista de sessões
* @return void
*/
void realizar_venda(Sessao *sessao);

/*
* @brief Função para buscar um acessório em uma sessão
* @param inicio Ponteiro para a lista de sessões
* @return void
*/
void buscar_acessorio(Sessao *inicio);


/*
* @brief Função para salvar os dados das sessões em um arquivo
* @param inicio Ponteiro para a lista de sessões
* @return void
*/
void salvar_dados(Sessao *inicio);


/*
* @brief Função para ler os dados das sessões de um arquivo
* @return Retorna um ponteiro para a lista de sessões
*/
Sessao *ler_dados_salvos();

#endif