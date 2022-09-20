#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, j;
    scanf(" %d %d %d", &n, &m, &j);
    int matriz[n][n], i, u;
    for(i = 0; i < n; i ++)
        for(u = 0; u < n; u ++)
            matriz[i][u] = 0;
    int vizinho;
    for(i = 0; i < n; i ++) {
        scanf(" %d", &vizinho);
        int local;
        for(u = 0; u < vizinho; u ++) {
            scanf(" %d", &local);
            matriz[i][local] = 1;
        }
    }
    int l;
    for(i = 0; i < m; i ++) {
        scanf(" %d", &l);
        matriz[l][l] = 2;
        for(u = 0; u < n; u ++) {
            if(matriz[l][u] == 1) {
                matriz[u][u] = 2;
            }
        }
    }
    for(i = 0; i < j; i ++) {
        scanf(" %d", &l);
            if(matriz[l][l] == 2) {
                printf("Eu vou estar la\n");
            }
            else
                printf("Nao vou estar la\n");
    }
    return 0;
}