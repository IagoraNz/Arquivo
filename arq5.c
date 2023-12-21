#include <stdio.h>
#include <conio.h>
#include <string.h>

#define string(c) (c >= 'a' && c <= 'z') ? (c - 32) : (c)
#define tamanho 100

int verificastr(char c){
    if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
        return 1;
    }
    else{
        return 0;
    }
}

void preenchestr(char string[]){
    char c;
    int i = 0;

    printf("Digite uma string: ");
    do{
        do{
            c = getch();
            if(verificastr(c) == 1){
                printf("%c", c);
                string[i] = c;
                i++;

            }else if(c == '\b'){

                printf("\b \b");
                string[i] = '\0';
                i--;
            
            }
            string[i] = '\0';

        }while(verificastr(c) == 1);
    }while(c != 13);
}

void criartxt(char string[]){
    FILE *arq;

    arq = fopen("strrepetida.txt","w");

    fputs(string,arq);

    fclose(arq);
}

void repeticao(char string[]){
    int tam = strlen(string), rep, c, i, j;

    for(i = 0; i < tam; i++){
        rep = 0; c = 1;
        for(j=0;j < tam;j++){
            if((string(string[i])) == (string(string[j]))  && i != j){
                rep++;
            }
        }
        for(j = 0;j < i;j++){
            if((string(string[i])) == (string(string[j]))  && i != j){
                c=0;
            }
        }
        if(rep > 0 && c != 0){
            printf("\nA letra %c se repete %d vezes no arquivo", string[i],rep);
        }
    }
}

int main(){

    char string[tamanho];

    preenchestr(string);
    criartxt(string);
    repeticao(string);

    return 0;
}