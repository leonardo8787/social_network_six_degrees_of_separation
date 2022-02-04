#include "graph.h"

int main(){

	int adj[1000];
	int a, b, tam, op, j=0;

	printf("\n===========GRAFO============\n");
	printf("\n\nDigite o tamanho do grafo:\n");
	scanf("%d",&tam);
	system("pause");
	Graph G = GraphInitialize(tam);

	do
	{
		printf("Menu\n");
		printf("1 - inserir no grafo\n");
		printf("2 - remover do grafo\n");
		printf("3 - printar grafo\n");
		printf("0 - sair\n");
		scanf("%d", &op);
		switch (op)
		{
		case 0: 
			printf("saindo...\n");
			break;
		case 1:
			printf("inserir no grafo!\n");
			system("pause");
			for(int i=0; i<tam; i++){
				j+=1;
				printf("Digite o caminho\n");
				system("pause");
				scanf("inicio: %d - fim: %d\n", &adj[i], &adj[j]);
				GraphInsertEdge(G, G->adj[i], G->adj[j]);
				system("pause");
			}
			break;
		case 2:
			printf("remover no grafo!\n");
			break;
		case 3:
			printf("printar grafo!\n");
			ImprimeGraph(G);
			break;
		default:
			break;
		}
	} while (op != 0);
	

	/*printf("Digite o tamanho do grafo, maior que 2: \n");
	scanf("%d",&tam);
	system("pause");

	Graph G = GraphInitialize(tam);

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

	printf("Digite dois vértices: \n");
	scanf("%d",&a);
	scanf("%d",&b);
	GraphInsertEdge(G, G->adj[a], G->adj[b]);

	ImprimeGraph(G);*/
	
	return 0;

}