#include <stdio.h>
int main() {
    /*int numLido, i;
    int contadorNum = 0;
    do{
        i = scanf("%d", &numLido);

    } while(i != EOF);{
        contadorNum++;
    }
    printf("%d", contadorNum);*/
    
    // PRINTAR A QUANTIDADE DE NUMEROS LIDOS PELO SCANF F ANTESD O EOF 

    int n1, ret, i = 0;
    while ((ret = scanf("%d", &n1)) != EOF ) {
        i++;    
    }
    printf("%d", i);
    return 0;
}