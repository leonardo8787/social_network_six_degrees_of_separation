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
  for (int i = 0; i < G->V; i++) {
    printf("[%2d]-> ", i);
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