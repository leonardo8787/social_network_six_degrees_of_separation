#include "graph.h"

int main(){

	int adj[]={};
	int cont=0;

	system("clear");
	printf("\n===========GRAFO============\n\n\n");
	Graph G = GraphInitialize(10);

	printf("inserir no grafo!\n");
	printf("0 - leonardo\n");
	printf("1 - joão\n");
	printf("2 - marcelo\n");
	printf("3 - marcos\n");
	printf("4 - maria\n");
	printf("5 - gabriel\n");
	printf("6 - daniel\n");
	printf("7 - weslei\n");
	printf("8 - lindomar\n");
	printf("9 - judite\n");
	system("read -p \"\nPressione enter para continuar...\" continue");
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			printf("contador: %d\n", cont+=1);
			printf("Digite o caminho\n");
			printf("\nInício:");
			scanf("%d",&adj[i]);
			printf("\nfim:");
			scanf("%d",&adj[j]);
			GraphInsertEdge(G, G->adj[i], G->adj[j]);
			printf("\nLigações\n");
			ImprimeGraph(G);
			system("read -p \"\nPressione enter para continuar...\" continue");
		}
	}

/*
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
*/
	printf("\nLigações\n");
	ImprimeGraph(G);

	printf("\nBFS(Busca em largura)\n");
	BFS(G, G->adj[0]);

	printf("\nDFS(Busca em profundidade)\n");
	DFS(G);

	
	return 0;

}