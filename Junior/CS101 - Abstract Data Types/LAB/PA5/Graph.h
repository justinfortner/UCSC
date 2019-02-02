//Justin Fortner
//ID#1481947
//jfortner
//CS101 PA5 Tantalo
//Graph.h

#include"List.h"
#include<stdio.h>
#include<stdlib.h>

#ifndef _GRAPH_H_INCLUDE_

#define _GRAPH_H_INCLUDE_

#define NIL 0
#define UNDEF -1

#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef struct GraphObj* Graph;

/* Constructors-Destructors */
Graph newGraph(int n);
void freeGraph(Graph* pG);

/* Access functions */
int getOrder(Graph G);
int getSize(Graph G);
int getParent(Graph G, int u);
int getDiscover(Graph G, int u); 
int getFinish(Graph G, int u);

/* Manipulation procedures */
void addArc(Graph G, int u, int v); 
void addEdge(Graph G, int u, int v); 
void DFS(Graph G, List S); 

/* Other Functions */
Graph transpose(Graph G);
Graph copyGraph(Graph G);
void printGraph(FILE* out , Graph G);

#endif