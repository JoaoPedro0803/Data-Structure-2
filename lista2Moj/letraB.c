#include <stdlib.h>
#include <stdio.h>

void selectionSort(int *v, int l, int r){
    int i, j, t;
    for(i = 0; i < r; i++){
        int min = i;
        for(j = i+1; j <= r; j++){
            if(v[j] < v[min]){
                min = j;
            }
        }
        if(i != min){
            t = v[i];
            v[i] = v[min];
            v[min] = t;                                        
        }
    }
}

int main() {
    int *v = malloc(1000*sizeof(int));
    int contador, tam = 0;
    while(scanf(" %d", &v[tam]) != EOF){
        tam++;
    }
    selectionSort(v, 0, tam-1);
    for(contador = 0; contador < tam; contador++){
        printf("%d ", v[contador]);
    }
    free(v);
    return 0;
}