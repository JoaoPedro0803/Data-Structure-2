#include <stdio.h>
#include <stdlib.h>

int main (){
    int quant;
    scanf(" %d", &quant);
    int v[quant];
    int i, j, k;
    for (i = 0; i < quant; i++){
        scanf(" %d", &v[i]);
    }
    ordena(v, quant);
    for (j = 0; j < quant; j++){
    }
    return 0;
}

int buscaBinaria(int *vet, int chave, int inicio, int fim){
    int meio;
    if(inicio <= fim){
        meio = (inicio + fim)/2;
        if(chave == vet[meio]){
            return 1;
            //repete++;
        }else{
            if (chave < vet[meio])
                return buscaBinaria(vet, chave, inicio, meio-1);
            else 
                return buscaBinaria(vet, chave, meio + 1, fim);
        }
    }
    return -1;
}

void ordena(int *v, int n){
    int elem, i, j;
    for(i=0; i<n; i++){
        elem = v[i];
        for(j = i-1 ; j >= 0 && v[j]>elem; j--){
            v[j+1] = v[j];
        }
        v[j+1] = elem;
    }
    /*for (i = 0; i <n; i++){
        printf("%d", v[i]);
    }*/
}

