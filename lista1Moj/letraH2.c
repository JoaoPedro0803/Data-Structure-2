#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int numPessoas;
    int numProblemas[101];
    char name[101][21];
    int i = 0, j = 1;

    while(scanf(" %d", &numPessoas) != EOF) {
        for (i = 0; i < numPessoas; i ++)
            if(scanf(" %s", name[i]) == EOF || scanf(" %d",&numProblemas[i]) == EOF)
                return 0;
        printf("Instancia %d\n", j);
        VerifReprovado(numPessoas, name, numProblemas);
        printf("\n");
        j ++;
    }

    return 0;
}

void VerifOrdem(char name[101][21], int auxiliariliar[101], int limite) {
    int i = 0, j;
    while(auxiliariliar[i] < auxiliariliar[limite]) {
        for(j = 0; name[auxiliariliar[i]][j] != '\0'; j ++) {
            if(name[auxiliariliar[i + 1]][j] == '\0') {
                strcpy(name[auxiliariliar[i + 1]], name[auxiliariliar[i]]);
                break;
            }
            else if(name[auxiliariliar[i]][j] > name[auxiliariliar[i + 1]][j]) {
                strcpy(name[auxiliariliar[i + 1]], name[auxiliariliar[i]]);
                break;
            }
            else if(name[auxiliariliar[i]][j] == name[auxiliariliar[i + 1]][j]) {
                continue;
            }
            else if(name[auxiliariliar[i]][j] < name[auxiliariliar[i + 1]][j]) {
                break;
            }
        }
        i ++;
    }

    printf("%s\n", name[auxiliariliar[limite]]);
}

void VerifReprovado(int numPessoas, char name[101][21], int numProblemas[101]) {
    int menor = numProblemas[0], j = 0, i;
    int auxiliariliar[101];
    for(i = 1; i < numPessoas; i ++)
        if(numProblemas[i] < menor) menor = numProblemas[i];

    for(i = 0; i < numPessoas; i ++)
        if(menor == numProblemas[i]) {
            auxiliariliar[j] = i;
            j ++;
        }

    if(j == 1)
        printf(" %s\n", name[auxiliariliar[0]]);
    else
        VerifOrdem(name, auxiliariliar, j - 1);
}