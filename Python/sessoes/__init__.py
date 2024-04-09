from projeto import read_names, escrever_Arquivo, merge_sort
from os import system

def adiconar_Sessao(sessao):
    """
    Função para adicionar novas sessões ao sistema.
    """
    system('cls')
    
    nome = read_names('Digite o nome da sessão: ')

    if nome in [sessao['nome'] for sessao in sessao]:
        print(f'Sessão "{nome}" já cadastrada!')
        return None
    
    else:
        descricao = read_names('Digite a descrisão da sessão: ')

        sessao.append({'nome': nome, 'descricao': descricao, 'acessorios': []})
        merge_sort(sessao, 'nome')
        escrever_Arquivo(sessao)

        print('Sessão adicionada com sucesso!')


def adicionar_Acessorios_Sessao(sessao):
    """
    Função para adicionar acessórios a uma sessão já cadastrada.
    """
    from acessorios import adicionar_Acessorio

    system('cls')

    if len(sessao) == 0:
        print('Nenhuma sessão cadastrada!') 
        return None

    else:
        nome = read_names('Qual o nome da sessao? ')

        for sessoes in sessao:
            if nome == sessoes['nome']:
                print('Sessão encontrada!')
                system('pause')

                adicionar_Acessorio(sessoes['acessorios'], sessao)
                escrever_Arquivo(sessao)
                return None
                
        print('Sessão não encontrada!')


def remover_Sessao(sessao):
    """
    Função para remover sessões cadastradas do sistema.
    """
    system('cls')

    if len(sessao) == 0:
        print('Nenhuma sessão cadastrada!') 
        return None
    
    nome = read_names('Qual o nome da sessão? ')

    for sessoes in sessao:
        if nome == sessoes['nome']:
            print('Sessão encontrada! Removendo...')
            sessao.remove(sessoes)
            escrever_Arquivo(sessao)
            return None
                
    print('Sessão não encontrada!')


def realizar_Venda(sessao):
    """
    Função para realizar a venda de acessórios de uma sessão.
    """
    from projeto import read_numbers

    system('cls')

    if len(sessao) == 0:
        print('Nenhuma sessão cadastrada!') 
        return None

    nome = read_names('Qual o nome da sessão? ')

    for sessoes in sessao:
        if nome == sessoes['nome'] and len(sessoes['acessorios']) == 0:
            print('Sessão encontrada, mas não possui acessórios cadastrados!')
            return None

        elif nome == sessoes['nome']:          
            print('Sessão foi encontrada!')
                  
            compra = read_names('Qual o nome do acessório? ')
            
            for acessorio in sessoes['acessorios']:                
                if compra == acessorio['nome']:
                    print(f'Nome: {acessorio["nome"]}\nTipo: {acessorio["tipo"]}\nPreço: R${acessorio["preco"]}\n'
                            f'Disponível no estoque: {acessorio["quantidade"]}')

                    while True:
                        quantidade = read_numbers('Informe a quantidade de itens: ', True)

                        if quantidade <= (acessorio['quantidade']):
                            acessorio['quantidade'] = acessorio['quantidade'] - quantidade
                            print(f'Valor total da compra: R${(float(acessorio["preco"]) * quantidade):.2f}')
                            escrever_Arquivo(sessao)
                            print('Venda realizada com sucesso!')
                            return None
                            
                        else:
                            print('Essa quantidade de items não está disponível no estoque!')
                                
            print('Acessório não encontrado!')
            return None

    print('Sessão não encontrada!')


def ver_Sessoes_Acessorios(sessao):
    """
    Função para listar todas as sessões e seus acessórios.
    """
    system('cls')

    if len(sessao) == 0:
        print('Nenhuma sessão cadastrada!') 
        return None
    
    for sessoes in sessao:
        print('=' * 20)
        print(f'Nome: {sessoes["nome"]}\nDescrição: {sessoes["descricao"]}\n')
        for acessorio in sessoes['acessorios']:
            print(f'Nome: {acessorio["nome"]}\nTipo: {acessorio["tipo"]}\n'
                  f'Preço: R${acessorio["preco"]}\nQuantidade: {acessorio["quantidade"]}\n')
