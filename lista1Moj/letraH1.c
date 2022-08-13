#include <stdlib.h>
#include <stdio.h>

void soma_imprime() {
    char b [101];
    int soma = 0;
    scanf(" %s", b);
    int i = 0;
    while (b[i] != '\0') {
        if (b[i] >= '0' && b[i] <= '9') {
            soma += b[i] - '0';
        }
        i++;
   }
   printf("%d\n", soma);
}

int main (){
    int t;
    int i;
    scanf(" %d", &t);
    for (i = 0; i < t; i++) {
        soma_imprime();
    }
    return 0;
}