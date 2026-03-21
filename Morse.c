#include <stdio.h>
#include <string.h>

#define MAX 200

// tabela de letras
char letras[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //cria uma string com o alfabeto

char *morse[] = { //cria a string com o codigo de cada letra  
".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
"-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-",
"..-","...-",".--","-..-","-.--","--.."
};


char traduzNormal(char *codigo){ // traduz letra normal - recebe codigo digitado pelo usuario  e retorna char 
    for(int i = 0; i < 26; i++){
        if(strcmp(codigo, morse[i]) == 0){ // compara duas strings, se forem iguais retorna 0. ve se o que foi digitado pelo usuario realmente existe no alfabeto morse 
            return letras[i]; //se existir mesmo, retorna a letra daquele codigo 
        }
    }
    return '?'; //se nao encontrar nenhuma letra, retorna ?
}

void traduzCorrompido(char *prefixo){ //vai verificar a letra corrompida - vai receber prefixo e retornar char 
    printf("[");
    for(int i = 0; i < 26; i++){
        if(strncmp(morse[i], prefixo, strlen(prefixo)) == 0){ //compara o que existe no alfabeto morse com o prefixo digitado e mostra o tamanho do prefixo
            printf("%c", letras[i]); //imprime as letras que começam com aquele prefixo
        }
    }
    printf("]");
}

int main(){

    char entrada[MAX]; //string pode ter no maximo 200 caracteres 
    fgets(entrada, MAX, stdin); //le a linha toda pois o codigo deve ser digitado com espaços entre as letras codificadas
	entrada[strcspn(entrada, "\n")] = '\0';
	
    char *token = strtok(entrada, " "); //separa a string pelo espacos - cada espaco inicia uma letra nova 
    int espacos = 0;

    while(token != NULL){ 

        int tamanho = strlen(token); // tamanho da string 

        
        if(token[tamanho-1] == '*'){ // verifica se tem * - "se o ultimo digito for *
            token[tamanho-1] = '\0'; // remove *
            traduzCorrompido(token); //depois da remocao, ve quiais letras começam com aquele codigo
        }
        else{
            printf("%c", traduzNormal(token)); //imprime as letras 
        }

        token = strtok(NULL, " ");

        
        if(token == NULL) break; //se o proximo token for vazio, fim do loop - fim da palavra 

        if(strlen(token) == 0){
            printf(" ");
            token = strtok(NULL, " ");
        }
    }

    printf("\n");

    return 0;
}