from projeto import *
from projeto.sessoes import *
from projeto.acessorios import *

Sessoes = []
choice = 0

while True:
    choice = menu()

    if choice == 1:
        adicionar_Acessorios_Sessao(Sessoes)
    
    elif choice == 2:
        adiconar_Sessao(Sessoes)
    
    elif choice == 3:
        buscar_Acessorio(Sessoes)

    elif choice == 4:
        ver_Sessoes_Acessorios(Sessoes)

    elif choice == 5:
        realizar_Venda(Sessoes)

    elif choice == 6:
        remover_Acessorio(Sessoes)

    elif choice == 7:
        remover_Sessao(Sessoes)

    elif choice == 8:
        break

    else:
        print('Opção inválida!')
