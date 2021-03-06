#include "graph_bfs_dfs.h"

Vertex VertexInitialize(int value) {
  Vertex v = (Vertex)malloc(sizeof(Vertex));
  v->value = value;
  return v;
}

Graph GraphInitialize(int V) {
  Graph G = (Graph)malloc(sizeof(Graph));
  G->V = V;
  G->E = 0;
  G->adj = (Vertex **)malloc(V * sizeof(Vertex *));
  for (int i = 0; i < V; i++) {
    G->adj[i] = (Vertex *)malloc(V * sizeof(Vertex));
    for (int j = 0; j < V; j++) {
      G->adj[i][j] = VertexInitialize(0);
    }
  }
  return G;
}

void GraphInsertEdge(Graph G, Vertex v1, Vertex v2) {
  if (G->adj[v1->value][v2->value]->value == 1) {
    return;
  }
  G->adj[v1->value][v2->value]->value = 1;
  G->E++;
}

void ImprimeGraph(Graph G) {
  int grau=0;
  char map_letra[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
  printf("   ");
  for (int j = 0; j < G->V; j++) {
    //printf("[%2d]", j);
    printf("[ %c]", map_letra[j]);
  }
  printf("\n\n");
  for (int i = 0; i < G->V; i++) {
    //printf("[%2d]-> ", i);
    printf("[%c]", map_letra[i]);
    for (int j = 0; j < G->V; j++) {
      if (G->adj[i][j]->value == 1) {
        printf("[ 1]");
      } else if (G->adj[i][j]->value == -1) {
        printf("[-1]");
      } else {
        printf("[  ]");
      }
    }
    printf("\n");
  }
}

void ImprimeGrau(Graph G) {
  int grau=0;
  for (int i = 0; i < G->V; i++) {
    for (int j = 0; j < G->V; j++) {
      if (G->adj[i][j]->value == 1) {
        grau += 1;
      }
    }
  }
  printf("grau: %d", grau);
}

void Aperto_de_mao(Graph G) {
  int grau=0;
  int grafo[10][10]={};
  int comprimento=0;
  char map_letra[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
  for (int i = 0; i < G->V; i++) {
    for (int j = 0; j < G->V; j++) {
      if (G->adj[i][j]->value == 1) {
        grau += 1;
        if (G->adj[j][i]->value == 1){
          comprimento += 1;
        }
      }
    }
  }
  printf("\n\nExistem %d pessoas que conhecem todas as outras no universo em questão! \n",comprimento);
  printf("existem %d conexões nessa rede!\n\n\n", grau);
/*
  for(int i=0;i<10;i++){
        printf("Amigos de %c:\t", map_letra[i]);
        for(int j=0;j<10;j++){
            if(G->adj[i][j]->value != -1){
                if(map_letra[i] == map_letra[grafo[i][j]]){
                    printf("\t");
                }else{
                    printf("%c\t", map_letra[grafo[i][j]]);
                }
            }
        }
        printf("\n");
  }
*/
}