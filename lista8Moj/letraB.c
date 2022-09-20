#include <stdio.h>
#include <stdlib.h>
#define GRAFO_TIPO int
#define GRAPH_VALUE_INIT 2147483647 

typedef struct{
    unsigned from, to; //de onde e para onde
    GRAFO_TIPO weight;
} Edge; 

typedef struct{
    GRAFO_TIPO **edges;//aresta
    unsigned vertices;
} Graph;

int vi[5001];//vetor pre

Graph G_init(unsigned vertices){
    unsigned j, i;
    Graph g = {.vertices = vertices};
    g.edges = malloc(sizeof(GRAFO_TIPO *) * g.vertices);
    for (i = 0; i < g.vertices; i++){
        g.edges[i] = malloc(sizeof(GRAFO_TIPO) * g.vertices);
        for (j = 0; j < g.vertices; j++)
            g.edges[i][j] = GRAPH_VALUE_INIT;
    }
    return g;
}

/* void G_free(Graph g){
    unsigned i;
    for (i = 0; i < g.vertices; i++)
        free(g.edges[i]);
    free(g.edges);
}*/

void G_insert(Graph *g, Edge e){
    if (e.from > g->vertices || e.to > g->vertices)
        return;
    g->edges[e.from][e.to] = e.weight;
}

void G_dfs(Graph g, int inicio, int visitados[]){
    visitados[inicio] = 1;
    unsigned i;
    for (i = 0; i < g.vertices; i++)
        if (g.edges[inicio][i] != GRAPH_VALUE_INIT && !visitados[i])
            G_dfs(g, i, visitados);
}

int main(){
    unsigned v;
    int i,from, to;
    scanf(" %d", &v);
    Graph g = G_init(v);
    while(scanf(" %d %d", &from, &to) == 2){
        G_insert(&g, (Edge){.from = from, .to = to});
        G_insert(&g, (Edge){.from = to, .to = from});
    }
    int resposta = 0;
    for (i = 0; i < v; i++)
        if (!vi[i]){
            G_dfs(g, i, vi);
            resposta++;
        }
    printf("%d\n", resposta);
    unsigned y;
    for (y = 0; y < g.vertices; y++)
        free(g.edges[y]);
    free(g.edges);
    return 0;
}