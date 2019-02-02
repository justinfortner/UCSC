//Justin Fortner
//ID#1481947
//jfortner
//CS101 PA5 Tantalo
//FindComponents.c

#include"Graph.h"
#include"List.h"
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
   
int main(int argc, char * argv[]){
	//initalize variables
	FILE *in, *out;
	int n, v1, v2;
	int sCount = 0;
	List L = newList();
	
	// check command line for correct number of arguments
	if( argc != 3 ){
		printf("Usage: %s <input file> <output file>\n", argv[0]);
		exit(1);
	}
	
	//open files
	//set in to read
	in = fopen(argv[1], "r");
	//set out to write
	out = fopen(argv[2], "w");

	
	//get the size of the new graph
    fscanf(in, "%d", &n); 
    //create the new graph
	Graph G = newGraph(n);
    //while loop that contains a sort of state machine
	//loops unitl reaches the end of the file
	while(fgetc(in) != EOF) {
		//take in both vertices
		fscanf(in, "%d", &v1); 
		fscanf(in, "%d", &v2);
		//if both verticesare 0 break out of the loop
		if(v1==0 && v2==0){
			break;
		}
		//otherwise add an arc
		addArc(G, v1, v2);
		//printf("\n before print \n");
		//printGraph(stdout, G); 
		//printGraph(out, G); 
		//printf("\n after print \n");
    }
	//printf("\n after while \n");
	//print out the graph
	fprintf(out, "Adjacency list representation of G:\n");
	printGraph(out, G);
	fprintf(out, "\n");
	
	//add the vertices in ascending otder to the list
	for(int i = 1; i <= getOrder(G); i++){
		append(L, i);
	}
	
	//perform a DFS search on the graph in ascending order
	DFS(G, L);
	
	//transpose the graph
	Graph gT = transpose(G); 

	//perform a DFS on the transpose graph in order of the new list
	DFS(gT, L);
	
	//move to the front of the list
	moveFront(L);
	//while we are in the list loop through it
	while(index(L) != -1){
		//if there is no parent it is a new strongly connected component
		if(getParent(gT, get(L)) == NIL){
			//add it to the strongly connected component graph
			sCount++;
		}
		//move to the next element in the list
		moveNext(L);
	}
	
	//message needed to show that strongly connected components are coming out
	fprintf(out, "G contains %d strongly connected components: \n", sCount);
		
	//move to the back of the list
	moveBack(L);
	
	//for each strongly connected component in the graph print out a new line
	for(int i = 1; i <= sCount; i++){
		fprintf(out, "Component %d:", i);
		List temp = newList();;
		//while in the list loop backwards through it
		while(index(L) != -1){
			//fprintf(out, "\n");
			//fprintf(out, "L1 L: %d", get(L));
			//fprintf(out, "\n");
			//if there is no parent then a strongly connected component
			if(getParent(gT, get(L)) == NIL){
				//print out source of SCC
				fprintf(out, " %d", get(L));
				moveFront(temp);
				//print out the rest of the elements associated with that SCC
				while(index(temp) != -1){
					fprintf(out, " %d", get(temp));
					moveNext(temp);
				}
				clear(temp);
				//fprintf(out, "\n");
				//fprintf(out, "temp after clear: ");
				//printList(out, temp);
				//fprintf(out, "\n");
				movePrev(L);
				//break out of loop and move into the next SCC
				break;
			}
			//if there is a parent add it to the temp list
			if (getParent(gT, get(L)) != NIL){
				prepend(temp, get(L));
				//fprintf(out, "\n");
				//fprintf(out, "temp: ");
				//printList(out, temp);
				//fprintf(out, "\n");
			}
			//fprintf(out, "\n");
			//fprintf(out, "current L2: %d", get(L));
			//fprintf(out, "\n");
			//move ot the previous element in the list
			movePrev(L);
			//fprintf(out, "\n");
			//fprintf(out, "current L3: %d", get(L));
			//fprintf(out, "\n");
		}
		fprintf(out, "\n");
	}
	
	//close the files
	fclose(in);
	fclose(out);
	
	//return 0
	return(0);
}
