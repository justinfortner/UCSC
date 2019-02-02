//Justin Fortner
//ID#1481947
//jfortner
//CS101 PA4 Tantalo
//Graph.c

#include<string.h>
#include<stdio.h>
#include <stdlib.h>
#include"Graph.h"

//Graph Constructor with all variables specified in lab manual
typedef struct GraphObj{
	int size;
	int order;
	int source;
	List *L;
	int *parent;
	int *color;
	int *distance;
} GraphObj;

//initalize a new graph
Graph newGraph(int n){
	//printf("start newGraph");
	//allocate all memory needed for the graph
	Graph G = malloc(sizeof(GraphObj));
	G->L = calloc(n+1, sizeof(List));
	G->parent = calloc(n+1, sizeof(int));
	G->color = calloc(n+1, sizeof(int));
	G->distance = calloc(n+1, sizeof(int));
	//initalize the size, order and source
	G->size = 0;
	G->order = n;
	G->source = NIL;
	//initalize the lists
	for(int i = 1; i <= n; i++){
		G->L[i] = newList();
		G->color[i] = WHITE;
		G->parent[i] = NIL;
		G->distance[i] = INF;
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
	free(&(G->L));
	free(&(G->parent));
	free(&(G->color));
	free(&(G->distance));
	free(*pG);
	*pG = NULL;
	//printf("end freeGraph");
}

//get the order
int getOrder(Graph G){
	return G->order;
}

//get the size
int getSize(Graph G){
	return G->size;
}

//get the source
int getSource(Graph G){
	return G->source;
}

//get the parent
int getParent(Graph G, int u){
		return G->parent[u];
}

//get the distance
int getDist(Graph G, int u){
	//if the souce is NIL then no path thus INF
	if(G->source == NIL){
		return INF;
	}
	//otherwise return the distance 
		return G->distance[u];
}

//get the path
void getPath(List L, Graph G, int u){
	//if the source equals the vertex then append to the list
	if(G->source == u){
		append(L, G->source);
	}
	//if the parent in NIL append NIL
	else if(G->parent[u] == NIL){
		append(L, NIL);
	}
	//otherwise get the path and append the vertex
	else{
		getPath(L, G, G->parent[u]);
		append(L, u);
	}
}

//make the graph null
void makeNull(Graph G){
	//make all the lists null in the graph
	for(int i = 1; i <= getOrder(G); i++){
		clear(G->L[i]);
	}
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

//Breadth First Search
void BFS(Graph G, int s){
	//initalize the elements in the graph to be WHITE with a distance of INF and a NIL parent
	for(int i = 0; i <= getOrder(G); i++){
		G->color[i] = WHITE;
		G->distance[i] = INF;
		G->parent[i] = NIL;
	}
	//source to s, color to GRAY, duatance to 0, parent to NIL
	G->source = s;
	G->color[s] = GRAY;
	G->distance[s] = 0;
	G->parent[s] = NIL;
	//create a new list
	List L1 = newList();
	//put the source in the list
	append(L1, s);
	//while the list has elements in it loop
	while(length(L1) > 0){
		//get the front element
		int x = front(L1);
		//delete the front element of the list
		deleteFront(L1);
		//Create a new list and move to the front of it
		List adj = G->L[x];
		moveFront(adj);
		//while we are in this list loop though it
		while(index(adj) != -1){
			//get the current element in the list
			int y = get(adj);
			//if the color is white or hasnt been discovered then
			if(G->color[y] == WHITE){
				//discover it
				G->color[y] = GRAY;
				//set the distance
				G->distance[y] = G->distance[x] + 1;
				//set the parent
				G->parent[y] = x;
				//append it ot the list
				append(L1, y);
			}
			//move to the next element
			moveNext(adj);
		}
		//set the color to black for done
		G->color[x] = BLACK;
	}
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

