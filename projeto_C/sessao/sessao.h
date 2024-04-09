
#ifndef SESSAO_H
#define SESSAO_H
#include "../acessorio/acessorio.c"

typedef struct sessao Sessao;

Sessao *criar_sessao(void);

Sessao *inserir_sessao(Sessao *s);

void listar_sessoes(Sessao *inicio);

void adicionar_acessorio(Sessao *inicio, char nome_sessao[], Acessorio *novo_acessorio);

void remover_sessao(Sessao **inicio);

void remover_acessorio(Sessao *sessao);

void realizar_venda(Sessao *sessao);

void buscar_acessorio(Sessao *inicio);

void salvar_dados(Sessao *inicio);

Sessao *ler_dados_salvos();

#endif