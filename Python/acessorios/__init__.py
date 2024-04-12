from projeto import voltar_Menu, leia_nomes, leia_numero, leia_numero_Float , escrever_Arquivo
from os import system

def adicionar_Acessorio(acessorio_sessao, sessao):
    """
    Função para preencher o cadastro de acessórios.

    Argumentos:
        "acessorio_sessao" (lista): Retorno da lista de acessórios cadastrados
         em uma determianda sessão.
        "sessao" (lista): Lista de todas as sessões cadastradas.
    """
    from projeto import merge_sort

    system('cls')
    
    tipos = ('Joia', 'Bijuteria')
    
    nome = leia_nomes('Digite o nome do acessório: ')

    if(voltar_Menu(nome) == True):
        return None

    if(buscar_Acessorio(sessao, nome, True) == True):
        print('\033[31mAcessório já cadastrado!\033[m')

    else:
        while True:
            tipo = leia_numero('Digite o tipo do acessório\n[1] Joia\n[2] Bijuteria\n>>> ')

            if tipo == 1 or tipo == 2:
                break
            else:
                print('\033[31mOpção inválida!\033[m')

        preco = leia_numero_Float('Digite o preço do acessório: R$')
        quantidade = leia_numero('Informe a quantidade no estoque: ', True)

        print(f'Acessório "{nome}" adicionado com sucesso!')

        acessorio_sessao.append({'nome': nome, 'tipo': tipos[tipo - 1], 'preco': f'{preco:.2f}', 'quantidade': quantidade})
        merge_sort(acessorio_sessao, 'nome')


def buscar_Acessorio(sessao, busca='', retornar=False):
    """
    Função para realizar a busca por um acessório cadastrado.

    Argumentos:
        "sessao" (lista): Lista de todas as sessões cadastradas.

    Opcionais:
        "busca" (str): Nome do acessório a ser pesquisado.
        "retornar" (booleano): Retorna True se o acessório foi encontrado 
         ou False se não foi encontrado.
    """

    if(retornar == True):
        nome = busca

    elif len(sessao) == 0:
        system('cls')
        print('\033[31mNenhum acessório cadastrado!\033[m') 
        return None  
          
    else:
        system('cls')
        nome = leia_nomes('Qual o nome do acessório? ')

        if(voltar_Menu(nome) == True):  
            return None
    
    for count in range(0, len(sessao)):        
        for acessorio in sessao[count]['acessorios']:
            if nome == acessorio['nome'] and retornar == False:
                print(f'\033[32mAcessório encontrado na sessão {sessao[count]["nome"]}!\033[m')
                print(f'Nome: {acessorio["nome"]}\nTipo: {acessorio["tipo"]}\n'
                  f'Preço: R${acessorio["preco"]}\nQuantidade: {acessorio["quantidade"]}')
                return None
                
            elif nome == acessorio['nome'] and retornar == True:
                return True  
                
    if retornar == True:
        return False    
            
    print('\033[31mAcessório não encontrado!\033[m') if retornar == False else None


def remover_Acessorio(sessao):
    """
    Função para remover um acessório cadastrado.

    Argumentos:
        "sessao" (lista): Lista de todas as sessões cadastradas.    
    """
    system('cls')

    if len(sessao) == 0:
        print('\033[31mNenhum acessório cadastrado!\033[m')
        return None
    
    else:
        nome = leia_nomes('Digite o nome do acessório: ')

        if(voltar_Menu(nome) == True):
            return None

        for count in range(0, len(sessao)):
            for acessorio in sessao[count]['acessorios']:
                if nome == acessorio['nome']:
                    print(f'\033[32mAcessório encontrado na sessão {sessao[count]["nome"]}!')
                    sessao[count]['acessorios'].remove(acessorio)
                    print('Acessório removido com sucesso!\033[m')
                    escrever_Arquivo(sessao)
                    return None
                
        print('\033[31mAcessório não encontrado!\033[m')
        return None


def repor_Estoque(acessorio):
    """
    Função Extra: Repor o estoque de um acessório.

    Argumentos:
        "acessorio" (lista): Lista do acessório que terá o estoque reposto.
    """
    system('cls')

    quantidade_nova = leia_numero('\033[1mDigite a quantidade a ser reposta: ', True)
    acessorio['quantidade'] += quantidade_nova

    print(f'\033[32mEstoque reposto com sucesso!\033[m\033[1m Quantidade atual do acessório "{acessorio["nome"]}": {acessorio["quantidade"]}')
