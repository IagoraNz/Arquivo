#include <stdio.h>
#include <stdlib.h>

#define maxtam 100

void mesclarArquivos(const char *arq1, const char *arq2, const char *arq3){

    FILE *arquivo1 = fopen(arq1, "r");
    FILE *arquivo2 = fopen(arq2, "r");
    FILE *arquivoResultado = fopen(arq3, "w");

    if (arquivo1 == NULL || arquivo2 == NULL || arquivoResultado == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        exit(1);
    }

    char linha1[maxtam], linha2[maxtam];

    while(fgets(linha1, maxtam, arquivo1) != NULL || fgets(linha2, maxtam, arquivo2) != NULL){ //Enquanto não chegar ao final dos arquivos
        if(linha1[0] != '\0'){
            fprintf(arquivoResultado, "%s", linha1);
        }
        if(linha2[0] != '\0'){
            fprintf(arquivoResultado, "%s", linha2);
        }
    }

    fclose(arquivo1);
    fclose(arquivo2);
    fclose(arquivoResultado);
}

int main(){

    char arquivo1[maxtam];
    char arquivo2[maxtam];
    char arquivo3[maxtam];

    printf("Digite o nome do primeiro arquivo: ");
    scanf("%s", arquivo1);

    printf("Digite o nome do segundo arquivo: ");
    scanf("%s", arquivo2);

    printf("Digite o nome do arquivo resultado: ");
    scanf("%s", arquivo3);

    mesclarArquivos(arquivo1, arquivo2, arquivo3);

    printf("Arquivos mesclados com sucesso!\n");

    return 0;
}
