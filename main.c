#include <stdio.h>
#include <stdlib.h>
#include "Sessao/sessao.c"

int main(){

    Sessao *sessao = NULL;
    Acessorio *acessorio = NULL;
    int opcao;

    do{
        printf("[1] Adicionar sessao\n[2] Adicionar acessorio\n[3] Listar tudo\n[4] Adionar acessorio a sessao\n[5] Sair\n>>> ");
        scanf(" %d", &opcao);
        fflush(stdin);

        switch (opcao){
        case 1:
            sessao = criar_sessao(sessao);
            break;
        case 2:
            acessorio = criar_acessorio(acessorio);
            break;
        case 3:
            listar_acessorios(acessorio);
            listar_sessoes(sessao);
            break;
        case 4:
            //adicionar_acessorio(sessao, acessorio);
            break;
        case 5:
            printf("Saindo...");
            break;
        default:
            break;
        }
    }while(opcao != 5);

    liberar_acessorios(acessorio);
    liberar_sessao(sessao);
    
    return 0;
}