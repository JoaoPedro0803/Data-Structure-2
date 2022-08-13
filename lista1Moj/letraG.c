#include <stdio.h>
#include <stdlib.h>

int main (){
    int *v = malloc(4);
    int aux, umn, tam = 0;
    while (scanf(" %d", &aux) == 1 && aux != 0){
        v = realloc(v, sizeof(int)*tam);
        v[tam-1] = aux;
        tam++;
    }
    scanf(" %d", &umn);
    fumn(v, umn, tam);
    return 0;
}

void fumn(int *v, int umn, int tam){
    int soma = 0, i = 0;
    if (tam == 0) return;
    while(soma < umn && i < tam){
        soma += v[i++];
    }
    fumn(&v[i], umn, tam-i);
    printf("%d\n", v[i-1]);
}
