#include "graph.h"

int main(){

	int a, b, tam, op;
	int adj[]={};

	printf("\n===========GRAFO============\n");
	//printf("\n\nDigite o tamanho do grafo:\n");
	//scanf("%d",&tam);
	//system("pause");
	Graph G = GraphInitialize(10);
/*
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
		system("read -p \"\nPressione enter para continuar...\" continue");
		for(int i=1; i<tam; i++){
			for(int j=1; j<tam; i++){
				printf("Digite o caminho\n");
				cout << "início: \n" << endl;
				cin >> adj[i];
				cout << "fim: \n" << endl;
				cin >> adj[j];
				cout << "\n" << endl;
				GraphInsertEdge(G, G->adj[i], G->adj[j]);
				system("read -p \"\nPressione enter para continuar...\" continue");
			}
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
		printf("Escolha uma opção válida");
	}
*/

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

	
	return 0;

}