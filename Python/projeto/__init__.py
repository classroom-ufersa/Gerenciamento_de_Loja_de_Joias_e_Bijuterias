def menu():
    """
    Função para exibir o menu principal do sistema.
    """
    
    print("""\033[1m
╔═══════════════════════════════════════════════╗
║          Loja de Joias e Bijuterias           ║
╠═══════════════════════════════════════════════╣
║   [1] ADICIONAR ACESSÓRIO                     ║
║   [2] ADICIONAR NOVA SESSÃO                   ║
║   [3] BUSCAR ACESSÓRIO                        ║
║   [4] VER TODAS AS SESSÕES E A ACESSÓRIOS     ║
║   [5] REALIZAR VENDA DE ACESSÓRIOS            ║
║   [6] REMOVER ACESSÓRIO                       ║
║   [7] REMOVER SESSÃO EXISTENTE                ║
║   [8] SAIR                                    ║
╚═══════════════════════════════════════════════╝""")

    choice = read_numbers('Escolha uma opção: ')

    return choice


def merge_sort(sessoes, chave):
    """
    Função de ordenação de sessões por nome.
    Utiliza o algoritmo de ordenação Merge Sort.
    """
    
    if len(sessoes) > 1:
        meio = len(sessoes) // 2  
        metade_esquerda = sessoes[:meio]
        metade_direita = sessoes[meio:]

        merge_sort(metade_esquerda, chave)
        merge_sort(metade_direita, chave)

        i = j = k = 0  
        while i < len(metade_esquerda) and j < len(metade_direita):
            if metade_esquerda[i][chave] < metade_direita[j][chave]:
                sessoes[k] = metade_esquerda[i]
                i += 1
            else:
                sessoes[k] = metade_direita[j]
                j += 1
            k += 1

        while i < len(metade_esquerda):
            sessoes[k] = metade_esquerda[i]
            i += 1
            k += 1

        while j < len(metade_direita):
            sessoes[k] = metade_direita[j]
            j += 1
            k += 1


def ler_Arquivo():
    """
    Função para ler o arquivo de sessões salvas no arquivo .txt.
    """
    from os import path

    if not path.exists('sessoes.txt'):
        open('sessoes.txt', 'x')

    with open('sessoes.txt', 'r') as file:
        sessoes = file.readlines()
        
    sessoes = [eval(sessao) for sessao in sessoes]

    return sessoes 


def escrever_Arquivo(sessoes):
    """
    Função para escrever os dados do sistema no arquivo .txt.
    """

    with open('sessoes.txt', 'w') as file:
        for sessao in sessoes:
            file.write(f'{sessao}\n')


def read_numbers(msg, test=False):
    """
    Tratamento de Erros:
    Função para ler apenas números inteiros.
    """

    while True:
        try:
            num = str(input(msg))

        except (EOFError, IndexError):
            print('\033[31mERRO! Por favor, digite um número inteiro válido.\033[m')

        else:    
            if len(num) > 0 and num[0] != '0':
                try:
                    num = int(num)

                except (ValueError, TypeError, NameError, EOFError):
                    print('\033[31mERRO! Por favor, digite um número inteiro válido.\033[m') 

                else:
                    return num
            else:
                print('\033[31mERRO! Por favor, digite uma opção válida.\033[m') if test == False else print('\033[31mERRO! Por favor, digite um número inteiro válido.\033[m')


def read_float_numbers(msg):
    """
    Tratamento de Erros:
    Função para ler apenas números decimais.
    """

    while True:
        valor = str(input(f'{msg}')).replace(",", ".").strip()

        if len(valor) > 2 and '.' in valor or valor.isnumeric():
            break

        if valor == "" or valor.isalpha():
            print(f'\033[31mERRO: "{valor}" é um preço inválido!\033[m')

        else:
            print(f'\033[31mERRO: "{valor}" é um preço inválido!\033[m')

    return float(valor)


def read_names(msg):
    """
    Tratamento de Erros:
    Função para ler apenas nomes.
    """

    while True:
        try:
            nome = str(input(msg))

            if not nome.replace(" ", "").isalpha():
                raise ValueError('O nome deve conter apenas letras.')

        except ValueError as ve:
            print('\033[31mERRO! Por favor, digite um nome válido.\033[m')

        except EOFError:
            print('\033[31mERRO! Por favor, digite um nome válido.\033[m')

        else:
            return nome.strip().title()
        