#include "acessorio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct acessorio{
    char nome[50];
    char tipo[20];
    float preco;
    int quantidade;
    Acessorio *proximo;
};

Acessorio *criar_acessorio(void){
    return NULL;
}

Acessorio *inserir_acessorio(Acessorio *a){
    char nome[50];
    char tipo[20];
    int quantidade;
    float preco;
    printf("Digite o nome do acessorio: ");
    scanf(" %[^\n]", nome);

    printf("Digite o tipo do acessorio JOIA ou BIJUTERIA: ");
    scanf(" %[^\n]", tipo);
    
    printf("Digite o preco do acessorio: ");
    scanf("%f", &preco);
    printf("Digite a quantidade do acessorio: ");
    scanf("%d", &quantidade);

    Acessorio *novo_acessorio = (Acessorio *) malloc(sizeof(Acessorio));
    if(novo_acessorio == NULL){
        printf("Erro ao alocar memoria\n");
        exit(1);
    }
    strcpy(novo_acessorio->nome, nome);
    strcpy(novo_acessorio->tipo, tipo);
    novo_acessorio->preco = preco;
    novo_acessorio->quantidade = quantidade;
    novo_acessorio->proximo = a;
    return novo_acessorio;
}