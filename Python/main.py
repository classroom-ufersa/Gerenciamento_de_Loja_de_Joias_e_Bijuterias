from projeto import menu, ler_Arquivo
from sessoes import *
from acessorios import *

Sessoes = ler_Arquivo()
opcao = 0

while True:    
    opcao = menu()

    if opcao == 1:
        adicionar_Acessorios_Sessao(Sessoes) 
    
    elif opcao == 2:
        adiconar_Sessao(Sessoes)
    
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

print('\n8💎 Obrigado por usar o nosso sistema!💎')
