#include <stdio.h>
#include <stdlib.h>

int main(){

    int size; 
    int i; 
    int soma = 0;
    scanf(" %d", &size);
    int linhas[size];    
    for(i =0; i < size; i++){
        scanf(" %d", &linhas[i]);
        soma += linhas[i] ;
    }
    printf("%d", soma);
    return 0;
}

/*
3
4
5
6
15

*/