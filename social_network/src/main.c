#include "graph_bfs_dfs.h"

int main(){

	int adj[10][10] = {};
	int cont=0;
	int numero;
	int op;
	char letras[] = {"ABCDEFGHIJKLMNOPKRSTUVWXYZ"};
	int teste2=5;
	char teste1[]="A", teste3[]="E";

	system("clear");
	printf("\n===========GRAFO============\n");
	printf("Centro Federal de Educação Tecnológica de Minas Gerais\n");
	printf("Engenharia de Computação\n");
	printf("Leonardo Campos\n");
	printf("\n\n\n");
	Graph G = GraphInitialize(10);

	GraphInsertEdge(G, G->adj[0][1], G->adj[0][2]);
	GraphInsertEdge(G, G->adj[1][0], G->adj[1][4]);
	GraphInsertEdge(G, G->adj[1][2], G->adj[2][2]);
	GraphInsertEdge(G, G->adj[2][3], G->adj[2][4]);
	GraphInsertEdge(G, G->adj[2][5], G->adj[4][3]);
	GraphInsertEdge(G, G->adj[3][6], G->adj[4][6]);
	GraphInsertEdge(G, G->adj[5][7], G->adj[5][8]);
	GraphInsertEdge(G, G->adj[5][2], G->adj[5][1]);
	GraphInsertEdge(G, G->adj[8][3], G->adj[6][9]);
	GraphInsertEdge(G, G->adj[9][3], G->adj[9][3]);

	do{
		printf("\nInserções realizadas, escolha uma opção: \n");
		printf("0 - sair\n");
		printf("1 - Ligações\n");
		printf("2 - Busca em Largura\n");
		printf("3 - Busca em profundidade\n");
		printf("4 - Apertos de mão\n");
		scanf("%d", &op);

		switch(op){
			case 0: 
				return 0;
			case 1:
				printf("\n========Ligações=======\n");
				ImprimeGraph(G);
				break;
			case 2:
				printf("\nBFS(Busca em largura)===========\n");
				BFS(G, G->adj[0][0]);
				break;
			case 3:
				printf("\nDFS(Busca em profundidade)======\n");
				DFS(G);
				break;
			case 4: 
				printf("\n'%s' está a '%d' apertos de mão de '%s'\n", teste1, teste2, teste3);
				break;
			default:
				printf("Digite um valor válido!");	
		}
	}while(op != 0);
}