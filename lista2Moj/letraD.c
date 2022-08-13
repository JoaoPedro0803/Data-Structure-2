#include <stdio.h>
#include <stdlib.h>

int main(void){
    int *v = malloc(50000*sizeof(int));
    int contador, tam = 0;
    while(scanf(" %d", &v[tam]) != EOF){
        tam++;
    }
    insertionSortHigh(v, 0, tam-1);
    for(contador = 0; contador < tam; contador++){
        printf("%d ", v[contador]);
    }
    free(v);
}

void insertionSortHigh(int *v, int l, int r){
    int i, t;
    for(i = r; i > l; i--){
        if(v[i] < v[i-1]){
            t = v[i -1];
            v[i-1] = v[i];
            v[i] = t;
        }
    }
    for(i = l+2; i <= r; i++){
        int aux = v[i];
        int j = i-1;
        while (aux < v[j]){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = aux;
    }
}