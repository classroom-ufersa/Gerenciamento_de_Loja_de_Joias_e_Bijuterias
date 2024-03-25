def menu():
    """
    """
    print('=-' * 14)
    print(' LOJA DE JOIAS E BIJUTERIAS')
    print('=-' * 14)
    print('[1] ADICIONAR ACESSÓRIO\n[2] ADICIONAR NOVA SESSÃO\n[3] BUSCAR ACESSÓRIO\n'
          '[4] VER TODAS AS SESSÕES E A ACESSÓRIOS\n[5] REALIZAR VENDA DE ACESSÓRIOS\n'
          '[6] REMOVER ACESSÓRIO\n[7] REMOVER SESSÃO EXISTENTE\n[8] SAIR')
    print('-' * 28)

    choice = int(input('Escolha uma opção:\n>>> '))

    return choice

def ler_Arquivo():
    """
    """

    