void menu();
// Função auxiliar para mesclar duas listas ordenadas
Sessao* merge(Sessao *a, Sessao *b);

// Função para dividir a lista em duas partes
void split(Sessao *inicio, Sessao **a, Sessao **b);

// Função principal de merge sort para a lista de sessões
void mergeSort(Sessao **head);