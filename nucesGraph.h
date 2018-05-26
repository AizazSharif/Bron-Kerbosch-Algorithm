#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
struct nGraph max;
struct vertex
{
	int label;
	struct vertex *next;
	struct vertex *prev;
};

struct edge 
{
	int weight;
	int head;
	int tail;
	struct edge *next;
	struct edge *prev;
};

struct verList
{
	int count;
	struct vertex *head;
	struct vertex *tail; 
};

struct edgList
{
	int count;
	struct edge *head;
	struct edge *tail;
};

struct nGraph
{
	char label;
	struct verList *V;
	struct edgList *E;
};

void nGraphFree(struct nGraph *G) 
{
}

void nGraphInit(struct nGraph *G, char t)
{
	G->V = malloc(sizeof(struct verList));
	G->V->count = 0;
	G->E = malloc(sizeof(struct edgList));
	G->E->count = 0;
	G->label = t;
}

int searchVertex(struct nGraph *G, int search) 
{
	struct vertex *tmp = G->V->head;
	while (tmp != NULL) {
		if (tmp->label == search) {
			return 1;
		}
		tmp = tmp->next;
	}
	return 0;
}

int getVertex(struct nGraph *G, int search) 
{
	struct vertex *tmp = G->V->head;
	int count = 0; 
	while (tmp != NULL) {
		if (tmp->label == search) {
			return count;
		}
		tmp = tmp->next;
		count++;
	}
	return 0;
}

int edgeExists(struct nGraph *G, int head, int tail) 
{
	struct edge *tmp = G->E->head;
	while (tmp != NULL) {
		if (((tmp->head == head && tmp->tail == tail) || 
		     (tmp->head == head && tmp->tail == head)) ||
		    ((tmp->head == tail && tmp->tail == tail) ||
		 	 (tmp->head == tail && tmp->tail == head))) {
			return 0;
		}
		tmp = tmp->next;
	}
	return 1;
}

void addRandomEdge(struct nGraph *G, int weight)
{
	struct edge *tmp = malloc(sizeof(struct edge));
	tmp->weight = weight;
	int randomHead = rand() % G->V->count;
	int randomTail = rand() % G->V->count;
	while (randomTail == randomHead) {
		randomTail = rand() % G->V->count;
	}
	tmp->head   = randomHead;
	tmp->tail   = randomTail;

	if (edgeExists(G, tmp->head, tmp->tail)) {
		if (G->E->count == 0) {
			G->E->head = tmp;
			G->E->tail = tmp;
			G->E->count++;
		}
		else {
			G->E->tail->next = tmp;
			G->E->tail       = tmp;
			G->E->count++;
		}
	}
}

void addEdge(struct nGraph *G, int head, int tail, int weight)
{
	if (head != tail) {
		if (!searchVertex(G, head)) {
			printf("invalid vertex %d in edge %d->%d\n", head, head, tail);
			return;
		}
		if (!searchVertex(G, tail)) {
			printf("invalid vertex %d in edge %d->%d\n", tail, head, tail);
			return; 
		}
		struct edge *tmp = malloc(sizeof(struct edge));
		tmp->weight = weight;
		tmp->head   = head;
		tmp->tail   = tail;
	
		if (G->E->count == 0) {
			G->E->head = tmp;
			G->E->tail = tmp;
			G->E->count++;
		}
		else {
			G->E->tail->next = tmp;
			G->E->tail       = tmp;
			G->E->count++;
		}
	}
}
int vertexSize(struct nGraph *G)
{
	struct vertex *tmp = G->V->head;
	int count = 0; 
	while(tmp != NULL) {
		if (count == (G->V->count-1)) {
			//printf("%d ", tmp->label);
		}
		else {
			//printf("%d, ", tmp->label);
		}
		tmp = tmp->next;
		count++;
	}
	return count;
	
}
void addVertex(struct nGraph *G, int c)
{
	struct vertex *tmp = malloc(sizeof(struct vertex));
	tmp->label = c;

	if (G->V->count == 0) {
		G->V->head = tmp;
		G->V->tail = tmp;
		G->V->count++;
	}
	else {
		G->V->tail->next = tmp;
		G->V->tail       = tmp;
		G->V->count++;	
	}
}

void makeCompleteGraph(struct nGraph *G, int size)
{
	int i, j;
	for (i = 0; i < size; i++) 
		addVertex(G, i);
	for (i = 0; i < size; i++) {
		for (j = i; j < size; j++) {
			addEdge(G, i, j, 0);
		}
	}
}

void listVertices(struct nGraph *G)
{
	struct vertex *tmp = G->V->head;
	printf("%c.V = { ", G->label);
	int count = 0; 
	while(tmp != NULL) {
		if (count == (G->V->count-1)) {
			printf("%d ", tmp->label);
		}
		else {
			printf("%d, ", tmp->label);
		}
		tmp = tmp->next;
		count++;
	}
	printf("}\n");
}

void listEdges(struct nGraph *G)
{
	struct edge *tmp = G->E->head;
	printf("%c.E = { ", G->label);
	int count = 0; 
	while (tmp != NULL) {
		if (count == (G->E->count-1)) {
			printf("%d->%d ", tmp->head, tmp->tail);
		}
		else {
			printf("%d->%d, ", tmp->head, tmp->tail);
		}
		tmp = tmp->next;
		count++;
	}
	printf("}\n");
}





/********************************************************

Below Here is the Additional Assignment Code



*********************************************************/






struct nGraph unionGrpah(struct nGraph *G1,struct nGraph *G2)
{
	struct edge *tmp1 = G1->E->head;
	struct edge *tmp2 = G2->E->head;
	struct vertex *tmp3 = G1->V->head;
	struct vertex *tmp4 = G2->V->head;

	//Make New Graph
	struct nGraph G4 ;	
	nGraphInit(&G4, 'C');
	//Copying Vertex of G1 to new Graph G4
	while(G1->V->head!=NULL){	
		addVertex(&G4,G1->V->head->label);
		G1->V->head=G1->V->head->next;
	}
	G1->V->head=tmp3;
	//Copying Edge of G1 to new Graph G4
	while(tmp1!=NULL){
		addEdge(&G4, tmp1->head, tmp1->tail, 0);
		tmp1=tmp1->next;
	}

	//Union of G1 and G2 Vertex 
	while (G2->V->head != NULL)
	{
			if (!searchVertex(&G4,G2->V->head->label))
			{
				addVertex(&G4, G2->V->head->label);
			}
			G2->V->head=G2->V->head->next;
	}

	//Union of G1 and G2 Edges
	while (tmp2 != NULL)
	{

			if (edgeExists(&G4, tmp2->head, tmp2->tail))
			{
				//printf("%d->%d, ", tmp2->head, tmp2->tail);

				addEdge(&G4, tmp2->head, tmp2->tail, 0);
			}

			tmp2=tmp2->next;
	}

	//Returning G1 and G2 to their head pointers
	G1->V->head=tmp3;
	G2->V->head=tmp4;


	return G4;
}


struct nGraph intersectGrpah(struct nGraph *G1,struct nGraph *G2)
{
	struct edge *tmp1 = G1->E->head;
	struct edge *tmp2 = G2->E->head;
	struct vertex *tmp3 = G1->V->head;
	struct vertex *tmp4 = G2->V->head;
	
	//Make New Graph
	struct nGraph G9 ;
	nGraphInit(&G9, 'D');


	//Intersection oof G1 and G2 Vertex
	while (G2->V->head != NULL)
	{
			if (searchVertex(G1,G2->V->head->label))
			{	
				//printf("%d, ", G2->V->head->label);
				addVertex(&G9, G2->V->head->label);
			}
			G2->V->head=G2->V->head->next;
	}
	
		
	G2->E->head=tmp2;

	//Intersection of G1 and G2 Edges
	while (tmp2 != NULL)
	{
			if (!edgeExists(G1, tmp2->head, tmp2->tail))
			{
				//printf("%d->%d, ", tmp2->head, tmp2->tail);

				addEdge(&G9, tmp2->head, tmp2->tail, 0);
			}
			tmp2=tmp2->next;
	}

	//Returning G1 and G2 to their head pointers
	G1->V->head=tmp3;
	G2->V->head=tmp4;
	return G9;
}

struct nGraph ringSum(struct nGraph *G1,struct nGraph *G2)
{
	struct edge *tmp1 = G1->E->head;
	struct edge *tmp2 = G2->E->head;
	struct vertex *tmp3 = G1->V->head;
	struct vertex *tmp4 = G2->V->head;
	struct edge *tmpA=malloc(sizeof(G1->E->head)) ;
	struct edge *tmpB=malloc(sizeof(G2->E->head)) ;
	struct edge *headA=tmpA;
	struct edge *headB=tmpB;

	//Make New Graph
	struct nGraph G10 ;
	nGraphInit(&G10, 'E');

	//Copying Vertex of G1 to new Graph G10
	while(G1->V->head!=NULL){
		addVertex(&G10,G1->V->head->label);
		G1->V->head=G1->V->head->next;
	}
	G1->V->head=tmp3;



	//Union of G1 and G2 Vertex 
	while (G2->V->head != NULL)	
	{
			if (!searchVertex(&G10,G2->V->head->label))
			{
				addVertex(&G10, G2->V->head->label);
			}
			G2->V->head=G2->V->head->next;
	}
	

	
	//Doing (G2-G1)Union(G1-G2) for Edges using 2 while loops 
	while (tmp1 != NULL)
	{
			
			if (edgeExists(G2, tmp1->head, tmp1->tail))
			{
				
				//printf("%d->%d, ", tmp1->head, tmp1->tail);
				//printf("%s\n","--");
				tmpA->head=	tmp1->head;
				tmpA->tail=	tmp1->tail;	
				addEdge(&G10, tmp1->head, tmp1->tail, 0);
			}

			tmp1=tmp1->next;
	}
	while (tmp2 != NULL)
	{

			if (edgeExists(G1, tmp2->head, tmp2->tail))
			{
				//printf("%d->%d, ", tmp2->head, tmp2->tail);
				//printf("%s\n","--");
				tmpB->head=	tmp2->head;
				tmpB->tail=	tmp2->tail;	
				addEdge(&G10, tmp2->head, tmp2->tail, 0);
			}

			tmp2=tmp2->next;
	}
	tmpA=headA;
	tmpB=headB;

	/*
	while(tmpA!=NULL){
		addEdge(&G10, tmpA->head, tmpA->tail, 0);
		tmpA=tmpA->next;
	}

	while(tmpB!=NULL){
		addEdge(&G10, tmpB->head, tmpB->tail, 0);
		tmpB=tmpB->next;
	}*/
	


	//listEdges(&G10);


	G1->V->head=tmp3;
	G2->V->head=tmp4;



	return G10;
}

struct nGraph neighbours(struct nGraph *G1,int c)
{

	struct edge *tmp1 = G1->E->head;
	struct vertex *tmp3 = G1->V->head;

	//make new Graph
	struct nGraph G15 ;
	nGraphInit(&G15, 'F');
	G1->V->head=tmp3;


	//Finding Neighbours of a given vertex in Graph G1
	if (searchVertex(G1,c)){
		while (tmp1!=NULL){
		if(tmp1->head==c){
			//printf("%s %d %s %d\n", "Neighbour of ",c," :",tmp1->tail );
			addVertex(&G15,tmp1->tail);
		}
		else if(tmp1->tail==c){
			//printf("%s %d %s %d\n", "Neighbour of ",c," :",tmp1->head );
			addVertex(&G15,tmp1->head);
		}
		else{

		}
		tmp1=tmp1->next;
		}
	}
	else{
		printf("%s\n","Vertex not present in this graph" );
	}


	return G15;
}





void BK(struct nGraph PP,struct nGraph P, struct nGraph R, struct nGraph X){

	struct vertex *temporary ;

	struct nGraph GV;
	nGraphInit(&GV, 'G');

	struct nGraph UnionOfPX;	
	
	struct nGraph NeighboursOfP;

	struct nGraph tempP;//P
	struct nGraph tempR;//R
	struct nGraph tempX;//X

	
	nGraphInit(&UnionOfPX, 'G');
	UnionOfPX=unionGrpah(&P,&X);	//PUX
	int sizeOfVertexUnion=vertexSize(&UnionOfPX);
	
	if(sizeOfVertexUnion==0){
		printf("%s\n", "------------------------------------------");
		
		if(max.V->count < R.V->count ){

			nGraphInit(&max, 'M');
			max=R;
		}
		printf("%s", "Maximal Clique : ");
		listVertices(&R);


		printf("%s\n", "------------------------------------------");
		
		return ;
	}



	while (P.V->head != NULL)	
	{	

		sizeOfVertexUnion=vertexSize(&R);

		nGraphInit(&GV, 'G');
		addVertex(&GV,P.V->head->label);
	
		
		nGraphInit(&NeighboursOfP, 'G');
		NeighboursOfP=neighbours(&PP,P.V->head->label);	

	
		nGraphInit(&tempP, 'P');
		tempP=intersectGrpah(&P,&NeighboursOfP);	//P N N(v)

		nGraphInit(&tempR, 'R');	
		tempR=unionGrpah(&R,&GV);	//R U (v)

		nGraphInit(&tempX, 'X');
		tempX=intersectGrpah(&X,&NeighboursOfP);	//X N N(v)

		BK(PP,tempP,tempR,tempX);



		temporary = P.V->head;
		P.V->head=P.V->head->next;	
		free(temporary);

		X=unionGrpah(&X,&GV);
	

		
	}

	



}

struct nGraph FindingCliques(struct nGraph G1)
{

	struct vertex *tmp1 = G1.V->head;
	struct nGraph P ;
	nGraphInit(&P, 'P');

	struct nGraph X ;
	nGraphInit(&X, 'X');

	struct nGraph R;
	nGraphInit(&R, 'R');

	nGraphInit(&max, 'M');
	while (G1.V->head != NULL)	
	{
		addVertex(&P, G1.V->head->label);
			
		G1.V->head=G1.V->head->next;
	}

	G1.V->head=tmp1;


	clock_t tic = clock();
	BK(G1,P,R,X);
	clock_t toc = clock();
	printf("%s\n", "==================");
		//printf("%d\n", G1.E->count);
		printf("%s","Maximum:  ");
		listVertices(&max);
		

	printf("%s\n", "==================");
		
	
	printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);

	return G1;
}
