from projeto.projeto import voltar_Menu, leia_nomes, leia_numero, escrever_Arquivo, merge_sort
from acessorios.acessorios import adicionar_Acessorio, repor_Estoque
from time import sleep
from os import system

def adicionar_Sessao(sessao):
    """
    Função para adicionar novas sessões ao sistema.

    Argumentos:
        "sessao" (lista): Lista de todas as sessões cadastradas.
    """
    system('cls')
    
    nome = leia_nomes('Digite o nome da sessão: ')

    if (voltar_Menu(nome) == True):
        return None
    
    for posicao in sessao:
        if nome == posicao['nome']:
            print(f'\033[31mSessão "{nome}" já cadastrada!\033[m')
            return None
    
    else:
        descricao = leia_nomes('Digite a descrição da sessão: ')

        if(voltar_Menu(descricao) == True):
            return None
    
        sessao.append({'nome': nome, 'descricao': descricao, 'acessorios': []})
        merge_sort(sessao, 'nome')
        escrever_Arquivo(sessao)

        print('\033[32mSessão adicionada com sucesso!\033[m')


def adicionar_Acessorios_Sessao(sessao):
    """
    Função para adicionar acessórios a uma sessão já cadastrada.

    Argumentos:
        "sessao" (lista): Lista de todas as sessões cadastradas.
    """
    system('cls')

    if len(sessao) == 0:
        print('\033[31mNenhuma sessão cadastrada!\033[m') 
        return None

    else:
        nome = leia_nomes('Qual o nome da sessao? ')

        if(voltar_Menu(nome) == True):
            return None
        
        for posicao in sessao:
            if nome == posicao['nome']:
                print('\033[32mSessão encontrada!\033[m')
                system('pause')

                adicionar_Acessorio(posicao['acessorios'], sessao)
                escrever_Arquivo(sessao)
                return None
                
        print('\033[31mSessão não encontrada!\033[m')


def remover_Sessao(sessao):
    """
    Função para remover sessões cadastradas do sistema.

    Argumentos:
        "sessao" (lista): Lista de todas as sessões cadastradas.
    """
    system('cls')

    if len(sessao) == 0:
        print('\033[31mNenhuma sessão cadastrada!\033[m') 
        return None
    
    nome = leia_nomes('Qual o nome da sessão? ')

    if(voltar_Menu(nome) == True):
        return None

    for posicao in sessao:
        if nome == posicao['nome']:
            print('\033[32mSessão encontrada! Removendo...\033[m')
            sleep(1)
            sessao.remove(posicao)
            escrever_Arquivo(sessao)
            return None
                
    print('\033[31mSessão não encontrada!\033[m')


def realizar_Venda(sessao):
    """
    Função para realizar a venda de acessórios de uma sessão.

    Argumentos:
        "sessao" (lista): Lista de todas as sessões cadastradas.
    """
    system('cls')

    if len(sessao) == 0:
        print('\033[31mNenhuma sessão cadastrada!\033[m') 
        return None

    nome = leia_nomes('Qual o nome da sessão? ')

    if(voltar_Menu(nome) == True):
        return None

    for posicao in sessao:
        if nome == posicao['nome'] and len(posicao['acessorios']) == 0:
            print('\033[33mSessão encontrada, mas não possui acessórios cadastrados!\033[m')
            return None

        elif nome == posicao['nome']:          
            print('\033[32mSessão foi encontrada!\033[m')
            sleep(1)
            system('cls')
                  
            compra = leia_nomes('\033[1mQual o nome do acessório? ')

            if(voltar_Menu(compra) == True):
                return None
            
            for acessorio in posicao['acessorios']:                
                if compra == acessorio['nome'] and acessorio['quantidade'] > 0:
                    print(f'\033[32mAcessório encontrado!\033[m')
                    sleep(0.5)
                    print(f'\033[1mNome: {acessorio["nome"]}\nTipo: {acessorio["tipo"]}\nPreço: R${acessorio["preco"]}\n'
                            f'Disponível no estoque: {acessorio["quantidade"]}')
                                    
                    while True:
                        quantidade = leia_numero('Informe a quantidade de itens: ', True)

                        if quantidade <= (acessorio['quantidade']):
                            acessorio['quantidade'] = acessorio['quantidade'] - quantidade
                            print(f'Valor total da compra: R${(float(acessorio["preco"]) * quantidade):.2f}')
                            escrever_Arquivo(sessao)
                            print('\033[32mVenda realizada com sucesso!\033[m')
                            return None
                            
                        else:
                            print('\033[31mEssa quantidade de items não está disponível no estoque!\033[m')

                if compra == acessorio['nome'] and acessorio['quantidade'] == 0:
                    print('\033[33mAcessório foi encontrado, mas infelizmente não temos estoque disponível!\033[m')
                    sleep(1)
                    print('\033[1mDeseja adicionar mais acessórios ao estoque?')
                    
                    while True:
                        opcao = leia_numero('[1] Sim\n[2] Não\n>>> ', True)

                        if opcao == 1:
                            repor_Estoque(acessorio)
                            escrever_Arquivo(sessao)
                            return None
                    
                        elif opcao == 2:
                            print('\033[31mReposição cancelada!\033[m')
                            return None 
                            
                        else:
                            print('\033[31mOpção inválida!\033[m') 
                        
            print('\033[31mAcessório não encontrado!\033[m')
            return None

    print('\033[31mSessão não encontrada!\033[m')


def ver_Sessoes_Acessorios(sessao):
    """
    Função para listar todas as sessões e seus acessórios.

    Argumentos:
        "sessao" (lista): Lista de todas as sessões cadastradas.
    """
    system('cls')

    if len(sessao) == 0:
        print('\033[31mNenhuma sessão cadastrada!\033[m') 
        return None
    
    for posicao in sessao:
        print('=' * 61)
        print(f'Sessão: {posicao["nome"]:<12} | Descrição: {posicao["descricao"]:<21}')
        print('-' * 61)
        print(f'{"Acessórios":<20} | {"Tipo":<10} | {"Preço":<12} | {"Quantidade":<10}')
        print('-' * 61)
        for acessorio in posicao['acessorios']:
            print(f'{acessorio["nome"]:<20} | {acessorio["tipo"]:<10} | R${acessorio["preco"]:<10} | {acessorio["quantidade"]:<10}')
        print('-' * 61)
        print(f'{"Total de acessórios: ":<10}{len(posicao["acessorios"]):<10}')
        print(f'{"FIM":_^61}\n\n')
    system('pause')
    system('cls')    
    