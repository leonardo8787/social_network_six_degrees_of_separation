#ifndef GRAPH_H 
#define GRAPH_H

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct graph *Graph;
typedef struct TipoVertex *Vertex;

typedef struct TipoItem Item;
typedef struct TipoFila Fila;

struct TipoVertex{
  int value;
  Vertex prox;
};

struct graph{
  int V;
  int E;
  Vertex **adj;
};

struct TipoItem{
    int data;
  Item *prox;
};

struct TipoFila{
  Item *head;
  Item *tail;
  int size;
};

Vertex VertexInitialize_BFS(int value);
Graph GraphInitialize_BFS(int V);
void GraphInsertEdge_BFS(Graph G, Vertex v1, Vertex v2);
void ImprimeGraph_BFS(Graph G);

Vertex VertexInitialize_DFS(int value);
Graph GraphInitialize_DFS(int V);
void GraphInsertEdge_DFS(Graph G, Vertex v1, Vertex v2);
void ImprimeGraph_DFS(Graph G);

Vertex VertexInitialize(int value);
Graph GraphInitialize(int V);
void GraphInsertEdge(Graph G, Vertex v1, Vertex v2);
void ImprimeGraph(Graph G);

void BFS(Graph G, Vertex s);

Fila* FFVazia_BFS();
void Queue_BFS(Fila *f, int vertex);
Item* Dequeue_BFS(Fila *f);

Fila* FFVazia_DFS();
void Queue_DFS(Fila *f, int vertex);
Item* Dequeue_DFS(Fila *f);

void DFS(Graph G);
void DFS_VISIT(Graph G, Vertex *v, int index, int *cor, int *d, int *f, int *tempo);

#endif
