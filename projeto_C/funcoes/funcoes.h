#include "../sessao/sessao.h"

void menu();

int botao_voltar();

void pressione_enter();

void limpar_tela();

int numero_inteiro(char *str);

int contem_apenas_letras(char *str);

void formata_string(char *str);




// Função auxiliar para mesclar duas listas ordenadas
Sessao* merge(Sessao *a, Sessao *b);

// Função para dividir a lista em duas partes
void split(Sessao *inicio, Sessao **a, Sessao **b);

// Função principal de merge sort para a lista de sessões
void mergeSort(Sessao **head);
