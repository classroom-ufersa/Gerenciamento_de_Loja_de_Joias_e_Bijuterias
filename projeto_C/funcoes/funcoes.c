#include "funcoes.h"
#include "../sessao/sessao.c"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

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

int botao_voltar(){
    int opcao;
    do{
    printf("[1] - Voltar\n");
    printf("[2] - Proseguir\n");
    scanf("%d", &opcao);
    }while(opcao != 1 && opcao != 2);
    
    return opcao;
}

void pressione_enter(){
    printf("Pressione ENTER para continuar...");
    while(getchar() != '\n');
    getchar();
}

void limpar_tela(){
    printf("carregando...\n");
    sleep(2);
    system("cls");
}

int numero_inteiroc(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

int contem_apenas_letras(char *str) {
    for (int index = 0; str[index] != '\0'; index++) {
        if (!isalpha(str[index]) && str[index] != ' ') {
            printf("Esse campo deve conter apenas letras.\n");
            limpar_tela();
            return 0;
        }
    }
    return 1;
}

void formata_string(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (i==0){
            str[0] = toupper(str[0]);
        }
        else{
            if (str[i - 1] == ' ') {
                str[i] = toupper(str[i]);
            } 
            else {
                str[i] = tolower(str[i]);
            }
        }
    }
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