#include "nucesGraph.h"

int main(int argc, char *argv[])
{
	int i;
	


	//Make Graph A
	/*struct nGraph G;	
	nGraphInit(&G, 'A');
	printf("%s\n", "Graph A");

	addVertex(&G, 1);
	addVertex(&G, 2);
	addVertex(&G, 3);
	addVertex(&G, 4);

	addEdge(&G, 1, 2, 0);
	addEdge(&G, 2, 3, 0);
	addEdge(&G, 3, 4, 0);
	addEdge(&G, 4, 1, 0);
	addEdge(&G, 1, 3, 0);

	//listVertices(&G);
	//listEdges(&G);
	printf("%s\n", "");
	printf("%s\n","*****************************");
	printf("%s\n", "");


	//Make Graph B
	struct nGraph G2;
	printf("%s\n", "Graph B");

	nGraphInit(&G2, 'B');
	addVertex(&G2, 1);
	addVertex(&G2, 2);
	addVertex(&G2, 3);
	addVertex(&G2, 6);
	addVertex(&G2, 7);
	addVertex(&G2, 8);


	addEdge(&G2, 2, 1, 0);
	addEdge(&G2, 2, 3, 0);
	addEdge(&G2, 7, 6, 0);
	addEdge(&G2, 7, 8, 0);

	//listVertices(&G2);
	//listEdges(&G2);
	printf("%s\n", "");
	printf("%s\n","*****************************");
	printf("%s\n", "");

	*/




	/********************************************************

	
		Below Here is the Additional Assignment Code



	*********************************************************/

	//Finding Union (G1 U G2)
	/*printf("%s\n", "Graph C union");
	struct nGraph G3=unionGrpah(&G,&G2);
	listVertices(&G3);
	listEdges(&G3);
	printf("%s\n", "");
	printf("%s\n","*****************************");
	printf("%s\n", "");

	//Finding Intersection (G1 ∩ G2)
	printf("%s\n", "Graph D intersection");
	struct nGraph G7=intersectGrpah(&G,&G2);
	listVertices(&G7);
	listEdges(&G7);
	printf("%s\n", "");
	printf("%s\n","*****************************");
	printf("%s\n", "");
	
	//Finding RingSum (G1.V U G2.V)	{(G1.E-G2.E) U (G2.E-G1.E)}
	printf("%s\n", "Graph E RingSum");
	struct nGraph G8=ringSum(&G,&G2);
	listVertices(&G8);
	listEdges(&G8);
	printf("%s\n", "");
	printf("%s\n","*****************************");
	printf("%s\n", "");

	//Finding Neighbours of A Graph on given vertex
	printf("%s\n", "Graph F Neighbours");
	struct nGraph G14=neighbours(&G,2);
	listVertices(&G14);
	//listEdges(&G14);
	printf("%s\n", "");
	printf("%s\n","*****************************");
	printf("%s\n", "");
	*/









	/********************************************************

	
		Below Here is the Bron-Kerbosch Algorithm Code



	*********************************************************/

	//Make Graph GG
	struct nGraph GG;
	nGraphInit(&GG,'G');
	addVertex(&GG, 1);
	addVertex(&GG, 2);
	addVertex(&GG, 3);
	addVertex(&GG, 4);
	addVertex(&GG, 5);

	addEdge(&GG, 1, 2, 0);
	addEdge(&GG, 1, 3, 0);
	addEdge(&GG, 2, 3, 0);
	addEdge(&GG, 2, 4, 0);
	addEdge(&GG, 3, 5, 0);
	addEdge(&GG, 4, 5, 0);
	
	listVertices(&GG);
	listEdges(&GG);

	printf("%s\n", "");
	printf("%s\n","*****************************");
	printf("%s\n", "");
	
	struct nGraph G21=FindingCliques(GG);

	
	
	//makeCompleteGraph(&GG,10);















	//addEdge(&G, 0, 1, 0);
	//addEdge(&G, 1, 2, 0);
	#if 0
	for (i = 0; i < 10; i++) 
		addVertex(&G, i);
	for (i = 0; i < 10; i++) 
		addRandomEdge(&G, 0);
	listVertices(&G);
	listEdges(&G);
	nGraphFree(&G);

	struct nGraph B;
	nGraphInit(&B, 'B');
	makeCompleteGraph(&B, 4);
	listVertices(&B);
	listEdges(&B);
	nGraphFree(&B);

	//addEdge(&G, 0, 1, 0);
	//addEdge(&G, 1, 2, 0);

	makeAdjacency(&G);
	printAdjacency(&G);
	addVertex(&G, 30);
	addVertex(&G, 29);
	addEdge(&G, 0, 30, 0);
	addEdge(&G, 29, 30, 0);
	listEdges(&G);
	printAdjacency(&G);

	makeAdjacency(&B);
	printAdjacency(&B);
	#endif

	return 0;
} 
