#include "graph_bfs_dfs.h"

Fila* FFVazia_DFS(){
  Fila *f = (Fila *)malloc(sizeof(Fila));
  f->head = NULL;
  f->tail = NULL;
  f->size = 0;
  return f;
}

void Queue_DFS(Fila *f, int vertex){
  Item *d = (Item *) malloc (sizeof(Item));
  d->data = vertex;
  d->prox = NULL;

  if(f->head == NULL){
    f->head = d;
    f->tail = d;
  }else{
    f->tail->prox = d;
    f->tail = d;
  }

  f->size ++;
}

Item* Dequeue_DFS(Fila *f){
  Item *aux;

  if(f->head == NULL)
    return NULL;

  aux = f->head;
  f->head = f->head->prox;
  f->size --;

  return aux;
}

Vertex VertexInitialize_DFS(int value){
  Vertex v = (Vertex)malloc (sizeof(Vertex));
  v->value = value;
  v->prox  = NULL;
  return v;
}

Graph GraphInitialize_DFS(int V){
  Graph G = (Graph)malloc(sizeof(Graph));
  G->V = V;
  G->E = 0;
  G->adj = (Vertex **)malloc(V * sizeof(Vertex *));
  for (int i = 0; i < V; i++) {
    G->adj[i] = (Vertex *)malloc(V * sizeof(Vertex));
    for (int j = 0; j < V; j++) {
      G->adj[i][j] = VertexInitialize_DFS(0);
    }
  }
  return G;
}

void GraphInsertEdge_DFS(Graph G, Vertex v1, Vertex v2){
  if (G->adj[v1->value][v2->value]->value == 1) {
    return;
  }
  G->adj[v1->value][v2->value]->value = 1;
  G->E++;
}

void DFS_VISIT(Graph G, Vertex *v, int index, int *cor, int *d, int *f,int *tempo){
  cor[index] = 1;
  *tempo += 1;
  d[index] = *tempo;
  for (int u = 0; u < G->V; u++) {
    if (v[u]->value == 1 && cor[u] == 0) {
      DFS_VISIT(G, G->adj[u], u, cor, d, f, tempo);
    }
  }
  cor[index] = 2;
  *tempo += 1;
  f[index] = *tempo;
  printf("Vertex:%3d D:%3d F:%3d\n", index, d[index], f[index]);
}

void DFS(Graph G){
  int cor[G->V]; 
  int d[G->V];    
  int f[G->V];    
  int tempo = 0;
  for (int v = 0; v < G->V; v++) cor[v] = 0;
  for (int v = 0; v < G->V; v++)
    if (cor[v] == 0)
      DFS_VISIT(G, G->adj[v], v, cor, d, f, &tempo);
}