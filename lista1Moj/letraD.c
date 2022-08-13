#include <stdio.h>
#include <stdlib.h>

int main (){
    char n1[4];
    int aux = 0;
    int triagem;
    int ret, contaSim = 0;
    while (aux < 10) {
        scanf(" %s", n1);
        if(n1[0] == 's'){
            contaSim++;
            if (contaSim >= 2) triagem=1;
        }
        aux++; 
    }
    printf("%d", triagem);
    return 0;
}