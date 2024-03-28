#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sessao.c"
#include "acessorio.c"
#include "funcoes.c"

int main(){
    ListaSessao *s = NULL;
    ListaAcessorio *aces = NULL;
    char opcao;
    
    do{
        menu(); 
        printf("Digite a opcao desejada: ");
        scanf(" %c", &opcao);
        system("cls");
        
        switch(opcao){
            case '1':
            
                aces = adicionar_acessorio(aces);    
                break;
            case '2':
                //printf("Remover acessorio\n");
                break;
            case '3':
                //printf("Vender acessorio\n");
                break;
            case '4':
                //printf("Buscar acessorio\n");
                break;
            case '5':
                s = adicionar_sessao(s);
                break;
            case '6':
                //printf("Remover sessao existente\n");
                break;
            case '7':
                listar_sessoes(s);
                lista_acessorio(aces);
                break;
            case '8':
                printf("Saindo...\n");
                break;
            default:
                printf("Digite uma opcao valida\n");
        }

    }while(opcao != '8');

    return 0;
}