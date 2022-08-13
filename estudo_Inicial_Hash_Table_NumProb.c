#include <stdio.h>
#include <stdlib.h>

int v[262139];

int hashN(int n){
    return n % 262139;          //mexe com o indice bro
}

int main(void){
    int N, i;
    scanf(" %d", &N);
    for(i = 0; i < N; i++){
        int t;
        scanf(" %d", &t);
        v[hashN(t)] = t; 
    }
    int c;
    while(scanf(" %d", &c) == 1){
        if(v[hashN(c)] == c){
            printf("sim");
        }else if(v[hashN(c) == 0]){
            printf("não");
        }else if(v[hashN(c) != c]){
            printf("colisão");
        }
    }
}