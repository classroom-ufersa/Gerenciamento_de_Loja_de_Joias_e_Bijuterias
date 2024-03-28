#ifndef ACESSORIO_H
#define ACESSORIO_H

typedef struct acessorio Acessorio;
typedef struct lista_acessorio ListaAcessorio;

ListaAcessorio *criar_lista_acessorio();
ListaAcessorio *adicionar_acessorio(ListaAcessorio *lista);
void lista_acessorio(ListaAcessorio *lista);


/*
Acessorio *criar_acessorio();
Acessorio *adicionar_acessorio(Acessorio *acessorio);
*/
#endif