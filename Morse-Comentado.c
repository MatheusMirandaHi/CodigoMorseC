#include <stdio.h>  // inclui biblioteca padrão de entrada/saída
#include <string.h>  // inclui biblioteca para manipulação de strings

#define MAX 200  // define constante MAX com valor 200

// tabela de letras
char letras[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";  // array com alfabeto

char *morse[] = {  // array de ponteiros com códigos Morse para cada letra
".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
"-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-",
"..-","...-",".--","-..-","-.--","--.."
};

// traduz código normal
char traduzNormal(char *codigo){  // função que converte Morse para letra
    for(int i = 0; i < 26; i++){  // itera sobre as 26 letras
        if(strcmp(codigo, morse[i]) == 0){  // se código Morse bate
            return letras[i];  // retorna a letra correspondente
        }
    }
    return '?';  // retorna '?' se não encontrar
}

// traduz código corrompido
void traduzCorrompido(char *prefixo){  // função para códigos incompletos
    printf("[");  // imprime abertura de colchete
    for(int i = 0; i < 26; i++){  // itera sobre as 26 letras
        if(strncmp(morse[i], prefixo, strlen(prefixo)) == 0){  // se prefixo bate
            printf("%c", letras[i]);  // imprime letra correspondente
        }
    }
    printf("]");  // imprime fechamento de colchete
}

int main(){  // função principal

    char entrada[MAX];  // array para armazenar entrada do usuário

    // leitura da entrada
    fgets(entrada, MAX, stdin);  // lê até MAX caracteres da entrada
    entrada[strcspn(entrada, "\n")] = '\0';  // remove quebra de linha

    int i = 0;  // índice para percorrer entrada
    char codigo[10];  // array para armazenar código Morse atual
    int j = 0;  // índice para construir código

    while(entrada[i] != '\0'){  // enquanto não chegar no fim da string

        if(entrada[i] != ' '){  // se não for espaço
            codigo[j++] = entrada[i];  // adiciona caractere ao código
        } 
        else {  // se for espaço
            codigo[j] = '\0';  // finaliza string do código

            if(j > 0){  // se há código para processar
                // verifica se é corrompido
                if(codigo[j-1] == '*'){  // se último caractere é '*'
                    codigo[j-1] = '\0';  // remove o '*'
                    traduzCorrompido(codigo);  // chama função Morse corrompido
                } else {  // se código está completo
                    printf("%c", traduzNormal(codigo));  // traduz normalmente
                }
                j = 0;  // reseta índice do código
            }

            // contar espaços
            int count = 0;  // contador de espaços
            while(entrada[i] == ' '){  // enquanto houver espaços
                count++;  // incrementa contador
                i++;  // próximo caractere
            }

            // se tiver 2 espaços → nova palavra
            if(count == 2){  // se foram 2 espaços
                printf(" ");  // imprime espaço entre palavras
            }

            continue;  // volta para próxima iteração
        }

        i++;  // próximo caractere
    }

    // processar último código
    if(j > 0){  // se há código pendente
        codigo[j] = '\0';  // finaliza string

        if(codigo[j-1] == '*'){  // se código está corrompido
            codigo[j-1] = '\0';  // remove '*'
            traduzCorrompido(codigo);  // chama função Morse corrompido
        } else {  // se código está completo
            printf("%c", traduzNormal(codigo));  // traduz normalmente
        }
    }

    printf("\n");  // imprime quebra de linha

    return 0;  // retorna 0 (sucesso)
}