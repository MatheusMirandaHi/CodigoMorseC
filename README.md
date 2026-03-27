# Projeto 1 – Código Morse

Disciplina: Algoritmos e Programação II
Curso: Ciência da Computação – Turma 02A – Campus Alphaville
Universidade: Universidade Presbiteriana Mackenzie

## Integrantes

- Nome: Isabella Rubio Venancio - RA 10778364
- Nome: Matheus Alves de Miranda - RA 10746221

# Descrição do Projeto

Este projeto consiste no desenvolvimento de um programa em linguagem C capaz de traduzir mensagens escritas em Código Morse para o alfabeto latino.

A entrada do programa consiste em uma linha contendo sequências de pontos (`.`) e traços (`-`) que representam letras em código Morse. As letras são separadas por um espaço e palavras distintas são separadas por dois espaços consecutivos.

O programa também deve tratar casos de **letras corrompidas**. Quando um código Morse termina com o caractere `*`, isso indica que os símbolos finais podem ter sido perdidos. Nesse caso, o programa deve listar todas as letras possíveis cujo código Morse começa com o prefixo fornecido.

As possíveis letras devem ser exibidas entre colchetes (`[]`) e em ordem alfabética.


# Compilação

Para compilar o programa utilizando o compilador GCC, execute o seguinte comando no terminal:

gcc -o morse morse.c

Esse comando irá gerar um executável chamado `morse`.

# Execução

Após a compilação, execute o programa com o comando:

./morse

O programa aguardará que o usuário digite a mensagem em código Morse. Após pressionar **Enter**, a tradução será exibida na tela.


# Exemplos de Entrada e Saída

## Exemplo 1

Morse: `--- .-* .- -- ..- -. -.. ---`

Saída : `O[AJLPRW]A MUNDO `

## Exemplo 2
Morse : `.... . .-.. .-.. ---  -- ..- -. -.. ---`

Saída : `HELLO MUNDO` 

## Exemplo 3
Morse : `.... . .-* .-.. --- -- ..- -. -..* ---` 

Saída : `HE[AJLPRW]LO MUN[BDX]O` 
 
## Exemplo 4
Morse : `.-.. .. -. --. ..- .- --. . --  -.-.` 

Saída: `LINGUAGEM C` 

## Exemplo 5
Moorse : `...* ---`

Saida: `[HSV]O` 


# Observações

* O programa utiliza uma tabela contendo os códigos Morse correspondentes a cada letra do alfabeto.
* Letras íntegras são traduzidas diretamente utilizando comparação de strings.
* Letras corrompidas são tratadas verificando quais códigos Morse começam com o prefixo fornecido.
* A saída final apresenta as palavras separadas por um único espaço, conforme especificado no enunciado do projeto.
