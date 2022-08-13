#include <stdio.h>
#include <stdlib.h>

int main (void){
    int n, i, m;
    scanf(" %d %d", &n, &m);
    int *vetorM = malloc(m*(sizeof(int)));
    int *vetorN = malloc(n*(sizeof(int)));
    int *vetorPos = malloc(m*(sizeof(int))); // o vetor que vai retornar os indices tem q ter o msm tamanho que o vetor m, para ter as posicoes desejadas do vetor M
    for(i = 0; i < n; i++){
        scanf(" %d", &vetorN[i]);
    }
    for(i = 0; i < m; i++){
        scanf(" %d", &vetorM[i]);
    }
    buscaBinaria(n, m, vetorN, vetorM, vetorPos);
    for(i = 0; i < m; i++){
        printf("%d \n", vetorPos[i]);
    }  
    free(vetorM);
    free(vetorN);
    free(vetorPos);  
}

void buscaBinaria(int tamVetN, int tamVetM, int *vetorN, int *vetorM, int *posicao){
    int meio, esquerda, direita, j;
    for(j = 0; j < tamVetM; j++){
        esquerda = -1;
        direita = tamVetN;
        while(esquerda != (direita-1)){ 
            meio = (esquerda + direita)/2;
            if(vetorM[j] > vetorN[meio])
                esquerda = meio; 
            else
                direita = meio;
        }
        posicao[j] = direita;
    }
}