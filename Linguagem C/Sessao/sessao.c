#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Acessorio/acessorio.c"
#include "sessao.h"

struct sessao{
    char nome[50];
    Acessorio *acessorio;
    Sessao *prox;
};

Sessao *criar_sessao(Sessao *lista){
    char nome[50];
    Sessao *nova_sessao = (Sessao *)malloc(sizeof(Sessao));
    
    printf("Informe o nome da sessao: ");
    fgets(nome, 50, stdin);

    if (nova_sessao != NULL) {
        strcpy(nova_sessao->nome, nome);
        nova_sessao->acessorio = NULL;
        nova_sessao->prox = lista; 
        lista = nova_sessao; 
        printf("Sessao adicionada!\n");
    } else {
        printf("Erro ao criar sessao.\n");
    }
    return nova_sessao;
}

void listar_sessoes(Sessao *lista_sessoes){
    if (lista_sessoes == NULL) {
        printf("Nenhuma sessao cadastrada.\n");
        return;
    }

    Sessao *atual = lista_sessoes;
    printf("Lista de sessoes:\n");
    while (atual != NULL){
        printf("Nome: %s\n", atual->nome);
        atual = atual->prox;
    }
}

/*void adicionar_acessorio(Sessao *atual, Acessorio *novo){
    char nome_sessao[50];
    char nome_acessorio[50];

    printf("Digite o nome da sessao: ");
    fgets(nome_sessao, 50, stdin);
}
*/

void liberar_sessao(Sessao *sessao){
    if (sessao != NULL) {
        liberar_acessorios(sessao->acessorio);
        free(sessao);
    }
}