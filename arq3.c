#include <stdio.h>
#include <string.h>

#define tam 100

void preencher(char str1[],char str2[]){
    printf("Digite uma palavra: ");
    fgets(str1, tam, stdin);

    printf("Digite uma segunda palavra: ");
    fgets(str2, tam, stdin);  
}

int main(){

    FILE *arq;
    char p1[tam], p2[tam], cat[tam];
    
    preencher(p1, p2);

    arq = fopen("arq1.txt","w");
    
    fputs(p1,arq);

    fclose(arq);

    arq = fopen("arq2.txt","w");

    fputs(p2,arq);
    
    fclose(arq);

    arq = fopen("arq3.txt","w");
    
    sprintf(cat,"%s%s",p1,p2);
    fputs(cat,arq);

    fclose(arq);

    arq = fopen("arq3.txt","r");

    while(fgets(cat,tam,arq) != NULL){
        printf("%s",cat);
    }

    fclose(arq);

    return 0;
}