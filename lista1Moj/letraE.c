#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  char *dado;
  struct node *prox;
} node;


node *cria_lista () {
  node *le = malloc (sizeof(node));
  le -> prox = NULL;
  return le;
}

void desfazer (node *le) {
  node *lixo = le -> prox;
  if (lixo != NULL) {
    le -> prox = lixo -> prox;
    printf (" %s\n", lixo -> dado);
    free (lixo);
  }
  else printf ("NULL\n");
}

void inserir (node *le, char *dado) {
  node *novo = malloc (sizeof(node));
  novo -> dado = dado;
  novo -> prox = le -> prox;
  le -> prox = novo;
}

int main () {
  node *le = cria_lista ();
  char var[101];
  char *aux = malloc(101 * sizeof(char));

  while(scanf(" %s", var) != EOF) {

    if (strcmp (var, "inserir") == 0) {
      scanf(" %[^\n]", aux);
      aux [strlen (aux)] = '\0';
      inserir(le, aux);

    }
    else if(strcmp(var,"desfazer")==0) desfazer(le);

    aux = malloc (101 * sizeof(char));

  }
  return 0;
}