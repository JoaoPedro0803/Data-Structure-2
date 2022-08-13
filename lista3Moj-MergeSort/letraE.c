// ordenar o vetorN primeiro pra fazer a busca, além de modificar o retorno da busca?
#include <stdio.h>
#include <stdlib.h>

int main (void){
    int n, m, numBusca, i;
    scanf(" %d %d", &n, &m);
    int *vetorN = malloc(n*sizeof(int));
    int *vetorPos = malloc(n*sizeof(int));
    for(i = 0; i < n; i++){
        scanf(" %d", &vetorN[i]);
        vetorPos[i] = i;
    }
    mergeSort(vetorN, vetorPos, 0, n-1);
    for(i = 0; i < m; i++){
        scanf(" %d", &numBusca);
        buscaBinaria(vetorN, vetorPos, n, numBusca);
    }
    free(vetorN);
    free(vetorPos);
}

void mergeSort(int *vetorN, int *vetorPos, int l, int r){
    if(l >= r) return;
    int meio = (r-l)/2 + l;          //para n dar overflow
    mergeSort(vetorN, vetorPos, l, meio);
    mergeSort(vetorN, vetorPos, meio+1, r);
    merge(vetorN, vetorPos, l, meio, r);
}

void merge(int *vetorN, int *vetorPos, int l, int m, int r){
    int *aux = malloc((r - l + 1) * sizeof(int));
    int *sup = malloc((r - l + 1) * sizeof(int));
    int i = l, j = m + 1, z = 0;

    while(i <= m && j <= r) {
        if(vetorN[i] < vetorN[j]) {
            sup[z] = vetorPos[i];
            aux[z++] = vetorN[i++];
        }
        else {
            sup[z] = vetorPos[j];
            aux[z++] = vetorN[j++];
        }
    }
    while(i <= m){
        sup[z] = vetorPos[i];
        aux[z++] = vetorN[i++];
    }
    while(j <= r){
        sup[z] = vetorPos[j];
        aux[z++] = vetorN[j++];
    }
    z = 0;
    for(i = l; i <= r; i ++){
        vetorPos[i] = sup[z];
        vetorN[i] = aux[z++];
    }
    free(aux);
    free(sup);
}

void buscaBinaria (int *vetorN, int *vetorPos, int r, int numBusca){
    int e = -1, d = r, m;
    while (e < d - 1){
        m = (e + d)/2;
        if (vetorN[m] < numBusca)
            e = m;
        else
            d = m;
    }
    if(vetorN[d] == numBusca)
        printf("%d\n", vetorPos[d]);
    else
        printf("%d\n", -1);
}

