from sessoes.sessoes import *
from acessorios.acessorios import buscar_Acessorio, remover_Acessorio
from projeto.projeto import ler_Arquivo, menu

Sessoes = ler_Arquivo()
opcao = 0

while True:    
    opcao = menu()

    if opcao == 1:
        adicionar_Acessorios_Sessao(Sessoes) 
    
    elif opcao == 2:
        adicionar_Sessao(Sessoes)
    
    elif opcao == 3:
        buscar_Acessorio(Sessoes)

    elif opcao == 4:
        ver_Sessoes_Acessorios(Sessoes)

    elif opcao == 5:
        realizar_Venda(Sessoes)

    elif opcao == 6:
        remover_Acessorio(Sessoes)

    elif opcao == 7:
        remover_Sessao(Sessoes)

    elif opcao == 8:
        break
    
    else:
        print('\033[31mOpção Inválida!\033[m')

print('\n💎 Obrigado por usar o nosso sistema!💎')
