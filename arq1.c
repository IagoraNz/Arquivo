#include <stdio.h>
#include <stdlib.h>

#define tam 20

int contador(char palavra[]){

    int cont = 0, i;

    for(i = 0; palavra[i] != '\0'; i++){
        if((palavra[i] >= 'a' && palavra[i] <= 'z') || (palavra[i] >= 'A' && palavra[i] <= 'Z')){
            cont++;
        }
    }
    return cont;
}

void arquivo(char palavra[], const char *nomeArquivo){

    FILE *arquivo = fopen(nomeArquivo, "w");
    
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    fprintf(arquivo, "%s", palavra);
    fclose(arquivo);
}

int main(){

    char palavra[100];

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    arquivo(palavra, "palavra.txt");

    int t = contador(palavra);
    printf("A palavra tem %d letras.\n", t);

    return 0;
}
