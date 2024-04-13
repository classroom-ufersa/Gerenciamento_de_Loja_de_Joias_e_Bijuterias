#include "sessao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../funcoes/funcoes.h"


struct sessao{
    char nome[50];
    char descricao[100];
    Acessorio *acessorios;
    Sessao *proximo;
};

Sessao *criar_sessao(void){
    return NULL;
}


Sessao *inserir_sessao(Sessao *s){
    char nome[50], descricao[100];
    do{
        printf("Digite o nome da sessao: ");
        scanf(" %[^\n]", nome);
        if(s != NULL){
            Sessao *temporario = s;
            while(temporario != NULL){
                if(strcmp(temporario->nome, nome) == 0){
                    printf("Erro: O nome da sessao ja existe.\n");
                    return s;
                }
                temporario = temporario->proximo;
            }
        }
    }while(contem_apenas_letras(nome) == 0);
    maiusculo_string(nome);
    
    do{
        printf("Digite a descricao da sessao: ");
        scanf(" %[^\n]", descricao); 
    }while(contem_apenas_letras(descricao) == 0);
    maiusculo_string(descricao);
    

    Sessao *nova_sessao = (Sessao *) malloc(sizeof(Sessao));
    if(nova_sessao == NULL){
        printf("Erro ao alocar memoria\n");
        exit(1);
    }

    strcpy(nova_sessao->nome, nome);
    strcpy(nova_sessao->descricao, descricao);
    nova_sessao->acessorios = NULL;
    nova_sessao->proximo = s;
    return nova_sessao;
}

void listar_sessoes(Sessao *inicio) {
    Sessao *atual = inicio;
    printf("Sessoes disponiveis:\n\n");
    while (atual != NULL) {
        printf("Nome da sessao: %s\n", atual->nome);
        printf("Descricao: %s\n", atual->descricao);
        printf("Acessorios:\n");
        Acessorio *acessorio_atual = atual->acessorios;
        while (acessorio_atual != NULL) {
            printf("\n");
            printf("Nome: %s\n", acessorio_atual->nome);
            printf("Tipo: %s\n", acessorio_atual->tipo);
            printf("Preco: %.2f\n", acessorio_atual->preco);
            printf("Quantidade em estoque: %d\n", acessorio_atual->quantidade);
            acessorio_atual = acessorio_atual->proximo;
        }
        printf("\n");
        atual = atual->proximo;
    }
}

void adicionar_acessorio(Sessao *inicio, char nome_sessao[], Acessorio *novo_acessorio) {
    Sessao *sessao_atual = inicio;
    
    while (sessao_atual != NULL && strcmp(sessao_atual->nome, nome_sessao) != 0) {
        sessao_atual = sessao_atual->proximo;
    }

    if (sessao_atual == NULL) {
        printf("Sessao nao encontrada.\n");
        return;
    }

    if (sessao_atual->acessorios == NULL || strcmp(novo_acessorio->nome, sessao_atual->acessorios->nome) < 0) {
        novo_acessorio->proximo = sessao_atual->acessorios;
        sessao_atual->acessorios = novo_acessorio;
    } else {
        Acessorio *atual = sessao_atual->acessorios;
        while (atual->proximo != NULL && strcmp(novo_acessorio->nome, atual->proximo->nome) > 0) {
            atual = atual->proximo;
        }
        novo_acessorio->proximo = atual->proximo;
        atual->proximo = novo_acessorio;
    }
}

// Função para remover um acessório de uma sessão
void remover_acessorio(Sessao *lista_sessoes) {
    char nome_acessorio[50];
    char nome_sessao[50];

    do{
        printf("Digite o nome da sessao onde deseja remover o acessorio: ");
        scanf(" %[^\n]", nome_sessao);
    }while(contem_apenas_letras(nome_sessao) == 0);
    maiusculo_string(nome_sessao);

    do{
        printf("Digite o nome do acessorio a ser removido: ");
        scanf(" %[^\n]", nome_acessorio);
    }while(contem_apenas_letras(nome_acessorio) == 0);
    maiusculo_string(nome_acessorio);
    

    Sessao *sessao_atual = lista_sessoes;
    while (sessao_atual != NULL && strcmp(sessao_atual->nome, nome_sessao) != 0) {
        sessao_atual = sessao_atual->proximo;
    }

    if (sessao_atual == NULL) {
        printf("Sessao nao encontrada.\n");
        return;
    }

    Acessorio *atual = sessao_atual->acessorios;
    Acessorio *anterior = NULL;

    while (atual != NULL && strcmp(atual->nome, nome_acessorio) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual != NULL) {
        if (anterior == NULL) {
            sessao_atual->acessorios = atual->proximo;
        } else {
            anterior->proximo = atual->proximo;
        }
        printf("Acessorio removido com sucesso da sessao %s!\n", sessao_atual->nome);
        free(atual);
    } else {
        printf("Acessorio nao encontrado na sessao %s.\n", nome_sessao);
    }
}

void realizar_venda(Sessao *lista_sessoes) {
    char nome_acessorio[50];
    int quantidade;
    char nome_sessao[50];
    do{
        printf("Digite o nome da sessao onde deseja realizar a venda: ");
        scanf(" %[^\n]", nome_sessao);
    }while(contem_apenas_letras(nome_sessao) == 0);
    maiusculo_string(nome_sessao);
    
    do{
        printf("Digite o nome do acessorio a ser vendido: ");
        scanf(" %[^\n]", nome_acessorio);
    }while(contem_apenas_letras(nome_acessorio) == 0);
    maiusculo_string(nome_acessorio);
        
    quantidade = numero_inteiroc();
    

    Sessao *sessao_atual = lista_sessoes;
    while (sessao_atual != NULL && strcmp(sessao_atual->nome, nome_sessao) != 0) {
        sessao_atual = sessao_atual->proximo;
    }

    if (sessao_atual == NULL) {
        printf("Sessao nao encontrada.\n");
        return;
    }

    Acessorio *atual = sessao_atual->acessorios;
    while (atual != NULL && strcmp(atual->nome, nome_acessorio) != 0) {
        atual = atual->proximo;
    }

    if (atual != NULL) {
        if (atual->quantidade >= quantidade) {
            atual->quantidade -= quantidade;
            printf("%d unidades de %s vendidas com sucesso na sessao %s!\n", quantidade, atual->nome, nome_sessao);
        } else {
            printf("Quantidade insuficiente em estoque na sessao %s.\n", nome_sessao);
        }
    } else {
        printf("Acessorio nao encontrado na sessao %s.\n", nome_sessao);
    }
}


// Função para buscar um acessório em uma sessão específica
void buscar_acessorio(Sessao *inicio) {
    char nome_sessao[50];
    char nome_acessorio[50];
    
    do{
        printf("Digite o nome da sessao onde deseja buscar o acessrio: ");
        scanf("%s", nome_sessao);
    }while(contem_apenas_letras(nome_sessao) == 0);
    maiusculo_string(nome_sessao);

    do{
        printf("Digite o nome do acessorio que deseja buscar: ");
        scanf("%s", nome_acessorio);
    }while(contem_apenas_letras(nome_acessorio) == 0);
    maiusculo_string(nome_acessorio);
    

    Sessao *sessao_atual = inicio;
    while (sessao_atual != NULL && strcmp(sessao_atual->nome, nome_sessao) != 0) {
        sessao_atual = sessao_atual->proximo;
    }

    if (sessao_atual == NULL) {
        printf("Sessao nao encontrada.\n");
        return;
    }

    Acessorio *acessorio_atual = sessao_atual->acessorios;
    while (acessorio_atual != NULL && strcmp(acessorio_atual->nome, nome_acessorio) != 0) {
        acessorio_atual = acessorio_atual->proximo;
    }

    if (acessorio_atual == NULL) {
        printf("Acessorio nao encontrado na sessao '%s'.\n", nome_sessao);
    } else {
        printf("Acessorio encontrado na sessao '%s':\n", nome_sessao);
        printf("Nome: %s\n", acessorio_atual->nome);
        printf("Tipo: %s\n", acessorio_atual->tipo);
        printf("Preco: %.2f\n", acessorio_atual->preco);
        printf("Quantidade em estoque: %d\n", acessorio_atual->quantidade);
    }
}

void remover_sessao(Sessao **inicio) {
    char nome[50];

    printf("Digite o nome da sessao que deseja remover: ");
    scanf(" %[^\n]", nome);
    maiusculo_string(nome);

    Sessao *atual = *inicio;
    Sessao *anterior = NULL;
    while (atual != NULL && strcmp(atual->nome, nome) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }
    if (atual != NULL) {
        if (anterior == NULL) {
            *inicio = atual->proximo;
        } else {
            anterior->proximo = atual->proximo;
        }
        free(atual);
    }
}


// Função para salvar os dados da loja em um arquivo de texto
void salvar_dados(Sessao *inicio) {
    FILE *arquivo = fopen("dados_loja.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Sessao *atual_sessao = inicio;
    while (atual_sessao != NULL) {
        maiusculo_string(atual_sessao->nome);
        maiusculo_string(atual_sessao->descricao);
        fprintf(arquivo, "SESSAO: %s\tDESCRICAO: %s\n", atual_sessao->nome, atual_sessao->descricao);

        Acessorio *atual_acessorio = atual_sessao->acessorios;
        while (atual_acessorio != NULL) {
            maiusculo_string(atual_acessorio->nome);
            maiusculo_string(atual_acessorio->tipo);
            fprintf(arquivo, "ACESSORIOS: %s\t%s\t%.2f\t%d\n", atual_acessorio->nome, atual_acessorio->tipo, atual_acessorio->preco, atual_acessorio->quantidade);
            atual_acessorio = atual_acessorio->proximo;
        }

        fprintf(arquivo, "\n");
        atual_sessao = atual_sessao->proximo;
    }

    fclose(arquivo);
}


// Função para ler os dados salvos da loja de um arquivo de texto
// Função para ler os dados salvos da loja de um arquivo de texto
Sessao *ler_dados_salvos() {
    FILE *arquivo = fopen("dados_loja.txt", "r");
    if (arquivo == NULL) {
        printf("Arquivo de dados nao encontrado.\n");
        return NULL;
    }

    Sessao *inicio = NULL;
    Sessao *atual = NULL;
    Acessorio *acessorio_atual = NULL;
    char linha[255];
    char nome_sessao[50];
    char descricao_sessao[100];
    char nome_acessorio[50];
    char tipo_acessorio[20];
    float preco_acessorio;
    int quantidade_acessorio;

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        linha[strcspn(linha, "\n")] = '\0';

        if (strstr(linha, "SESSAO:") != NULL) {    
            sscanf(linha, "SESSAO: %[^\t]\tDESCRICAO: %[^\n]", nome_sessao, descricao_sessao);
            
            Sessao *nova_sessao = (Sessao *)malloc(sizeof(Sessao));
            if (nova_sessao == NULL) {
                printf("Erro ao alocar memoria para a sessao.\n");
                fclose(arquivo);
                return NULL;
            }
            
            strcpy(nova_sessao->nome, nome_sessao);
            strcpy(nova_sessao->descricao, descricao_sessao);
            nova_sessao->acessorios = NULL;
            nova_sessao->proximo = NULL;
            
            if (inicio == NULL) {
                inicio = nova_sessao;
                atual = nova_sessao;
            } else {
                atual->proximo = nova_sessao;
                atual = atual->proximo;
            }
        } else if (strstr(linha, "ACESSORIOS:") != NULL && atual != NULL) {
            sscanf(linha, "ACESSORIOS: %[^\t]\t%[^\t]\t%f\t%d", nome_acessorio, tipo_acessorio, &preco_acessorio, &quantidade_acessorio);
            
            Acessorio *novo_acessorio = (Acessorio *)malloc(sizeof(Acessorio));
            if (novo_acessorio == NULL) {
                printf("Erro ao alocar memoria para o acessorio.\n");
                fclose(arquivo);
                return inicio; 
            }
            
            strcpy(novo_acessorio->nome, nome_acessorio);
            strcpy(novo_acessorio->tipo, tipo_acessorio);
            novo_acessorio->preco = preco_acessorio;
            novo_acessorio->quantidade = quantidade_acessorio;
            novo_acessorio->proximo = NULL;
            
            if (atual->acessorios == NULL) {
                atual->acessorios = novo_acessorio;
                acessorio_atual = novo_acessorio;
            } else {
                acessorio_atual->proximo = novo_acessorio;
                acessorio_atual = acessorio_atual->proximo;
            }
        }
    }

    fclose(arquivo);
    return inicio;
}

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

void liberar_memoria(Sessao *inicio) {
    Sessao *atual = inicio;
    Sessao *proximo = NULL;
    while (atual != NULL) {
        proximo = atual->proximo;
        Acessorio *acessorio_atual = atual->acessorios;
        Acessorio *acessorio_proximo = NULL;
        while (acessorio_atual != NULL) {
            acessorio_proximo = acessorio_atual->proximo;
            free(acessorio_atual);
            acessorio_atual = acessorio_proximo;
        }
        free(atual);
        atual = proximo;
    }
}

