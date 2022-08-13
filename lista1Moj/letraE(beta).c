#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *b;
    node *n;
} node;

typedef struct {
    int count;
    node *p;
} pilha_st;

void inicializa_pilha(pilha_st *p){
    p -> count = 0;
    p -> p = NULL;
}

int estaVazia (pilha_st *p){
    return p -> count == 0?1:0;
}

int empilha (pilha_st *p, char *b){
    node *x = malloc(sizeof(node));
    x -> b = b;
    x -> n = p -> p;
    p -> p = x;
    p -> count++;
    return 1;
}

char * desempilha(pilha_st *p){
    char *ret = p ->p -> b;
    node *x = p -> p;
    p -> p = p -> p -> n;
    free(x);
    p -> count--;
    return ret;
}

int main (){

    pilha_st pilha;
    inicializa_pilha(&pilha);
    char command[9];
    
    while (scanf(" %s", command) == 1){
        if(command[0] == 'i'){
            char *buf = malloc(101);
            scanf(" %[^\n]", buf);
            empilha(&pilha, buf);
        } else if (command[0] == 'd'){
            if(estaVazia(&pilha)){
                printf("NULL\n");
            }else{
                printf("%s\n", desempilha(&pilha));
            }
        }
    }
    return 0;
}