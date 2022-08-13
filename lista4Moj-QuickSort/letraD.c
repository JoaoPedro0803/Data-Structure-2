#include <stdio.h>
#include <stdlib.h>
#define key(A) (A.cargo)
#define less(A, B) (A.voto == B.voto ? key(A) > key(B) : A.voto > B.voto)
#define exch(A, B)  {dadosVoto t = B; B = A; A = t;}
#define cmpexch(A, B) {if (less(B, A)) exch(A, B)}


int numPres = 0;
int numSenador = 0;
int numDepFederal = 0;
int numDepEstadual = 0;

typedef struct dadosVoto{
    int cargo;
    int voto;
} dadosVoto;

dadosVoto president[91];
dadosVoto senador[901];
dadosVoto depFederal[9001];
dadosVoto depEstadual[90001];

int main(void){
    long long i, senadores, 
    depFederais, depEstaduais;
    scanf(" %lld %lld %lld", &senadores, &depFederais, &depEstaduais);

    int valido = 0, invalidoo = 0, 
    totalVotos = 0, votoLido, l;

    while (scanf(" %d%n", &votoLido, &l) != EOF){ 
        if (votoLido < 0){
            invalidoo++;
            continue;
        }
        switch (l){ 

        case 3: // president
            president[votoLido - 10].cargo = votoLido;
            president[votoLido - 10].voto++;
            totalVotos++;
            break;
        case 4: // senador
            senador[votoLido - 100].cargo = votoLido;
            senador[votoLido - 100].voto++;
            break;
        case 5: // deputado federal
            depFederal[votoLido - 1000].cargo = votoLido;
            depFederal[votoLido - 1000].voto++;
            break;
        default: // deputado estadual
            depEstadual[votoLido - 10000].cargo = votoLido;
            depEstadual[votoLido - 10000].voto++;
        }
        valido++;
    }
    for (i = 0; i < 91; i++){
        if (president[i].voto){
            president[numPres++] = president[i];
        }   
    }  
    for (i = 0; i < 901; i++){
        if (senador[i].voto){
            senador[numSenador++] = senador[i];
        }     
    }
    for (i = 0; i < 9001; i++){
        if (depFederal[i].voto){
            depFederal[numDepFederal++] = depFederal[i];
        }  
    }  
    for (i = 0; i < 90001; i++){
        if (depEstadual[i].voto){
            depEstadual[numDepEstadual++] = depEstadual[i];
        }
    }
    printf("%d %d\n", valido, invalidoo);
    quicksort(president, 0, numPres - 1);
    quicksort(senador, 0, numSenador - 1);
    quicksort(depFederal, 0, numDepFederal - 1);
    quicksort(depEstadual, 0, numDepEstadual - 1);
    if ((double)president[0].voto/totalVotos >= 0.51){
        printf("%d\n", president[0].cargo);
    }else{
        printf("Segundo turno\n");
    }
    for (i = 0; i < senadores; i++){
        printf("%d%c", senador[i].cargo, " \n"[i == senadores - 1]);
    }      
    for (i = 0; i < depFederais; i++){
        printf("%d%c", depFederal[i].cargo, " \n"[i == depFederais - 1]);
    }
    for (i = 0; i < depEstaduais; i++){
        printf("%d%c", depEstadual[i].cargo, " \n"[i == depEstaduais - 1]);
    }
}

void quicksort(dadosVoto *uiuiuiuiuiuiuiuiuiuiui, int l, int r){
    if (l >= r) return;
    cmpexch(uiuiuiuiuiuiuiuiuiuiui[(l + r) / 2], uiuiuiuiuiuiuiuiuiuiui[r]);
    cmpexch(uiuiuiuiuiuiuiuiuiuiui[l], uiuiuiuiuiuiuiuiuiuiui[(l + r) / 2]);
    cmpexch(uiuiuiuiuiuiuiuiuiuiui[r], uiuiuiuiuiuiuiuiuiuiui[(l + r) / 2]);
    int j = separa(uiuiuiuiuiuiuiuiuiuiui, l, r);
    quicksort(uiuiuiuiuiuiuiuiuiuiui, l, j - 1);
    quicksort(uiuiuiuiuiuiuiuiuiuiui, j + 1, r);
}

int separa(dadosVoto *uiuiuiuiuiuiuiuiuiuiui, int l, int r){
    dadosVoto aux = uiuiuiuiuiuiuiuiuiuiui[r];
    int j = l,k;
    for (k = l; k < r; k++){
        if (less(uiuiuiuiuiuiuiuiuiuiui[k], aux)){
            exch(uiuiuiuiuiuiuiuiuiuiui[k], uiuiuiuiuiuiuiuiuiuiui[j]);
            j++;
        }
    }
    exch(uiuiuiuiuiuiuiuiuiuiui[j], uiuiuiuiuiuiuiuiuiuiui[r]);
    return j;
}