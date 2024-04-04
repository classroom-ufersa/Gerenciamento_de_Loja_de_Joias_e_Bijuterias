#include "funcoes.h"
#include "../sessao/sessao.h"
#include "../acessorio/acessorio.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void menu(){
    printf("[1] - Adicionar acessorio\n");
    printf("[2] - Remover acessorio\n");
    printf("[3] - Vender acessorio\n");
    printf("[4] - Buscar acessorio\n");
    printf("[5] - Adicionar nova sessao\n");
    printf("[6] - Remover sessao existente\n");
    printf("[7] - Listar sessoes e seus acessorios\n");
    printf("[8] - Sair\n");
}

// Função auxiliar para mesclar duas listas ordenadas
Sessao* merge(Sessao *a, Sessao *b) {
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    Sessao *resultado = NULL;

    if (strcmp(a->nome, b->nome) <= 0) {
        resultado = a;
        resultado->proximo = merge(a->proximo, b);
    } else {
        resultado = b;
        resultado->proximo = merge(a, b->proximo);
    }

    return resultado;
}

// Função para dividir a lista em duas partes
void split(Sessao *inicio, Sessao **a, Sessao **b) {
    Sessao *rapido;
    Sessao *lento;
    lento = inicio;
    rapido = inicio->proximo;

    while (rapido != NULL) {
        rapido = rapido->proximo;
        if (rapido != NULL) {
            lento = lento->proximo;
            rapido = rapido->proximo;
        }
    }

    *a = inicio;
    *b = lento->proximo;
    lento->proximo = NULL;
}

// Função principal de merge sort para a lista de sessões
void mergeSort(Sessao **head) {
    Sessao *inicio = *head;
    Sessao *a;
    Sessao *b;

    if (inicio == NULL || inicio->proximo == NULL)
        return;

    split(inicio, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *head = merge(a, b);
}