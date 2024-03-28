#ifndef SESSAO_H
#define SESSAO_H
#include "acessorio.h"

typedef struct sessao Sessao;
typedef struct lista_sessao ListaSessao;


ListaSessao *criar_lista_sessao();
ListaSessao *adicionar_sessao(ListaSessao *lista);
void listar_sessoes(ListaSessao *lista);
ListaSessao *adicionar_acessorio_sessao(ListaSessao *lista);





/*
Sessao *criar_sessao();
Sessao *adicionar_sessao(Sessao *session);
void listar_sessoes(Sessao *session);
*/
#endif