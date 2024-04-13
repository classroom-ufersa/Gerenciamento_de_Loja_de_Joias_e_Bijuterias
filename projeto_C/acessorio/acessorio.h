#ifndef ACESSORIO_H
#define ACESSORIO_H

// definição de um novo tipo estrturado de dado chamado Acessorio
typedef struct acessorio Acessorio;

/*
* @brief Função para criar um novo acessório
* @return Retorna um ponteiro para o novo acessório
* @return NULL caso não seja possível alocar memória
*/
Acessorio *criar_acessorio(void);

/*
* @brief Função para inserir um novo acessório na lista de acessórios
* @param a Ponteiro para a lista de acessórios
* @return Retorna um ponteiro para o novo acessório
*/
Acessorio *inserir_acessorio(Acessorio *a);

#endif