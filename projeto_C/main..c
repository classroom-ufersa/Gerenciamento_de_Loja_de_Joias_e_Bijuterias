#include "funcoes/funcoes.c"
#include "sessao/sessao.c"



int main(){
    Sessao *s = ler_dados_salvos();
    Acessorio *a = criar_acessorio();
    int opcao;
    char nome_sessao[50];
    
    do{
        mergeSort(&s);
        menu();
        opcao = valida_opcao();
                
        system("cls");
        switch (opcao){
        case 1:
            if(botao_voltar() == '1'){
                break;
            }else{
                do{
                printf("Nome da sessao que desejar adicionar acessorio: ");
                scanf(" %[^\n]", nome_sessao);
                maiusculo_string(nome_sessao);
                }while(contem_apenas_letras(nome_sessao) == 0);            
                a = inserir_acessorio(a);
                adicionar_acessorio(s, nome_sessao, a);
                pressione_enter();
                break;
            }  
        case 2:
            if(botao_voltar() == '1'){
                break;
            }else{
                remover_acessorio(s);
                pressione_enter();
                break;
            }
            
        case 3:
            if(botao_voltar() == '1'){
                break;
            }else{
                realizar_venda(s);
                pressione_enter();
                break;
            }
        case 4:
            if(botao_voltar() == '1'){
                break;
            }else{
                buscar_acessorio(s);
                pressione_enter();
                break;
            }
        case 5:
            if(botao_voltar() == '1'){
                break;
            }else{
                s = inserir_sessao(s);
                pressione_enter();
                break;
            }
        case 6:
            if(botao_voltar() == '1'){
                break;
            }else{
                remover_sessao(&s);
                pressione_enter();
                break;
            }
        case 7:
            if(botao_voltar() == '1'){
                break;
            }else{
                listar_sessoes(s);
                pressione_enter();
                break;
            }
        case 8:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida. Digite um numero correspondente com as opcoes do menu.\n");
            limpar_tela();
            break;
        }
        salvar_dados(s);
    }while(opcao!= 8);

}