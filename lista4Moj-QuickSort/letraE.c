#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ull unsigned long long
#define less(a, b) (a.sementeNota == b.sementeNota ? a.sementeCodigo < b.sementeCodigo : a.sementeNota < b.sementeNota)
#define lessv2(a, b) (a.sementeCodigo == b.sementeCodigo ? a.sementeNota < b.sementeNota : a.sementeCodigo < b.sementeCodigo)
#define exch(a, b) { Item t = a;a = b;b = t;}
#define cmpexch(a, b) {if (less(b, a)) exch(a, b);}
#define cmpexch2(a, b) {if (lessv2(b, a)) exch(a, b);}
typedef struct{
    long long sementeCodigo;
    int sementeNota;
} Item;

Item fullSemente[10000001];

int main(void){
    int i;
    int k;
    int n;
    scanf(" %d", &k);
    for (n = 0; scanf(" %lld %d", &fullSemente[n].sementeCodigo, &fullSemente[n].sementeNota) == 2; n++);

    quickselect(fullSemente, 0, n - 1, k - 1);
    quicksort2(fullSemente, 0, k - 1);

    for (i = 0; i < k; i++){
        printf("%lld %d\n", fullSemente[i].sementeCodigo, 
        fullSemente[i].sementeNota);
    }
}

void quicksortM3(Item *fullSemente, int l, int r){
    if (r<=l )return;
    exch(fullSemente[(l + r) / 2], fullSemente[r - 1]);
    cmpexch2(fullSemente[l], fullSemente[r - 1]);
    cmpexch2(fullSemente[l], fullSemente[r]);
    cmpexch2(fullSemente[r - 1], fullSemente[r]);
    int m = separa(fullSemente, l, r);
    quicksortM3(fullSemente, l, m - 1);
    quicksortM3(fullSemente, m + 1, r);
}

void insertionsort(Item *fullSemente, int l, int r){
    int i,j;
    for (i = l + 1, j; i <= r; i++){
        Item t = fullSemente[i];
        for (j = i; j > 0 && lessv2(t, fullSemente[j - 1]); j--){
            fullSemente[j] = fullSemente[j - 1];
        }
        fullSemente[j] = t;
    }
}

int separa(Item *fullSemente, int l, int r){
    Item pivot = fullSemente[r];
    int j = l,k;
    for (k = l; k < r; k++){
        if (less(fullSemente[k], pivot)){
            exch(fullSemente[k], fullSemente[j]);
            j++;
        }
    }
    exch(fullSemente[j], fullSemente[r]);
    return j;
}

void quicksort2(Item *fullSemente, int l, int r){
    quicksortM3(fullSemente, l, r);
    insertionsort(fullSemente, l, r);
}

void quickselect(Item *fullSemente, int l, int r, int i){
    cmpexch(fullSemente[(l + r) / 2], fullSemente[r]);
    cmpexch(fullSemente[l], fullSemente[(l + r) / 2]);
    cmpexch(fullSemente[r], fullSemente[(l + r) / 2]);
    int t = separa(fullSemente, l, r);
    if (t > i){
        quickselect(fullSemente, l, t - 1, i);
    }else if (t < i){
        quickselect(fullSemente, t + 1, r, i);
    }
}