def menu():
    """
    """
    from projeto import read_numbers

    print('=-' * 14)
    print(' LOJA DE JOIAS E BIJUTERIAS')
    print('=-' * 14)
    print('[1] ADICIONAR ACESSÓRIO\n[2] ADICIONAR NOVA SESSÃO\n[3] BUSCAR ACESSÓRIO\n'
          '[4] VER TODAS AS SESSÕES E A ACESSÓRIOS\n[5] REALIZAR VENDA DE ACESSÓRIOS\n'
          '[6] REMOVER ACESSÓRIO\n[7] REMOVER SESSÃO EXISTENTE\n[8] SAIR')
    print('-' * 28)

    choice = read_numbers('Escolha uma opção:\n>>> ')

    return choice


def merge_sort(sessoes, chave):
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
    """

    with open('sessoes.txt', 'r') as file:
        sessoes = file.readlines()
        
    sessoes = [eval(sessao) for sessao in sessoes]
    return sessoes


def escrever_Arquivo(sessoes):
    """
    """

    with open('sessoes.txt', 'w') as file:
        for sessao in sessoes:
            file.write(f'{sessao}\n')


def read_numbers(msg, test=False):
    """
    Função para ler apenas números.
    """

    while True:
        try:
            num = str(input(msg))

        except EOFError:
            print('\033[31mERRO! Por favor, digite um número inteiro válido.\033[m')

        else:            
            if num[0] != '0':
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
            return nome.strip().capitalize()
        