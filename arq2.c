#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam 20

void inverter(const char *palavra, const char *arq){

    FILE *arquivo = fopen(arq, "w");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(EXIT_FAILURE);
    }

    int i, j = 0, comp = strlen(palavra);
    char inverso[tam];

    for(i = comp - 1; i >= 0; i--){
        inverso[j] = palavra[i];
        j++;
    }

    inverso[j] = '\0';

    printf("\nPalavra invertida: %s\n", inverso);

    fprintf(arquivo, "%s", inverso);
    fclose(arquivo);
}

int main(){

    char palavra[tam];

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    inverter(palavra, "palavra.txt");

    return 0;
}
