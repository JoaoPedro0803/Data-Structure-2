#include <stdio.h>
#include <stdlib.h>
#define key(A) (A)
#define less(A,B) (key(A) < key(B))
#define exch(A,B) {int t=A; A=B; B=t;}
#define cmpexch(A,B) {if(less(B,A)) exch(A,B);}

int main(void){
    int numProd, pagina, numProdPag,i; 
    scanf(" %d %d %d", &numProd, &pagina, &numProdPag);
    int inicio = numProdPag*pagina; 
    int fim = inicio + numProdPag;
    if(fim > numProd)fim = numProd;
    int *vetor = malloc(numProd*sizeof(int));
    for(i = 0; i < numProd; i++){
        scanf(" %d", &vetor[i]);
    }
    quickselect(vetor, 0, numProd-1, inicio);
    quickselect(vetor, inicio+1, numProd-1, fim);
    quicksort(vetor, inicio, fim-1);
    for(i = inicio; i < fim; i++){
        printf("%d\n", vetor[i]);
    }
    free(vetor);
}

int separa(int *vetor,int l, int r){
  int auxiliar = vetor[r], i, j = l;
  for(i = l; i < r; i++){
    if(less(vetor[i], auxiliar)){
      exch(vetor[i], vetor[j]);
      j++;
    }
  }    
  exch(vetor[j], vetor[r]);
  return j;
}
void quickselect(int *vetor, int l, int r, int pagina){
    int j;
    if(r <= l) return;
    j = separa(vetor, l, r);
    if(j > pagina)
        quickselect(vetor, l, j-1, pagina);
    else if(j < pagina)
        quickselect(vetor, j+1, r, pagina);
}

void quicksort(int *vetor,int l, int r){
  if (l >= r) return; 
  cmpexch(vetor[(l+r)/2], vetor[r]);
  cmpexch(vetor[l], vetor[(l+r)/2]);
  cmpexch(vetor[r], vetor[(l+r)/2]);
  int j = separa(vetor, l, r);
  quicksort(vetor, l, j-1);
  quicksort(vetor, j+1, r);
}