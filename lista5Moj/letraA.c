#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n=-1, i;
    while(n != 0){
       scanf(" %d", &n);
        int *v = malloc(sizeof(int)*n);
        for(i = 0; i < n; i++){
            scanf(" %d", &v[i]);
        }
    }
}

