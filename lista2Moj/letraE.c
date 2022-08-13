#include <stdio.h>
#include <stdlib.h>
#define codigo(A)(A.codigo)
#define less(A,B) (codigo(A) < codigo(B))
#define exch(A, B) {info t = B; B = A; A = t;}
#define cmpexch(A, B) {if(less(B, A)) exch(A, B);}

typedef struct info{
    int codigo;
    char instruction[16];
} info;

int main(void){
    int n, i, target; 
    // quantas linhas de instruções vc vai definir
    scanf(" %d", &n);
    
    info *vetor = malloc(n*sizeof(info));         // aloca o vetor que define as instrucoes e os codigos
    for(i = 0; i < n; i++){                         // preenche ele
        scanf(" %d %s", &vetor[i].codigo, vetor[i].instruction);
    }

    ordenaVetor(vetor, 0, n-1);

    while(scanf(" %d", &target) != EOF){
        buscaBinaria(vetor, 0, n-1, target);
    }

    free(vetor);
}

void ordenaVetor(info *vetor, int l, int r){
    int i;
    for(i = r; i > l; i--){
        if(less(vetor[i], vetor[i-1])){
            exch(vetor[i], vetor[i-1])
        }
    }
    for(i = l+1; i <= r; i++){
        int j = i - 1;
        info aux = vetor[j + 1]; 
        while(less(aux, vetor[j])){
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = aux;
    }
}

void buscaBinaria(info *vetor, int l, int r, int target){
    while (l <= r){
        int meio = (l + r)/2;
        if(codigo(vetor[meio]) == target){
            printf("%s\n", vetor[meio].instruction);
            return;
        }   
        if(codigo(vetor[meio]) > target){
            r = meio - 1;
        }else{
            l = meio + 1;
        }
    }
    printf("undefined\n");
    return;
}
