#include <stdio.h>
#include <stdlib.h>

#define tam 20

int main(){

    FILE *arq;

    char palavra[tam];

    arq = fopen("arq1.txt", "w");

    if(arq == NULL){
        printf("Erro na abertura do arquivo!");
        exit(1);
    }

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    fprintf(arq, "%s", palavra);

    fclose(arq);

    fopen("arq1.txt", "r");

    if(arq == NULL){
        printf("Erro na abertura do arquivo!");
        exit(1);
    }

    int i = 0;

    while(palavra[i] != '\0'){
        i++;
    }

    printf("A palavra possui %d letras", i);

    fclose(arq);

    return 0;
}