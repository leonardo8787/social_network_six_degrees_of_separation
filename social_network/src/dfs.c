#include "graph_bfs_dfs.h"

//// procs FILA

Fila* FFVazia_DFS(){
  Fila *f = (Fila*) malloc(sizeof(Fila));
  f->head = NULL;
  f->tail = NULL;
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

//// fim procs FILA


// procs para tratar com grafos 
Vertex VertexInitialize_DFS(int value){
  Vertex v = (Vertex)malloc (sizeof(Vertex));
  v->value = value;
  v->prox  = NULL;
  return v;
}

Graph GraphInitialize_DFS(int V){
  Graph G = (Graph)malloc (sizeof(Graph));
  G->V = V;
  G->E = 0;
  G->adj = (Vertex*)malloc(V * sizeof(Vertex));

  for(int v=0; v<V; v++)
    G->adj[v] = VertexInitialize_DFS(v);

  return G;
}

void GraphInsertEdge_DFS(Graph G, Vertex v1, Vertex v2){
  Vertex v = G->adj[v1->value];
  
  while(v->prox != NULL){
    if (v->value == v2->value)
      return;
    v = v->prox;
  }

  v->prox = VertexInitialize_DFS(v2->value);
  G->E ++;
}

void ImprimeGraph_DFS(Graph G){
  Vertex aux;

  for(int v=0; v<G->V; v++){
    aux = G->adj[v];

    while(aux != NULL){
      printf(" %d -> ", aux->value);
      aux = aux->prox;
    }

    printf("\n");
  }
  
}


// fim procs para tratar com grafos
void DFS_VISIT_DFS(Graph G, Vertex v, int *cor, int *d, int *f, int *tempo){
  cor[v->value]  = 1;
  *tempo        += 1;
  d[v->value]    = *tempo;

  for(Vertex u = G->adj[v->value]; u != NULL; u=u->prox)
    if(cor[u->value] == 0)
      DFS_VISIT_DFS(G, u, cor, d, f, tempo);


  cor[v->value] = 2;
  *tempo += 1;
  f[v->value] = *tempo;
  printf("Vertex:%d D:%d, F:%d \n", v->value, d[v->value], f[v->value]);
}

void DFS(Graph G){
  int cor[G->V]; // Branco 0, Cinza 1, Preto 2
  int d[G->V];   // Tempo de descoberta
  int f[G->V];   // Tempo de finalização
  int tempo = 0;

  for(int v=0; v<G->V; v++)
    cor[v] = 0;

  for(int v=0; v<G->V; v++)
    if(cor[v] == 0)
      DFS_VISIT_DFS(G, G->adj[v], cor, d, f, &tempo);
}


