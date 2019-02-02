//Justin Fortner
//ID#1481947
//jfortner
//CS101 PA5 Tantalo
//Graph.c

#include<string.h>
#include<stdio.h>
#include <stdlib.h>
#include"Graph.h"

void visit(Graph G, List S, int x);

//Graph Constructor with all variables specified in lab manual
typedef struct GraphObj{
	int size;
	int order;
	int time;
	List *L;
	int *parent;
	int *color;
	int *discover;
	int *finish;
} GraphObj;

//initalize a new graph
Graph newGraph(int n){
	int N = n + 1;
	//printf("start newGraph");
	//allocate all memory needed for the graph
	Graph G = malloc(sizeof(GraphObj));
	G->L = calloc(N, sizeof(List));
	G->parent = calloc(N, sizeof(int));
	G->color = calloc(N, sizeof(int));
	G->discover = calloc(N, sizeof(int));
	G->finish = calloc(N, sizeof(int));
	//initalize the size, order and time
	G->size = 0;
	G->order = n;
	G->time = 0;
	//initalize the lists
	for(int i = 1; i <= n; i++){
		G->L[i] = newList();
		G->color[i] = WHITE;
		G->parent[i] = NIL;
		G->discover[i] = UNDEF;
		G->finish[i] = UNDEF;
	}
	//printf("end newGraph");
	return G;
}

//free the memory allocated to the graph
void freeGraph(Graph* pG){
	//printf("start freeGraph");
	Graph G = *pG;
	//free the list memory for the graph
	for(int i = 1; i <= getOrder(G); i++){
		freeList(&(G->L[i]));
	}
	//free calls
	free(&(G->L));
	free(&(G->parent));
	free(&(G->color));
	free(&(G->discover));
	free(&(G->finish));
	free(*pG);
	*pG = NULL;
	//printf("end freeGraph");
}

//return the order
int getOrder(Graph G){
	return G->order;
}

//return the size
int getSize(Graph G){
	return G->size;
}

//return the parent
int getParent(Graph G, int u){
	return G->parent[u];
}

//return the discover time
int getDiscover(Graph G, int u){
	return G->discover[u];
}

//return the finish time
int getFinish(Graph G, int u){
	return G->finish[u];
}

//make the graph null
void makeNull(Graph G){
	//make all the lists null in the graph
	for(int i = 1; i <= getOrder(G); i++){
		clear(G->L[i]);
	}
	//set the size to be 0
	G->size = 0;
}

//add an edge to the graph
void addEdge(Graph G, int u, int v){
	//printf("start addEdge");
	//add two Arc will add an edge
	addArc(G, u, v);
	addArc(G, v, u);
	//decrease the size by 1 so the size is correct
	G->size--;
	//printf("end addEdge");
}

//add an arc to the graph
void addArc(Graph G, int u, int v){
	//printf("start addArc");
	//if the length is 0 then append
	if(length(G->L[u]) == 0){
		append(G->L[u], v);
		
	}
	//otherwise loop through the list
	else{
		moveFront(G->L[u]);
		while(index(G->L[u]) != -1){
			//if the list element is greater than v then insert before v amd get out of the loop
			if(get(G->L[u]) > v){
				insertBefore(G->L[u], v);
				break;
			}
			moveNext(G->L[u]);
		}
		//if we fall off the list then append it
		if(index(G->L[u]) == -1){
			append(G->L[u], v);
		}
	}
	//increase the size
	G->size++;
	//printf("end addArc");
}

//Depth First Search
void DFS(Graph G, List S){
	//printf("\n in DFS \n");
	//for the elemtns in the lsit set the color to white and the parent to none
	for(int i = 1; i <= getOrder(G); i++){
		G->color[i] = WHITE;
		G->parent[i] = NIL;
	}
	//initalize the time to be 0
	G->time = 0;
	//create a temp list of the queue
	List L1 = copyList(S);
	//clear the origional list
	clear(S);
	//move to the front of the temp list
	moveFront(L1);
	//while we are in the list loop through it
	while(index(L1) != -1){
		//get the current element in the temp list
		int x = get(L1);
		//if the color of the element is white call visit
		if(G->color[x] == WHITE){
			//pass in the graph, queue and current element
			visit(G, S, x);
		}
		//move to the nect element
		moveNext(L1);
	}
	//printf("\n end DFS \n");
}

//visit for DFS
void visit(Graph G, List S, int x){
	//printf("\n in visit \n");
	//set the color to gray
	G->color[x] = GRAY;
	//increment the time
	G->time++;
	//set the discover time
	G->discover[x] = G->time;
	//create an adjacency list
	List adj = G->L[x];
	//move to the front of the list
	moveFront(adj);
	//while in the list loop through it
	while(index(adj) != -1){
		//printf("\n in visit while \n");
		//get the current element in the list
		int y = get(adj);
		//if the color is white set the parent to x and call visit on the new element
		if(G->color[y] == WHITE){
			G->parent[y] = x;
			//printf("\n in visit while if \n");
			//printf("\n X: %d \n", x);
			visit(G, S, y);
		}
		//move to the next element
		moveNext(adj);
	}
	//printf("\n after visit while\n");
	//set the color to black
	G->color[x] = BLACK;
	//increment the time
	G->time++;
	//set the finish time
	G->finish[x] = G->time;
	//add the element to the queue
	prepend(S, x);
	//printf("\n end visit \n");
}	

//transpose the graph
Graph transpose(Graph G){
	//set a new graph with same size
	Graph gT = newGraph(G->order);
	//loop through elements in the list
	for(int i = 1; i <= getOrder(G); i++){
		//move to the front of the list
		moveFront(G->L[i]);
		//while in the list loop thorugh it
		while(index(G->L[i]) != -1){
			//get the current element of the current list
			int x = get(G->L[i]);
			//add the arc with a reverse arrow
			addArc(gT, x, i);
			//move to the enxt element
			moveNext(G->L[i]);
		}
	}
	//return the graph
	return gT;
}

//copy the graph
Graph copyGraph(Graph G){
	//set a new graph with same size
	Graph gC = newGraph(G->order);
	//loop through elements in the list
	for(int i = 1; i <= getOrder(G); i++){
		//move to the front of the list
		moveFront(G->L[i]);
		//while in the list loop thorugh it
		while(index(G->L[i]) != -1){
			//get the current element of the current list
			int x = get(G->L[i]);
			//add the arc with a reverse arrow
			addArc(gC, i, x);
			//move to the enxt element
			moveNext(G->L[i]);
		}
	}
	//return the graph
	return gC;
}

//pring the graph
void printGraph(FILE* out, Graph G){
	//printf("\n in printGraph \n");
	//printf("Order: %d \n", getOrder(G));
	//int count = 1;
	//loop through the elements
	for(int i = 1; i <= getOrder(G); i++){
		//printf("i: %d:" , i);
		//print out the line
		fprintf(out, "%d:" , i);
		//move to the front of the list
		moveFront(G->L[i]);
		//while we are in the list loop through it
		while(index(G->L[i]) != -1){
			//fprintf(out, "Count: %d for num %d", count, get(G->L[i]));
			//print out the current element of the list
			fprintf(out, " %d", get(G->L[i]));
			//move to the next element
			moveNext(G->L[i]);
			//count++;
		}
		//go to the next line
		fprintf(out, "\n");
	}
	//printf("\n end printGraph \n");
}

