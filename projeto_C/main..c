#include "funcoes/funcoes.c"



int main(){
    Sessao *s = ler_dados_salvos();
    Acessorio *a = criar_acessorio();
    char opcao;
    char nome_sessao[50];

    do{
        mergeSort(&s);
        menu(); 
        printf("Digite a opcao desejada: ");
        scanf(" %c", &opcao);
        getchar();
        system("cls");
        switch (opcao){
        case '1':
            printf("Nome da sessao que desejar adicionar acessorio: ");
            scanf(" %[^\n]", nome_sessao);
            a = inserir_acessorio(a);
            adicionar_acessorio(s, nome_sessao, a);
            pressione_enter();
            break;  
        case '2':
            remover_acessorio(s);
            pressione_enter();
            break;
        case '3':
            realizar_venda(s);
            pressione_enter();
            break;
        case '4':
            buscar_acessorio(s);
            pressione_enter();
            break;
        case '5':
            s = inserir_sessao(s);
            pressione_enter();
            break;
        case '6':
            remover_sessao(&s);
            pressione_enter();
            break;
        case '7':
            listar_sessoes(s);
            pressione_enter();
            break;
        case '8':
            printf("Saindo...\n");
            break;
        default:
            printf("Digite uma opcao valida\n\n");
            break;
        }
        salvar_dados(s);
    }while(opcao != '8');

}