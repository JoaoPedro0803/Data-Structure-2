#include <stdio.h>
#include <stdlib.h>

//macros

#define Item int
#define key(x) (x)
#define less(a, b) (a < b)
#define exch(A,B) {int t=A; A=B; B=t;}
#define cmpexch(A,B) {if(less(B,A)) exch(A,B);}
#define GRAPH_WEIGHT_T int
#define GRAPH_WEIGHT_SUM(a, b) (a + b)
#define GRAPH_WEIGHT_LESS(a, b) (a < b)
#define GRAPH_WEIGHT_INF 2147483647

//Structs para definicao do grafo

typedef struct{
    unsigned from, to;
    GRAPH_WEIGHT_T weight;
} Edge;

typedef struct{
    GRAPH_WEIGHT_T **edges;
    unsigned V, E;

} Graph;

int co[5001];//vetor auxiliar para garantir a busca sem repeticao

int separa(Item *v, int l, int r){
    Item pivot = v[r];
    int j = l,k;
    for (k = l; k < r; k++)
        if (less(v[k], pivot)){
            exch(v[k], v[j]);
            j++;
        }
        
    exch(v[j], v[r]);
    return j;
}

void quicksortM3(Item *v, int l, int r){
    if (r - l <= 32) return;
    exch(v[(l + r) / 2], v[r - 1]);
    cmpexch(v[l], v[r - 1]);
    cmpexch(v[l], v[r]);
    cmpexch(v[r - 1], v[r]);
    int m = separa(v, l, r);
    quicksortM3(v, l, m - 1);
    quicksortM3(v, m + 1, r);
}

void insertionsort(Item *v, int l, int r){
    int i,j;
    for (i = l + 1, j; i <= r; i++){
        Item t = v[i];
        for (j = i; j > 0 && less(t, v[j - 1]); j--)
            v[j] = v[j - 1];
        v[j] = t;
    }
}

void quicksort(Item *v, int l, int r){
    quicksortM3(v, l, r);
    insertionsort(v, l, r);
}

Graph G_init(unsigned numeroVertices){
    Graph g = {.V = numeroVertices, .E = 0};
    g.edges = malloc(sizeof(GRAPH_WEIGHT_T *) * g.V);
    unsigned i, j;
    for (i = 0; i < g.V; i++){
        g.edges[i] = malloc(sizeof(GRAPH_WEIGHT_T) * g.V);
        for (j = 0; j < g.V; j++)
            g.edges[i][j] = GRAPH_WEIGHT_INF;
    }
    return g;
}

void G_free(Graph g){
    unsigned i;
    for (i = 0; i < g.V; i++)
        free(g.edges[i]);
    free(g.edges);
}

void G_insert(Graph *g, Edge e){
    if (e.from > g->V || e.to > g->V)
        return;
    g->E += (g->edges[e.from][e.to] == GRAPH_WEIGHT_INF);
    g->edges[e.from][e.to] = e.weight;
}

int G_numberOfEdges(Graph g){
    return g.E;
}

int G_numberOfVertices(Graph g){
    return g.V;
}

void G_components(Graph g, int inicio, int visitados[]){
    if (visitados[inicio] < 0) visitados[inicio] = inicio;
    unsigned i;
    for (i = 0; i < g.V; i++)
        if (g.edges[inicio][i] != GRAPH_WEIGHT_INF && visitados[i] < 0){
            int mn = ((int)i < visitados[inicio] ? (int)i : visitados[inicio]);//decide qual sera o valor a compor mn e assim o vetor auxiliar
            visitados[inicio] = mn;
            visitados[i] = mn;
            G_components(g, i, visitados);
        }
}

int main(){
    int v, s;
    int f,t;
    int i;

    scanf(" %d %d", &v, &s);//a quantidade de cidades existentes  e a cidade em que João se encontra 

    Graph g = G_init(v);

    while(scanf(" %d %d", &f, &t) == 2){
        G_insert(&g, (Edge){.from = f, .to = t});
        G_insert(&g, (Edge){.from = t, .to = f});
    }

    for (i = 0; i < v; i++)
        co[i] = -1;
    for (i = 0; i < v; i++)
        G_components(g, i, co);
    G_free(g);
    int *frequencia = malloc(sizeof(int) * v);
    for (i = 0; i < v; i++)
        frequencia[i] = 0;
    int resposta = v - 1;
    for (i = v - 1; i >= 0; i--){
        if (++frequencia[co[i]] > frequencia[resposta] || (frequencia[co[i]] == frequencia[resposta] && resposta != co[s] && co[i] < resposta))
            resposta = co[i];
    }
    if (resposta == co[s] && G_numberOfEdges(g) == 0)
        printf("Fique em casa\n");
    else if (resposta == co[s])
        printf("Bora pra estrada\n");
    else
        printf("Vamos para %d\n", resposta);
    free(frequencia);
    return 0;
}
