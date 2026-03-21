#include <stdio.h>
#include <string.h>

#define MAX 200

// tabela de letras
char letras[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

char *morse[] = {
".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
"-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-",
"..-","...-",".--","-..-","-.--","--.."
};

// traduz código normal
char traduzNormal(char *codigo){
    for(int i = 0; i < 26; i++){
        if(strcmp(codigo, morse[i]) == 0){
            return letras[i];
        }
    }
    return '?';
}

// traduz código corrompido
void traduzCorrompido(char *prefixo){
    printf("[");
    for(int i = 0; i < 26; i++){
        if(strncmp(morse[i], prefixo, strlen(prefixo)) == 0){
            printf("%c", letras[i]);
        }
    }
    printf("]");
}

int main(){

    char entrada[MAX];

    // leitura da entrada
    fgets(entrada, MAX, stdin);
    entrada[strcspn(entrada, "\n")] = '\0';

    int i = 0;
    char codigo[10];
    int j = 0;

    while(entrada[i] != '\0'){

        if(entrada[i] != ' '){
            codigo[j++] = entrada[i];
        } 
        else {
            codigo[j] = '\0';

            if(j > 0){
                // verifica se é corrompido
                if(codigo[j-1] == '*'){
                    codigo[j-1] = '\0';
                    traduzCorrompido(codigo);
                } else {
                    printf("%c", traduzNormal(codigo));
                }
                j = 0;
            }

            // contar espaços
            int count = 0;
            while(entrada[i] == ' '){
                count++;
                i++;
            }

            // se tiver 2 espaços → nova palavra
            if(count == 2){
                printf(" ");
            }

            continue;
        }

        i++;
    }

    // processar último código
    if(j > 0){
        codigo[j] = '\0';

        if(codigo[j-1] == '*'){
            codigo[j-1] = '\0';
            traduzCorrompido(codigo);
        } else {
            printf("%c", traduzNormal(codigo));
        }
    }

    printf("\n");

    return 0;
}