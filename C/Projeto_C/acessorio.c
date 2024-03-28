#include "acessorio.h"
#include <stdio.h>
#include <stdlib.h>


struct acessorio{
    char nome[50];
    char tipo[20];
    float preco;
    int quantidade;

};

struct lista_acessorio{
    Acessorio *acessorio;
    ListaAcessorio *proximo;
};

ListaAcessorio *criar_lista_acessorio(){
    ListaAcessorio *nova_lista = (ListaAcessorio *) malloc(sizeof(ListaAcessorio));
    nova_lista->acessorio = NULL;
    nova_lista->proximo = NULL;
    return nova_lista;
}

ListaAcessorio *adicionar_acessorio(ListaAcessorio *lista){
    ListaAcessorio *nova_lista = malloc(sizeof(ListaAcessorio));
    Acessorio *novo_acessorio = malloc(sizeof(Acessorio));
    char nome[50];
    char tipo[20];
    printf("Digite o nome do acessorio: ");    
    scanf(" %[^\n]", nome);
    printf("Digite o tipo do acessorio: ");
    scanf(" %[^\n]", tipo);
    printf("Digite o preco do acessorio: ");
    scanf(" %f", &novo_acessorio->preco);
    printf("Digite a quantidade do acessorio: ");
    scanf(" %d", &novo_acessorio->quantidade);
    strcpy(novo_acessorio->nome, nome);
    strcpy(novo_acessorio->tipo, tipo);
    nova_lista->acessorio = novo_acessorio;
    nova_lista->proximo = lista;
    return nova_lista;
}

void lista_acessorio(ListaAcessorio *lista){
    if(lista == NULL){
        printf("Nao ha acessorios cadastrados\n");
        return;
    }
    ListaAcessorio *aux = lista;
    while(aux != NULL){
        printf("Nome: %s\n", aux->acessorio->nome);
        printf("Tipo: %s\n", aux->acessorio->tipo);
        printf("Preco: %.2f\n", aux->acessorio->preco);
        printf("Quantidade: %d\n", aux->acessorio->quantidade);
        aux = aux->proximo;
    }
}








/*
Acessorio *cria_acessorio(){
    Acessorio *novo_acessorio = (Acessorio *) malloc(sizeof(Acessorio));
    novo_acessorio->proximo = NULL;
    return novo_acessorio;
}

Acessorio *adicionar_acessorio(Acessorio *acessorio){
    Acessorio *novo_acessorio = malloc(sizeof(Acessorio));
    printf("Digite o nome do acessorio: ");    
    scanf(" %[^\n]", novo_acessorio->nome);

    printf("Digite o tipo do acessorio: ");
    scanf(" %[^\n]", novo_acessorio->tipo);

    printf("Digite o preco do acessorio: ");
    scanf(" %f", &novo_acessorio->preco);

    printf("Digite a quantidade do acessorio: ");
    scanf(" %d", &novo_acessorio->quantidade);
    if(novo_acessorio != NULL){
        novo_acessorio->proximo = acessorio;
        return novo_acessorio;
    }else{
        printf("Erro ao adicionar acessorio\n");
        return NULL;
    }

}
*/
