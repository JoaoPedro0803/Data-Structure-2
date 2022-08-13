#include <stdio.h>
#include <stdlib.h>

/*typedef struct Item{
    int valor;
}Item;*/

void mergeSort(int *vetor, int l, int r){
    if(l >= r) return;
    int meio = (r-l)/2 + l;          //para n dar overflow
    mergeSort(vetor, l, meio);
    mergeSort(vetor, meio+1, r);
    merge(vetor, l, meio, r);
}

void merge(int *vetor, int l, int m, int r){
    int l1 = l, r1 = m, l1i = l1;
    int l2 = m+1, r2 = r, l2i = l2;

    int *c = malloc(sizeof(int)*(r-l+1));
    int ci = 0, lc = 0, rc = r-l;
    while(l1i <= r1 && l2i <= r2){
        if(vetor[l1i] < vetor[l2i]){
            c[ci++] = vetor[l1i++];
        }else{
            c[ci++] = vetor[l2i++];
        }
    }
    while(l1i <= r1){
        c[ci++] = vetor[l1i++];
    }
    while(l2i <= r2){
        c[ci++] = vetor[l2i++];
    }
    l1i = l;
    for(ci = 0; ci <= rc; ci++){
        vetor[l1i++] = c[ci];
    }
    free(c);
}

int main(void){
    int *vetor = malloc(50000*sizeof(int));
    int contador, tam = 0;
    while(scanf(" %d", &vetor[tam]) != EOF){
        tam++;
    }
    mergeSort(vetor, 0, tam-1);
    for(contador = 0; contador < tam; contador++){
        printf("%d ", vetor[contador]);
    }
    free(vetor);
}