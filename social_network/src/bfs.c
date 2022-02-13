#include "graph_bfs_dfs.h"

Fila* FFVazia_BFS(){
  Fila *f = (Fila *)malloc(sizeof(Fila));
  f->head = NULL;
  f->tail = NULL;
  f->size = 0;
  return f;
}

void Queue_BFS(Fila *f, int vertex){
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

Item* Dequeue_BFS(Fila *f){
  Item *aux;

  if(f->head == NULL)
    return NULL;

  aux = f->head;
  f->head = f->head->prox;
  f->size --;

  return aux;
}

Vertex VertexInitialize_BFS(int value){
  Vertex v = (Vertex)malloc (sizeof(Vertex));
  v->value = value;
  v->prox  = NULL;
  return v;
}

Graph GraphInitialize_BFS(int V){
  Graph G = (Graph)malloc(sizeof(Graph));
  G->V = V;
  G->E = 0;
  G->adj = (Vertex **)malloc(V * sizeof(Vertex *));
  for (int i = 0; i < V; i++) {
    G->adj[i] = (Vertex *)malloc(V * sizeof(Vertex));
    for (int j = 0; j < V; j++) {
      G->adj[i][j] = VertexInitialize_BFS(0);
    }
  }
  return G;
}

void GraphInsertEdge_BFS(Graph G, Vertex v1, Vertex v2){
  if (G->adj[v1->value][v2->value]->value == 1) {
    return;
  }
  G->adj[v1->value][v2->value]->value = 1;
  G->E++;
}

void BFS(Graph G, Vertex s) {
  int cor[G->V]; 
  int d[G->V];
  int pi[G->V]; 
  Fila *f = FFVazia_BFS();
  for (int i = 0; i < G->V; i++)
    if (i != s->value) {
      cor[i] = 0;
      d[i] = -1;  
      pi[i] = -1; 
    }
  cor[s->value] = 1;
  d[s->value] = 0;
  pi[s->value] = -1;
  Queue_BFS(f, s->value);
  while (f->size > 0) {
    Item *u = Dequeue_BFS(f);
    for (int v = 0; v < G->V; v++) {
      if (G->adj[u->data][v]->value == 1 && cor[v] == 0) {
        cor[v] = 1;
        d[v] = d[u->data] + 1;
        pi[v] = u->data;
        Queue_BFS(f, v);
      }
    }
    cor[u->data] = 2;
    printf("Vertex:%3d\n", u->data);
  }
}