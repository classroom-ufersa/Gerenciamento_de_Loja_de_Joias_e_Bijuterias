from projeto import read_names, read_numbers, read_float_numbers , escrever_Arquivo
from os import system

def adicionar_Acessorio(sessoes, sessao):
    """
    Função para preencher o cadastro de acessórios.
    """
    from projeto import merge_sort

    system('cls')
    
    tipos = ('Joia', 'Bijuteria')
    
    nome = read_names('Digite o nome do acessório: ')

    if(buscar_Acessorio(sessao, nome, True) == True):
        print('Acessório já cadastrado!')

    else:
        while True:
            tipo = read_numbers('Digite o tipo do acessório\n[1] Joia\n[2] Bijuteria\n>>> ')

            if tipo == 1 or tipo == 2:
                break
            else:
                print('Opção inválida!')

        preco = read_float_numbers('Digite o preço do acessório: R$')
        quantidade = read_numbers('Informe a quantidade no estoque: ', True)

        print(f'Acessório "{nome}" adicionado com sucesso!')

        sessoes.append({'nome': nome, 'tipo': tipos[tipo - 1], 'preco': f'{preco:.2f}', 'quantidade': quantidade})
        merge_sort(sessoes, 'nome')


def buscar_Acessorio(sessao, busca='', retornar=False):
    """
    Função para realizar a busca por um acessório cadastrado.
    """

    if(retornar == True):
        nome = busca

    elif len(sessao) == 0:
        system('cls')
        print('Nenhum acessório cadastrado!') 
        return None  
          
    else:
        system('cls')
        nome = read_names('Qual o nome do acessório? ')
    
    for count in range(0, len(sessao)):        
        for acessorio in sessao[count]['acessorios']:
            if nome == acessorio['nome'] and retornar == False:
                print(f'Acessório encontrado na sessão {sessao[count]["nome"]}!')
                print(f'Nome: {acessorio["nome"]}\nTipo: {acessorio["tipo"]}\n'
                      f'Preço: R${acessorio["preco"]}\nQuantidade: {acessorio["quantidade"]}')
                if retornar == True:
                    return False                
                return None
            
            elif nome == acessorio['nome'] and retornar == True:
                return True     # Acessório não foi encontrado...
            
    print('Acessório não encontrado!') if retornar == False else None


def remover_Acessorio(sessao):
    """
    Função para remover um acessório cadastrado.
    """
    system('cls')

    if len(sessao) == 0:
        print('Nenhum acessório cadastrado!')
        return None
    
    else:
        nome = read_names('Digite o nome do acessório: ')

        for count in range(0, len(sessao)):
            for acessorio in sessao[count]['acessorios']:
                if nome == acessorio['nome']:
                    print(f'Acessório encontrado na sessão {sessao[count]["nome"]}!')
                    sessao[count]['acessorios'].remove(acessorio)
                    print('Acessório removido com sucesso!')
                    escrever_Arquivo(sessao)
                    return None
                
        print('Acessório não encontrado!')
        return None
