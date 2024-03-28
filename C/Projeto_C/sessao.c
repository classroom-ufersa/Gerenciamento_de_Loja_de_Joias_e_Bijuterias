#include "sessao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "acessorio.h"

struct sessao{
    char nome[50];
    char descricao[100];
    Acessorio *acessorios;
    
};

struct lista_sessao{
    Sessao *sessao;
    ListaSessao *proximo;
};

ListaSessao *criar_lista_sessao(){
    ListaSessao *nova_lista = (ListaSessao *) malloc(sizeof(ListaSessao));
    nova_lista->sessao = NULL;
    nova_lista->proximo = NULL;
    return nova_lista;
}

ListaSessao *adicionar_sessao(ListaSessao *lista){
    ListaSessao *nova_lista = malloc(sizeof(ListaSessao));
    Sessao *nova_sessao = malloc(sizeof(Sessao));
    char descricao[100];
    char nome[50];
    printf("Digite o nome da sessao: ");    
    scanf(" %[^\n]", nome);
    printf("Digite a descricao da sessao: ");
    scanf(" %[^\n]", descricao);
    strcpy(nova_sessao->nome, nome);
    strcpy(nova_sessao->descricao, descricao);
    nova_lista->sessao = nova_sessao;
    nova_lista->proximo = lista;
    return nova_lista;
}

void listar_sessoes(ListaSessao *lista){
    if(lista == NULL){
        printf("Nao ha sessoes cadastradas\n");
        return;
    }
    ListaSessao *aux = lista;
    while(aux != NULL){
        printf("Nome: %s\n", aux->sessao->nome);
        printf("Descricao: %s\n", aux->sessao->descricao); 
        aux = aux->proximo;
    }
}







/*

Sessao *cria_sessao(){
    Sessao *nova_sessao = (Sessao *) malloc(sizeof(Sessao));
    nova_sessao->acessorios = NULL;
    nova_sessao->proximo = NULL;
    return nova_sessao;
}

Sessao *adicionar_sessao(Sessao *session){
    Sessao *nova_sessao = malloc(sizeof(Sessao));
    char descricao[100];
    char nome[50];
    printf("Digite o nome da sessao: ");    
    scanf(" %[^\n]", nome);
    printf("Digite a descricao da sessao: ");
    scanf(" %[^\n]", descricao);
    strcpy(nova_sessao->nome, nome);
    strcpy(nova_sessao->descricao, descricao);
    nova_sessao->acessorios = adicionar_acessorio(nova_sessao->acessorios);
    nova_sessao->proximo = session;
    return nova_sessao;
}

void listar_sessoes(Sessao *session){
    if(session == NULL){
        printf("Nao ha sessoes cadastradas\n");
        return;
    }
    Sessao *aux = session;
    while(aux != NULL){
        printf("Nome: %s\n", aux->nome);
        printf("Descricao: %s\n", aux->descricao); 
        aux = aux->proximo;
    }
}
*/