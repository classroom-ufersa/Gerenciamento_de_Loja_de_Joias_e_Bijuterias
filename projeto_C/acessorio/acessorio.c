#include "./acessorio.h"
#include "../funcoes/funcoes.h"

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
    do{
        printf("Digite o nome do acessorio: ");
        scanf(" %[^\n]", nome);
        maiusculo_string(nome);
    }while(contem_apenas_letras(nome) == 0);
    
    do{
        printf("Digite o tipo do acessorio JOIA ou BIJUTERIA: ");
        scanf(" %[^\n]", tipo);
        maiusculo_string(tipo);
    }while(contem_apenas_letras(tipo) == 0 || validar_tipo(tipo) == 0);
    
    preco = numero_floatc();

    quantidade = numero_inteiroc();

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