//Justin Fortner
//ID#1481947
//jfortner
//CS101 PA4 Tantalo
//FindPath.c

#include"Graph.h"
#include"List.h"
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
   
int main(int argc, char * argv[]){
	//initalize variables
	FILE *in, *out;
	int n, v1, v2;
	int count = 0;
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
		//take in pair of vertices
        fscanf(in, "%d", &v1); 
        fscanf(in, "%d", &v2); 
		//fprintf(out, "count: %d \n", count);
        //if we reach a pair of zeros scan again to skip over them and increment the coutner
		if(v1 == 0 && v2 == 0){
			fscanf(in, "%d", &v1); 
			fscanf(in, "%d", &v2); 
			count++;
		}
		//if the count is zero we are still adding edges to the graph
		if(count == 0){
			//fprintf(out, "V1: %d V2: %d \n", v1, v2);
			addEdge(G, v1, v2);
		}
		//if the count is 1 all the edges have been added
		//print the graph nd increment the counter
		if(count == 1){
			printGraph(out, G); 
			fprintf(out, "\n");
			count++;
		}
		//if the counter is 2 then we are in the BFS stage
		if(count == 2){
			//perform a BFS on a pair of vertices
			BFS(G, v1);
			//make sure the list is empty
			clear(L);
			//get the path from the two vertices
			getPath(L, G, v2);
			//if there is no parth pring out this response
			if(getDist(G, v2) == INF){
				fprintf(out, "The distance from %d to %d is infinity\n", v1, v2);
				fprintf(out, "No %d-%d path exists\n\n", v1, v2);
			}
			//if there is a path print out this response
			else{
				fprintf(out, "The distance from %d to %d is %d\n", v1, v2, length(L)-1);
				fprintf(out, "A shortest %d-%d path is: ", v1, v2);
				printList(out, L);
				fprintf(out, "\n\n");
			}
		}
		//printf("\n before print \n");
		//printGraph(stdout, graph); 
		//printGraph(out, graph); 
		//printf("\n after print \n");
    }
	
	//close the files
	fclose(in);
	fclose(out);
	
	//return 0
	return(0);
}
