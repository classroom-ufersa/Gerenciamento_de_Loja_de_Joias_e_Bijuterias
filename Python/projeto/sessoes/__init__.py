from os import system

def adiconar_Sessao(sessao):
    """
    """
    system('cls')
    
    nome = str(input('Digite o nome da sessão: '))

    if nome in [sessao['nome'] for sessao in sessao]:
        print('Sessão já cadastrada!')
        return None
    
    else:
        descricao = str(input('Digite a descrisão da sessão: '))

        sessao.append({'nome': nome, 'descricao': descricao, 'acessorios': []})

        print('Sessão adicionada com sucesso!')


def adicionar_Acessorios_Sessao(sessao):
    """
    """
    from projeto.acessorios import adicionar_Acessorio

    system('cls')

    if len(sessao) == 0:
        print('Nenhuma sessão cadastrada!') 
        return None

    else:
        nome = str(input('Qual o nome da sessao? '))

        for sessoes in sessao:
            if nome == sessoes['nome']:
                print('Sessão encontrada!')
                system('pause')

                adicionar_Acessorio(sessoes['acessorios'], sessao)
                return None
                
        print('Sessão não encontrada!')


def remover_Sessao(sessao):
    """
    """
    system('cls')

    if len(sessao) == 0:
        print('Nenhuma sessão cadastrada!') 
        return None
    
    nome = str(input('Qual o nome da sessão? '))

    for sessoes in sessao:
        if nome == sessoes['nome']:
            print('Sessão encontrada!')
            system('pause')
            return None
                
    print('Sessão não encontrada!')


def realizar_Venda(sessao):
    """
    """
    system('cls')

    if len(sessao) == 0:
        print('Nenhuma sessão cadastrada!') 
        return None

    nome = str(input('Qual o nome da sessão? '))

    for sessoes in sessao:
        if nome == sessoes['nome'] and len(sessoes['acessorios']) == 0:
            print('Sessão encontrada, mas não possui acessórios cadastrados!')
            return None
            
        else:                
            compra = str(input('Qual o nome do acessório? '))
            
            for count in range(0, len(sessao)):
                for acessorio in sessao[count]['acessorios']:

                    if compra == acessorio['nome']:
                        print(f'Nome: {acessorio["nome"]}\nTipo: {acessorio["tipo"]}\nPreço: R${acessorio["preco"]}\n'
                              f'Disponível no estoque: {acessorio["quantidade"]}')

                        quantidade = int(input('Informe a quantidade de itens: '))

                        if quantidade <= (acessorio['quantidade']):
                            acessorio['quantidade'] = acessorio['quantidade'] - quantidade
                            print(f'Valor total da compra: R${acessorio["preco"] * quantidade}')
                            print('Venda realizada com sucesso!')
                            return None
                        
            print('Acessório não encontrado!')
            return None

    print('Sessão não encontrada!')


def ver_Sessoes_Acessorios(sessao):
    """
    """
    system('cls')

    # AJEITAR *****
    if len(sessao) == 0:
        print('Nenhuma sessão/acessório cadastrado!') 
        return None
    
    for sessoes in sessao:
        print(f'Nome: {sessoes["nome"]}\nDescrição: {sessoes["descricao"]}\nAcessórios: {sessoes["acessorios"]}\n')