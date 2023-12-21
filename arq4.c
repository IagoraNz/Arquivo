#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define tam 100

void preencher(char nome[],int *ano,int *mes,int *dia){

    printf("Informe o seu nome: ");
    gets(nome);

    printf("Informe a sua data de nascimento (dia/mes/ano): ");
    scanf("%d %d %d", dia, mes, ano);
}

void nomedata(char nome[],int ano,int mes,int dia){
    FILE *arq;
    arq = fopen("nomedata.txt","a");
    
    fprintf(arq,"%s %02d/%02d/%04d",nome,dia,mes,ano);

    fclose(arq);
}

void nomeidade(char nome[],int idade){
    FILE *arq;
    arq = fopen("nomeIdade.txt","a");
    
    fprintf(arq,"%s %02d",nome,idade);

    fclose(arq);
}

int calcidade(char hoje[],int ano,int mes,int dia){

    int dataHj = atoi(hoje), dataNasc, anodeidade;
    char nasc[8];
    
    sprintf(nasc,"%04d%02d%02d",ano,mes,dia);
    dataNasc = atoi(nasc);

    anodeidade = dataHj - dataNasc;

    return anodeidade/10000; 
}

void leitura(){

    FILE *arq;
    char c;
    arq = fopen("nomedata.txt","r");

    printf("Primeiro arquivo\n");
    while(!(feof(arq))){
        c = fgetc(arq);
        printf("%c", c);
    }

    fclose(arq);

    printf("\nSegundo arquivo\n");
    arq = fopen("nomeIdade.txt","r");

    while(!(feof(arq))){
        c = fgetc(arq);
        printf("%c", c);
    }

    fclose(arq);
}

int main(){

    char nome[tam], hoje[8];
    int ano, mes, dia, idade;
    
    time_t mytime;
    mytime = time(NULL);

    struct tm tm = *localtime(&mytime);

    sprintf(hoje,"%04d%02d%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    printf("Data: %04d/%02d/%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

    preencher(nome,&ano,&mes,&dia);

    nomedata(nome,ano,mes,dia);

    idade = calcidade(hoje,ano,mes,dia);

    nomeidade(nome,idade);

    leitura();

    return 0;
}