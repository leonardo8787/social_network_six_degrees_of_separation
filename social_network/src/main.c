#include "graph_bfs_dfs.h"

int main(){

	int adj[]={};
	int cont=0;
	int numero;

	system("clear");
	printf("\n===========GRAFO============\n\n\n");
	Graph G = GraphInitialize(10);

	GraphInsertEdge(G, G->adj[0], G->adj[2]);
	GraphInsertEdge(G, G->adj[0], G->adj[1]);
	GraphInsertEdge(G, G->adj[1], G->adj[0]);
	GraphInsertEdge(G, G->adj[1], G->adj[4]);
	GraphInsertEdge(G, G->adj[1], G->adj[5]);
	GraphInsertEdge(G, G->adj[2], G->adj[0]);
	GraphInsertEdge(G, G->adj[2], G->adj[3]);
	GraphInsertEdge(G, G->adj[3], G->adj[2]);
	GraphInsertEdge(G, G->adj[4], G->adj[1]);
	GraphInsertEdge(G, G->adj[4], G->adj[5]);
	GraphInsertEdge(G, G->adj[4], G->adj[6]);
	GraphInsertEdge(G, G->adj[5], G->adj[1]);
	GraphInsertEdge(G, G->adj[5], G->adj[4]);
	GraphInsertEdge(G, G->adj[5], G->adj[6]);
	GraphInsertEdge(G, G->adj[5], G->adj[7]);
	GraphInsertEdge(G, G->adj[6], G->adj[4]);
	GraphInsertEdge(G, G->adj[6], G->adj[5]);
	GraphInsertEdge(G, G->adj[6], G->adj[7]);
	GraphInsertEdge(G, G->adj[7], G->adj[6]);
	GraphInsertEdge(G, G->adj[7], G->adj[5]);

	printf("\nLigações\n");
	ImprimeGraph(G);

	printf("\nBFS(Busca em largura)\n");
	BFS(G, G->adj[0]);

	printf("\nDFS(Busca em profundidade)\n");
	DFS(G);

	printf("\n\n==========================================\n");
	printf("O ");

	return 0;

}