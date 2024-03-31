#include "sessao/sessao.c"
#include "funcoes/funcoes.c"



int main(){
    Sessao *s = ler_dados_salvos();
    Acessorio *a = criar_acessorio();
    char opcao;

    do{
        menu(); 
        printf("Digite a opcao desejada: ");
        scanf(" %c", &opcao);
        system("cls");
        switch (opcao){
        case '1':
            printf("Nome da sessao que desejar adicionar acessorio: ");
            char nome_sessao[50];
            scanf(" %[^\n]", nome_sessao);
            a = inserir_acessorio(a);
            adicionar_acessorio(s, nome_sessao, a);
            break;  
        case '2':
            
            break;
        case '3':
            
            break;
        case '4':
            buscar_acessorio(s);
            break;
        case '5':
            s = inserir_sessao(s);
            break;
        case '6':
            remover_sessao(&s);
            break;
        case '7':
            listar_sessoes(s);
            break;
        case '8':
            printf("Saindo...\n");
            break;
        default:
            printf("Digite uma opcao valida\n\n");
            break;
        }
            
    }while(opcao != '8');
    salvar_dados(s);



}