#include <stdio.h>
#include <stdlib.h>

typedef struct Fonte{
    char input[81];
    char outputTraduzido[81];
} Fonte;

void verificaPalavra(char aux[81], int tamFonte, Fonte *vetor, int tamanhoPalavra) {
    int i, j;
    for(i = 0; i < tamFonte; i ++){
        for(j = 0; j < tamanhoPalavra; j ++){
            if(aux[j] == vetor[i].input[j] && j == (tamanhoPalavra-1) && vetor[i].input[j+1] == '\0'){
                printf("%s ", vetor[i].outputTraduzido);
                return;
            }else if(aux[j]==vetor[i].input[j]){
                continue;
            }else{
                break;
            }
        }
    }
    printf("%s ", aux);
}

void traduzir(int sizeSong, int tamanhoDicionario, char song[sizeSong][81], Fonte *vetor) {
    int i, j, z = 0;
    char auxiliar[81];

    for(i = 0; i < sizeSong; i ++){
        for(j = 0; song[i][j] != '\0'; j ++) {
            if(song[i][j] == ' '){
                auxiliar[z++]='\0';
                verificaPalavra(auxiliar, tamanhoDicionario, vetor, z-1);
                z = 0;
            } else if(song[i][j+1]=='\0'){
                auxiliar[z++] = song[i][j];
                auxiliar[z++] = '\0';
                verificaPalavra(auxiliar, tamanhoDicionario, vetor, z-1);
                z = 0;
            } else{
                auxiliar[z++] = song[i][j];
        }
        printf("\n");
        }
    }
}

int main(void){
    int i = 0, t;
    int r, n, j;
    // num instancias
    scanf(" %d", &t);
    while(i < t) {
        /* quantidade de palavras na fonte e
        numeros de linhas na letra
        */
        scanf(" %d %d", &r, &n);
        Fonte *vetor = malloc(r * sizeof(Fonte));
        char musica[n][81];
        for(j = 0; j < r; j ++) {
            scanf(" %[^\n]", vetor[j].input);
            scanf(" %[^\n]", vetor[j].outputTraduzido);
        }
        for(j = 0; j < n; j ++){
            scanf(" %[^\n]", musica[j]);
        }
        traduzir(n, r, musica, vetor);
        printf("\n");
        i ++;
        free(vetor);
    }
}

/*
    https://br.spoj.com/problems/JASPION.pdf        --> Enunciado da questao
*/