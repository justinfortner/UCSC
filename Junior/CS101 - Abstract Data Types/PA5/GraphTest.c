//Justin Fortner
//ID#1481947
//jfortner
//CS101 PA5 Tantalo
//GraphTest.c

#include<stdio.h>
#include<stdlib.h>
#include"Graph.h"
#include"List.h"

int main(int argc, char* argv[]){
   int i, n=9;
   Graph G = NULL;

   //test newGraph
   G = newGraph(n);
   
   
   //test addArc
   addArc(G, 1, 2);
   addArc(G, 2, 1);
   addArc(G, 2, 3);
   addArc(G, 3, 5);
   addArc(G, 5, 4);
   addArc(G, 4, 3);
   addArc(G, 5, 6);
   addArc(G, 6, 8);
   addArc(G, 7, 6);
   addArc(G, 8, 7);
   addArc(G, 8, 9);
   addArc(G, 1, 3);
   addArc(G, 1, 4);
   addArc(G, 1, 5);
   addArc(G, 1, 6);
   addArc(G, 1, 7);
   addArc(G, 1, 8);
   addArc(G, 1, 9);
   addArc(G, 2, 4);
   addArc(G, 2, 5);
   addArc(G, 2, 6);
   addArc(G, 2, 7);
   addArc(G, 2, 8);
   addArc(G, 2, 9);
   addArc(G, 3, 6);
   addArc(G, 3, 7);
   addArc(G, 3, 8);
   addArc(G, 3, 9);
   addArc(G, 4, 6);
   addArc(G, 4, 7);
   addArc(G, 4, 8);
   addArc(G, 4, 9);
   addArc(G, 5, 7);
   addArc(G, 5, 8);
   addArc(G, 5, 9);
   addArc(G, 6, 9);
   addArc(G, 7, 9);
   addArc(G, 9, 9);
   
   //test print Graph
   printGraph(stdout, G);
   
   //test makeNull
   makeNull(G);
   
   //test print Graph
   printGraph(stdout, G);
   
   //test addArc
   addArc(G, 1, 2);
   addArc(G, 2, 1);
   addArc(G, 2, 3);
   addArc(G, 3, 5);
   addArc(G, 5, 4);
   addArc(G, 4, 3);
   addArc(G, 5, 6);
   addArc(G, 6, 8);
   addArc(G, 7, 6);
   addArc(G, 8, 7);
   addArc(G, 8, 9);
   addArc(G, 1, 3);
   addArc(G, 1, 4);
   addArc(G, 1, 5);
   addArc(G, 1, 6);
   addArc(G, 1, 7);
   addArc(G, 1, 8);
   addArc(G, 1, 9);
   addArc(G, 2, 4);
   addArc(G, 2, 5);
   addArc(G, 2, 6);
   addArc(G, 2, 7);
   addArc(G, 2, 8);
   addArc(G, 2, 9);
   addArc(G, 3, 6);
   addArc(G, 3, 7);
   addArc(G, 3, 8);
   addArc(G, 3, 9);
   addArc(G, 4, 6);
   addArc(G, 4, 7);
   addArc(G, 4, 8);
   addArc(G, 4, 9);
   addArc(G, 5, 7);
   addArc(G, 5, 8);
   addArc(G, 5, 9);
   addArc(G, 6, 9);
   addArc(G, 7, 9);
   addArc(G, 9, 9);
   
   //test print Graph
   printGraph(stdout, G);
   
   //test getOrder
   printf("Get Order: %d", getOrder(G));
   
   //test getSize
   printf("Get Size: %d", getSize(G));
   
   List S = newList();
   
   //test BFS
   DFS(G, S);
   
   //test getParent
   printf("Get Parent: %d", getParent(G, 7));
   
   //test getDiscover
   printf("Get Discover: %d", getDiscover(G, 7));
   
   //test getFinish
   printf("Get Finish: %d", getFinish(7));
   
   //test copy
   Graph gC = copyGraph(G);
   printGraph(stdout, gC);
   
   //test transpose
   Graph gT = transpose(G);
   printGraph(stdout, gT);
   
   //test freeGraph
   freeGraph(G);
   return(0);
}