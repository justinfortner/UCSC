//Justin Fortner
//ID#1481947
//jfortner
//CS101 PA4 Tantalo
//GraphTest.c

#include<stdio.h>
#include<stdlib.h>
#include"Graph.h"

int main(int argc, char* argv[]){
   int i, n=15;
   Graph G = NULL;

   //test newGraph
   G = newGraph(n);
   
   //test add edge
   addEdge(G, 1, 7);
   addEdge(G, 2, 3);
   addEdge(G, 2, 6);
   addEdge(G, 3, 7);
   addEdge(G, 4, 10);
   addEdge(G, 5, 9);
   addEdge(G, 5, 10);
   addEdge(G, 6, 7);
   addEdge(G, 6, 11);
   addEdge(G, 7, 12);
   addEdge(G, 8, 13);
   addEdge(G, 9, 13);
   addEdge(G, 9, 14);
   addEdge(G, 10, 15);
   addEdge(G, 14, 15);
   
   /*
   //test addArc
   addArc(G, 1, 7);
   addArc(G, 2, 3);
   addArc(G, 2, 6);
   addArc(G, 3, 7);
   addArc(G, 4, 10);
   addArc(G, 5, 9);
   addArc(G, 5, 10);
   addArc(G, 6, 7);
   addArc(G, 6, 11);
   addArc(G, 7, 12);
   addArc(G, 8, 13);
   addArc(G, 9, 13);
   addArc(G, 9, 14);
   addArc(G, 10, 15);
   addArc(G, 14, 15);
   */
   
   //test print Graph
   printGraph(stdout, G);
   
   //test makeNull
   makeNull(G);
   
   //test print Graph
   printGraph(stdout, G);
   
   //test add edge
   addEdge(G, 1, 7);
   addEdge(G, 2, 3);
   addEdge(G, 2, 6);
   addEdge(G, 3, 7);
   addEdge(G, 4, 10);
   addEdge(G, 5, 9);
   addEdge(G, 5, 10);
   addEdge(G, 6, 7);
   addEdge(G, 6, 11);
   addEdge(G, 7, 12);
   addEdge(G, 8, 13);
   addEdge(G, 9, 13);
   addEdge(G, 9, 14);
   addEdge(G, 10, 15);
   addEdge(G, 14, 15);
   
   //test print Graph
   printGraph(stdout, G);
   
   //test getOrder
   printf("Get Order: %d", getOrder(G));
   
   //test getSize
   printf("Get Size: %d", getSize(G));
   
   //test getSource
   printf("Get Source: %d", getSource(G));
   
   //test getParent
   printf("Get Parent: %d", getParent(G, 7));
   
   //test BFS
   BFS(G, 1);
   
   //test getDist
   printf("Get Dist: %d", getDist(G, 7));
   
   //test getPath
   printf("Get Order: %d", getOrder(G));

   
   //test freeGraph
   freeGraph(G);
   return(0);
}