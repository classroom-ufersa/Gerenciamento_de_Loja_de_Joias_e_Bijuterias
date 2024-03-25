#include <stdio.h>
#include <stdlib.h>
#include "acessorio.h"

struct acessorio{
    char nome[50];
    char tipo[50];
    int quantidade;
    float valor;
    struct acessorio *prox;
};

Acessorio *criar_acessorio(Acessorio *lista){
    char nome[50], tipo[50];
    int quantidade = 0;
    float valor = 0.0;

    Acessorio *novo_acessorio = (Acessorio *)malloc(sizeof(Acessorio));

    printf("Informe o nome: ");
    scanf(" %[^\n]", nome);
    printf("Infome o tipo: ");
    scanf(" %[^\n]", tipo);
    printf("Informe a quantidade de itens: ");
    scanf(" %d", &quantidade);
    printf("Informe o valor: R$");
    scanf(" %f", &valor);
    printf("Acessorio adicionado!\n");

    if (novo_acessorio != NULL) {
        strcpy(novo_acessorio->nome, nome);
        strcpy(novo_acessorio->tipo, tipo);
        novo_acessorio->quantidade = quantidade;
        novo_acessorio->valor = valor;
        novo_acessorio->prox = lista;
        lista = novo_acessorio;
    }
    return novo_acessorio;
}

void listar_acessorios(Acessorio *acessorio) {
    printf("Lista de acessorios cadastrados:\n");
    Acessorio *atual = acessorio;
    while (atual != NULL) {
        printf("Nome: %s\n", atual->nome);
        printf("Tipo: %s\n", atual->tipo);
        printf("Quantidade: %d\n", atual->quantidade);
        printf("Valor: %.2f\n\n", atual->valor);
        atual = atual->prox;
    }
}

void liberar_acessorios(Acessorio *acessorio){
    Acessorio *atual = acessorio;
    while (atual != NULL) {
        Acessorio *prox_acessorio = atual->prox;
        free(atual);
        atual = prox_acessorio;
    }
}
