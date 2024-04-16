# Tópicos
###  **[[1]](#listas-encadeadas-simples)** Linguagem C: Listas encadeadas
### **[[2]](#linguagem-c-lista-de-funções)** Lista de Funções
#### **📌 TAD Sessão**
- [Criar Sessão](#função-de-criar-sessão)
- [Inserir Sessão](#função-de-inserir-sessão)
- [Listar Sessões](#função-de-listar-sessões)
- [Adicionar Acessório](#função-de-adicionar-acessório)
- [Remover Sessão](#funçao-para-remover-sessão)
- [Remover Acessório](#funçao-para-remover-acessório)
- [Realizar Venda](#funçao-para-realizar-venda)
- [Buscar Acessório](#função-para-buscar-acessório)
- [Salvar Dados](#função-para-salvar-dados)
- [Ler Dados Salvos](#função-para-ler-dados-salvos)
- [Merge Sort](#função-para-merge-sort)
#### **📌 TAD Acessório**
- [Criar Acessório](#função-de-criar-acessório)
- [Inserir Acessório](#função-de-inserir-acessório)
#### **📌 TAD Funções**
- [Menu](#função-do-menu)
- [Pressione Enter](#função-pressione-enter)
- [Número Inteiro](#função-de-tratativa-inteiro)
- [Número Float](#função-de-tratativa-float)
- [Contém Apenas Letras](#funções-de-tratativa-string)
- [Maiúsculo String](#funçao-de-tratativa-maiusculo)
- [Validar Opção](#funçao-de-validar-opção)
---
# Listas encadeadas simples
Optamos por utilizar listas encadeadas em c, porque achamos mais simples e eficientes para nosso projeto.
##  Vantagens
* Como vantagens vimos sua eficiência na remoção e adição de dados, além da sua praticidade na realocação de memória tendo em vista que listas não precisa de realocação de memória.
## Desvantagens
* Como desvantagens temos seu acesso sequencial diminuindo seu desempenho e também listas encadeadas podem consumir mais memória do que outras estruturas, pois é necessário armazenar um ponteiro adicionar para cada novo elemento.

# Linguagem C: Lista de Funções 

### Função de `Criar sessão`
```
Sessao *criar_sessao(void);
```
* Descrição: 

### Função de `Inserir Sessão`
```
Sessao *inserir_sessao(Sessao *s);
```
* Descrição: está função pedir ao usuário para digitar os dados da sessão e em seguida criar o novo nó da lista e adicionar a sessão

### Função de `Listar Sessões`
````
void listar_sessoes(Sessao *inicio);
````
* Descrição: está função é responsável por imprimir todos os dados das sessões enquanto a sessão for diferente de NULL, receber como parâmetro a lista de sessões.

### Função de `Adicionar Acessório`
````
void adicionar_acessorio(Sessao *inicio, char nome_sessao[], Acessorio *novo_acessorio);
````
* Descrição: essa função é responsável por adicionar o acessório a sua sessão correspondente, ela tem como parâmetro a lista de sessões o nome do da sessão que desejar adicionar o acessório e o nó onde está o acessório que vai ser adicionado.


### Funçao para `Remover Sessão`
````
void remover_sessao(Sessao **inicio);
````
* Descrição: essa função é semelhante a de buscar acessório, receber a listas de sessões, perguntar ao usuário qual sessão desejar remover e em seguida faz a busca sequencial novamente. essa função faz uso de ponteiro duplo para que a modificação feita dentro da função reflita na variável original, se fosse um ponteiro simples isso não seria possivel.

### Funçao para `Remover Acessório`
````
void remover_acessorio(Sessao *sessao);
````
* Descrição: essa função receber a lista de sessões, perguntar ao usuário qual sessão ele desejar remover acessório em seguida pedir ao usuário o nome do acessório depois disso faz uma buscar sequencial dentro da lista de acessórios até encontrar, retornar uma mensagem caso não seja encontrado o acessório.

### Funçao para `Realizar Venda`
````
void realizar_venda(Sessao *sessao);
````
* Descrição: função responsável por realizar venda de acessórios, semelhante a todas as outras receber a lista de sessões como parâmetro verificar se o acessório existe dentro da sessão, se existir perguntar a quantidade a ser vendida. só é possível vender um acessorio se a quantidade for menor ou igual a quantidade cadastrada.

### Função para `Buscar Acessório`
````
void buscar_acessorio(Sessao *inicio);
````
* Descrição: essa função receber a lista de sessões, perguntar ao usuário qual sessão ele desejar remover acessório em seguida pedir ao usuário o nome do acessório depois disso faz uma buscar sequencial dentro da lista de acessórios até encontrar, retornar uma mensagem caso não seja encontrado o acessório.

### Função para `Salvar Dados`
````
void salvar_dados(Sessao *inicio);
````
* Descrição: Esta função é responsável por salvar os dados das sessões e seus acessórios em um arquivo de texto chamado "dados_loja.txt". Primeiro, ela abre o arquivo em modo de escrita. Em seguida, percorre todas as sessões na lista, escrevendo o nome e a descrição da sessão no arquivo. Para cada sessão, também percorre todos os seus acessórios, escrevendo seus detalhes (nome, tipo, preço e quantidade em estoque) no arquivo. Ao finalizar, fecha o arquivo.

### Função para `Ler Dados Salvos`
````
Sessao *ler_dados_salvos();
````
* Descrição: Esta função lê os dados salvos anteriormente no arquivo "dados_loja.txt" e os carrega de volta na memória. Primeiro, abre o arquivo em modo de leitura. Em seguida, percorre cada linha do arquivo. Se a linha contiver informações sobre uma sessão, cria uma nova sessão na memória e a adiciona à lista de sessões. Se a linha contiver informações sobre um acessório, cria um novo acessório e o adiciona à sessão atual. Ao finalizar a leitura do arquivo, fecha-o e retorna a lista de sessões carregada com os dados.

### Função para `Merge Sort`
````
void mergeSort(Sessao **head);
````
* Descrição: Esta função implementa o algoritmo de ordenação Merge Sort para ordenar a lista de sessões. Ela recebe um ponteiro para o início da lista de sessões e ordena essa lista em ordem alfabética com base nos nomes das sessões. Ela utiliza as funções merge() e split() para dividir a lista em partes menores, ordenar cada parte e, em seguida, mesclar as partes ordenadas para obter a lista final ordenada.

### Função de `Criar Acessório`
````
Acessorio *criar_acessorio(void);
````
* Descrição: essa função é responsável por criar a lista de aceesórios vazia, tem como retorno NULL.

### Função de `Inserir Acessório`
````
Acessorio *Inserir_acessorio(Acessorio *a);
````
* Descrição: Esta função insere um novo acessório na lista de acessórios existente. Solicita ao usuário o nome, tipo, preço e quantidade do acessório. Verifica se o nome e o tipo do acessório contêm apenas letras. Em seguida, aloca memória para um novo acessório, preenche seus detalhes e o insere no início da lista de acessórios. Retorna o ponteiro para o novo acessório.

### Função do `Menu`
````
void menu();
````
* Descrição: Exibe um menu com opções para o usuário.

### Função `Pressione enter`
````
void pressione_enter();
````
* Descrição: função que esperar até que o usuário pressione enter

### Função de `tratativa inteiro`
````
int numero_inteiroc();
````
* Descrição: Solicita ao usuário que digite um número inteiro e valida se a entrada contém apenas números. Retorna o número inteiro digitado.

### Função de `tratativa float`
````
float numero_floatc();
````
* Descrição: Solicita ao usuário que digite um número float e valida se a entrada contém apenas números e um ponto decimal. Retorna o número float digitado.

### Função de `tratativa string`
````
int contem_apenas_letras(char *str);
````
* Descrição: Verifica se uma string contém apenas letras e espaços. Retorna 1 se contém apenas letras, caso contrário, retorna 0

### Função de `tratativa maiusculo`
````
void maiusculo_string(char *str);
````
* Descrição: receber uma string qualquer como parâmetro e retornar ela em maiusculo.

### Função de `validar opção`
````
int valida_opcao();
````
* Descrição: Recebe a entrada do usuário para escolher uma opção do menu, verifica se é um número válido e retorna a opção escolhida.