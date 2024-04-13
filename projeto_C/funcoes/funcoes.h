// função para exibir o menu
void menu();

// função para esperar o usuário pressionar enter
void pressione_enter();

// função para limpar a tela
void limpar_tela();

/*
* @brief Função para exibir um botão de voltar
* @return Retorna um caractere correspondente a opção escolhida
* @return '1' para voltar
*/
char botao_voltar();

/*
* @brief Função para validar que seja digitado um número inteiro
* @return Retorna o número inteiro digitado
*/
int numero_inteiroc();

/*
@brief Função para validar que seja digitado um número float
@return Retorna o número float digitado

*/
float numero_floatc();

/*
* @brief Função para verificar se a string contém apenas letras
* @param str Ponteiro para a string
* @return Retorna 1 se a string contém apenas letras
* @return Retorna 0 se a string contém outros caracteres
*/
int contem_apenas_letras(char *str);

/*
@brief Função para converter uma string para maiúsculo
@param str Ponteiro para a string
@return void
*/
void maiusculo_string(char *str);

/*
@brief Função para validar a opção digitada
@return Retorna a opção válida

*/
int valida_opcao();