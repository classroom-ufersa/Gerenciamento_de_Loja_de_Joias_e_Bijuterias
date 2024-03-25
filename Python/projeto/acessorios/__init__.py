from os import system

def adicionar_Acessorio(sessoes, sessao):
    """
    """
    system('cls')
    
    tipos = ('Joia', 'Bijuteria')
    
    nome = str(input('Digite o nome do acessório: '))

    if(buscar_Acessorio(sessao, nome, True) == True):
        print('Acessório já cadastrado!')

    else:
        tipo = int(input('Digite o tipo do acessório\n[1] Joia\n[2] Bijuteria\n>>> '))
        tipo = tipos[tipo - 1]
        preco = float(input('Digite o preço do acessório: R$'))
        quantidade = int(input('Informe a quantidade no estoque: '))

        print(f'Acessório "{nome}" adicionado com sucesso!')

        sessoes.append({'nome': nome, 'tipo': tipo, 'preco': preco, 'quantidade': quantidade})
        

def buscar_Acessorio(sessao, busca='', retornar=False):
    """
    """

    if(retornar == True):
        nome = busca

    elif len(sessao) == 0:
        system('cls')
        print('Nenhum acessório cadastrado!') 
        return None  
          
    else:
        system('cls')
        nome = str(input('Qual o nome do acessório? '))
    
    for count in range(0, len(sessao)):
        for acessorio in sessao[count]['acessorios']:
            if nome == acessorio['nome'] and retornar == False:
                print(f'Acessório encontrado na sessão {sessao[count]["nome"]}!')
                print(f'Nome: {acessorio["nome"]}\nTipo: {acessorio["tipo"]}\n'
                      f'Preço: R${acessorio["preco"]}\nQuantidade: {acessorio["quantidade"]}')

            elif nome == acessorio['nome'] and retornar == True:
                return True     # Acessório não foi encontrado...


def remover_Acessorio(sessao):
    """
    """
    system('cls')

    if len(sessao) == 0:
        print('Nenhum acessório cadastrado!')
        return None
    
    else:
        nome = str(input('Digite o nome do acessório: '))

        for count in range(0, len(sessao)):
            for acessorio in sessao[count]['acessorios']:
                if nome == acessorio['nome']:
                    print(f'Acessório encontrado na sessão {sessao[count]["nome"]}!')
                    sessao[count]['acessorios'].remove(acessorio)
                    print('Acessório removido com sucesso!')
                    return None
                
        print('Acessório não encontrado!')
        return None
