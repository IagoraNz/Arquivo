#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define maxtam 100
#define tamdata 11

typedef struct {
    char nome[maxtam];
    char nascimento[tamdata];
} Pessoa;

void calc(const char *nascimento, char *idade){

    time_t t = time(NULL);
    
    struct tm tmAtual = *localtime(&t);
    
    int diaNasc, mesnasc, anonasc;
    sscanf(nascimento, "%d/%d/%d", &diaNasc, &mesnasc, &anonasc);

    int idadeemanos = tmAtual.tm_year + 1900 - anonasc;

    if(tmAtual.tm_mon + 1 < mesnasc || (tmAtual.tm_mon + 1 == mesnasc && tmAtual.tm_mday < diaNasc)){
        idadeemanos--;
    }

    sprintf(idade, "%d", idadeemanos);
}

void idade(const char *arqe, const char *arqs){

    FILE *arquivoEntrada = fopen(arqe, "r");
    FILE *arquivoSaida = fopen(arqs, "w");

    if(arquivoEntrada == NULL || arquivoSaida == NULL){
        printf("Erro ao abrir os arquivos.\n");
        exit(EXIT_FAILURE);
    }

    Pessoa pessoa;

    while(fscanf(arquivoEntrada, "%s %s", pessoa.nome, pessoa.nascimento) == 2){
        char idade[tamdata];
        calc(pessoa.nascimento, idade);
        fprintf(arquivoSaida, "%s %s\n", pessoa.nome, idade);
    }

    fclose(arquivoEntrada);
    fclose(arquivoSaida);
}

int main(){
    char nomeArquivoEntrada[maxtam];
    char nomeArquivoSaida[maxtam];

    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", nomeArquivoEntrada);

    printf("Digite o nome do arquivo de saída: ");
    scanf("%s", nomeArquivoSaida);

    idade(nomeArquivoEntrada, nomeArquivoSaida);

    printf("Arquivo de idades construído com sucesso!\n");

    return 0;
}
