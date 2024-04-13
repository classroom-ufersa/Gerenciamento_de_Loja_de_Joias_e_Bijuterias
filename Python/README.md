# 1 - Listas e Dicionários
Optamos por usar listas e dicionários porque eles fornecem uma combinação ideal de flexibilidade, facilidade de uso e eficiência das funções. 
##  Vantagens
* Flexibilidade: Tanto listas quanto dicionários são estruturas de dados flexíveis em Python, permitindo armazenar e manipular dados de diferentes tipos de forma eficiente.
* Facilidade de uso: Python fornece uma sintaxe simples e intuitiva para trabalhar com listas e dicionários, tornando mais fácil para a implementação e atualizações do código.
* Adequação às necessidades do projeto: As características de listas e dicionários, se assemelham aos conteúdos vistos durante a 3º unidade da disciplina, como por exemplo, às Listas encadeadas. 
## Desvantagens
* Pesquisa linear: A busca por um elemento em uma lista requer uma busca linear, o que pode ser ineficiente para grandes conjuntos de dados.
* Memória extra: Os dicionários consomem mais memória do que as listas devido à necessidade de armazenar chaves adicionais.
# 2 - Principais Funções do projeto em Python

### Função de `Adicionar Sessão`  
```
def adiconar_Sessao(sessao):
```
* Descrição: Permite adicionar sessões a loja. Recebe como parâmetro a lista de todas as sessões cadastradas. Depois, é perguntado ao usuário qual é o nome da sessão e sua descrição associada. Além disso, verifica-se a existência de sessões com nomes iguais. Dessa forma, utlizamos a função `append()` para adicionar o Dicionário ao fim da lista contendo: { 'nome': nome, 'descricao': descricao, 'acessorios': [ ] }. Por fim, chamamos a função `merge_sort()` para ordenar a lista e atualizamos o arquivo de sessões.

### Função de `Adicionar Acessórios à Sessão`
```
def adicionar_Acessorios_Sessao(sessao):
```
* Descrição:  Esta função permite adicionar acessórios a uma sessão já cadastrada. Ela recebe como parâmetro a lista de todas as sessões cadastradas. Verifica se há sessões disponíveis e, em seguida, solicita o nome da sessão. Se a sessão é encontrada, permite adicionar acessórios usando a função `adicionar_Acessorio()`. Por fim, chamamos a função `merge_sort()` para ordenar a lista e atualizamos o arquivo de sessões.

### Função de `Remover Sessão`
```
def remover_Sessao(sessao):
```
* Descrição: Esta função remove sessões cadastradas do sistema. Recebe como parâmetro a lista de todas as sessões cadastradas. Verifica se há sessões disponíveis e solicita o nome da sessão a ser removida. Se a sessão é encontrada, é removida da lista e o arquivo de sessões é atualizado.

### Função de `Realizar Venda de Acessórios`
```
def realizar_Venda(sessao):
```
* Descrição: Esta função realiza a venda de acessórios de uma sessão. Recebe como parâmetro a lista de todas as sessões cadastradas. Verifica se há sessões disponíveis e solicita o nome da sessão onde a venda será realizada. Se a sessão é encontrada e possui acessórios, permite selecionar o acessório desejado e realizar a compra. Se o acessório cadastrado não possui estoque, o usuário pode pedir para repor o estoque desse acessório. Para isso, utilizamos a função `repor_Estoque()`. Por fim, atualizamos a quantidade de acessórios disponíveis e o arquivo de sessões.

### Função de `Ver Sessões e Acessórios`
```
def ver_Sessoes_Acessorios(sessao):
```
* Descrição: Recebe como parâmetro a lista de todas as sessões cadastradas. Se houver sessões disponíveis, imprime formatado o nome da sessão, sua descrição e os acessórios associados a ela, incluindo tipo, preço e quantidade em estoque. 

### Função de `Adicionar Acessório`
```
def adicionar_Acessorio(acessorio_sessao, sessao):
```
* Descrição: Essa função permite ao usuário preencher os dados referentes ao acessório. Recebe como 1º parâmetro a lista da sessão onde será adicionado o acessório. O 2º parâmetro é a lista de todas as sessões cadastradas. Solicita ao usuário o nome, tipo, preço e quantidade do acessório a ser cadastrado. É verificado se o nome do acessório informado já está cadastrado. O acessório é então adicionado à lista de acessórios da sessão e ordenado em ordem alfabética pelo nome usando o `merge_sort()`.

### Função de `Buscar Acessório`
```
def buscar_Acessorio(sessao, busca='', retornar=False):
```
* Descrição: Esta função realiza a busca por um acessório cadastrado. Recebe como parâmetros a lista de todas as sessões cadastradas, o nome do acessório a ser pesquisado (opcional) e um indicador booleano para retornar ou não um valor. Se nenhum nome for fornecido, solicita ao usuário o nome do acessório. Percorre a lista utilizando dois(2) `for():`, o 1º é referente as sessões e o 2º é referentes aos acessórios de cada sessão. Se o acessório for encontrado, exibe suas informações. Se o parâmetro retornar for `True`, retorna True se o acessório for encontrado e False caso contrário.

### Função de `Remover Acessório`
```
def remover_Acessorio(sessao):
```
* Descrição: : Esta função remove um acessório cadastrado. Recebe como parâmetro a lista de todas as sessões cadastradas. Solicita ao usuário o nome do acessório a ser removido e, se encontrado, remove o acessório da lista de acessórios da sessão utilizando a função `remove()`.

### Função de `Repor Estoque de Acessórios`
```
def remover_Acessorio(sessao):
```
* Descrição: **Função extra** para repor o estoque de um acessório. Recebe como parâmetro a lista do acessório que terá o estoque reposto e solicita ao usuário a quantidade a ser adicionada. Atualiza o estoque do acessório e exibe a quantidade atualizada.

### Função do `Menu do Programa`
```
def menu():
```
* Descrição:  Esta função exibe o menu principal do sistema. Exibe as opções enumeradas para o usuário, como adicionar acessório, adicionar nova sessão, buscar acessório, ver todas as sessões e acessórios, realizar venda de acessórios, remover acessório, remover sessão existente e sair do sistema. Retorna a opção escolhida pelo usuário.

### Função do `Merge Sort`
```
def merge_sort(sessoes, chave):
```
* Descrição: Esta função implementa o algoritmo de ordenação Merge Sort para ordenar sessões por nome. Recebe como parâmetros a lista de todas as sessões cadastradas ou apenas de uma sessão, e uma chave para indicar o critério de ordenação (nome).

### Função de `Ler Arquivo`
```
def ler_Arquivo():
```
* Descrição: Esta função é responsável por ler o arquivo de sessões salvas no formato .txt. Se o arquivo não existir, ele é criado. Em seguida, lê todas as linhas do arquivo e converte cada linha em um dicionário de sessão, utilizando a função eval(). Retorna uma lista de todas as sessões salvas no arquivo. Onde cada dicionário representa uma sessão com seus respectivos acessórios.

### Função de `Escrever no Arquivo`
```
def escrever_Arquivo(sessoes):
```
* Descrição: Esta função é responsável por escrever os dados do sistema no arquivo .txt. Recebe como parâmetro a lista de todas as sessões cadastradas e atualiza o arquivo `'sessoes.txt` com esses dados. Cada sessão é escrita em uma linha do arquivo no formato de dicionário convertido para string utilizando a função ´write()´. Onde cada linha do arquivo é representado por um dicionário da sessão com seus respectivos acessórios.

### Funções de `Tramento de Erros`
```
def leia_numero(msg, test=False):
def leia_numero_Float(msg):
def leia_nomes(msg):
```
* Descrição: Essas funções são responsáveis por ler entradas do usuário com tratamento de erros para garantir que apenas números inteiros, números decimais ou nomes sejam aceitos, respectivamente. Com exceção da função de ´leia_numero_Float´, todas utilizam blocos de exceções para capturar e lidar com possíveis exceções (erros do usuário) durante a execução do código.

### Funções de `Voltar ao Menu`
```
def voltar_Menu(nome):
```
* Descrição: Essa função sempre é utilizada depois da função ´leia_nomes(msg)´. Então é verificado se o nome retornado é 'voltar', indicando que o usuário deseja retornar ao menu principal. Para conseguir utilizar ela é necessário que o bloco de exceção ´KeyboardInterrupt´ capture o erro quando o usuário pressionar `Ctrl+C`
 Se for o caso, limpa a tela e retorna True.
