#include<stdio.h>
#include<stdlib.h>
#define less(A, B) (A < B)
#define exch(A, B) {int t = B; B = A; A = t;}
#define cmpexch(A, B) {if(less(B, A)) exch(A, B);}

int main(void){
    int j, i, s;
    scanf(" %d", &s);
    int *v = malloc(s * sizeof(int));
    for(i = 0; i < s; i++){
        scanf(" %d", &v[i]);
    }
    quicksort(v, 0, i-1);
    for(j = 0; j < i - 1; j ++){
        printf("%d ", v[j]);
    } 
    printf("%d\n", v[j]);
    free(v);
    return 0;
}

int separa(int *v, int l, int r){
    int i = l-1, j = r;
    int c = v[r];
    for(;;){
        while(less(v[++i], c)); 
        while(less(c, v[--j])) if(i == j) break;
        if(i >= j) break;
        exch(v[i], v[j]);
    }
    exch(v[i], v[r]);
    return i;
}

void quicksort(int *v, int l, int r){
    if(l >= r) return;
    cmpexch(v[(l+r)/2],v[r]);
    cmpexch(v[l],v[(l+r)/2]);
    cmpexch(v[r],v[(l+r)/2]);
  
    int j = separa(v, l, r);
  
    quicksort(v, l, j-1);
    quicksort(v, j+1, r);
}