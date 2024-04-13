#include "funcoes.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

void menu(){
    printf("=-=-=-=-=-=-=-= MENU =-=-=-=-=-=-=-=-=-=\n");
    printf("[1] - Adicionar acessorio\n");
    printf("[2] - Remover acessorio\n");
    printf("[3] - Vender acessorio\n");
    printf("[4] - Buscar acessorio\n");
    printf("[5] - Adicionar nova sessao\n");
    printf("[6] - Remover sessao existente\n");
    printf("[7] - Listar sessoes e seus acessorios\n");
    printf("[8] - Sair\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}

char botao_voltar(){
    char opcao;
    printf("[1] - Voltar, qualquer tecla para continuar: ");
    scanf(" %c", &opcao);
    limpar_tela();
    return opcao;
}

int valida_opcao() {
    char opcao[10];
    printf("Digite a opcao desejada: ");
    scanf("%s", opcao);

    for (int i = 0; opcao[i] != '\0'; i++) {
        if (!isdigit(opcao[i])) {
            printf("Opcao invalida. Digite um numero correspondente com as opcoes do menu.\n");
            return -1;
        }
    }

    int escolha = atoi(opcao);
    return escolha;
}

void pressione_enter(){
    printf("Pressione ENTER para continuar...");
    while(getchar() != '\n');
    getchar();
    system("cls");
}

int numero_inteiroc() {
    char formata_numero[10];
    int contador;
    do{
        contador = 0;
        printf("Digite a quantidade: ");
        scanf("%s", formata_numero);
        getchar();
        for (int i = 0; formata_numero[i] != '\0'; i++) {
            if (!isdigit(formata_numero[i])) {
                printf("Esse campo deve conter apenas numeros.\n");
                sleep(1);
                contador++;
                break;
            }

        }
        
    }while((contador != 0));
    
    int numero = atoi(formata_numero);
    return numero;
}

float numero_floatc() {
    char formata_numero[20];
    int contador;
    do {
        contador = 0;
        printf("Digite o preco do acessorio: ");
        scanf("%s", formata_numero);
        getchar();
        for (int i = 0; formata_numero[i] != '\0'; i++) {
            if (!isdigit(formata_numero[i]) && formata_numero[i] != '.' && formata_numero[i] != '-') {
                printf("Esse campo deve conter apenas números.\n");
                sleep(1);
                contador++;
                break;
            }
        }
    } while (contador != 0);

    float numero = atof(formata_numero);
    return numero;
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

void maiusculo_string(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

void limpar_tela(){
    printf("pera ai...\n");
    sleep(1);
    system("cls");
}

