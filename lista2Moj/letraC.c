#include <stdio.h>
#include <stdlib.h>

int main(void){
    int *v = malloc(1000*sizeof(int));
    int contador, tam = 0;
    while(scanf(" %d", &v[tam]) != EOF){
        tam++;
    }
    insertionSortSlow(v, 0, tam-1);
    for(contador = 0; contador < tam; contador++){
        printf("%d ", v[contador]);
    }
    free(v);
}
void insertionSortSlow(int *v, int l, int r){
    int i, j, t;
    for(i = l+1; i <= r; i++){
        for(j = i; j > l; j--){
            if(v[j-1] > v[j]){
                t = v[j-1];
                v[j-1] = v[j];
                v[j] = t; 
            }
        }
    }
}