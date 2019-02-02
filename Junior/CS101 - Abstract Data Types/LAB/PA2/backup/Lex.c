//Justin Fortner
//ID#1481947
//jfortner
//CS101 PA2 Tantalo
//Lex.c

#include"List.h"
#include<stdio.h>
#include <stdlib.h>
#include<string.h>


#define MAX_LEN 1000
   
int main(int argc, char * argv[]){
	//initialize variables
	FILE *in, *out;
	char line[MAX_LEN];
	char* lineList[MAX_LEN];
	int count = 0;
	List L = newList();
	// check command line for correct number of arguments
	if( argc != 3 ){
		printf("Usage: %s <input file> <output file>\n", argv[0]);
		exit(1);
	}

	// open files for reading and writing 
	in = fopen(argv[1], "r");
	out = fopen(argv[2], "w");

	//while there is a line in the fine loop through the file
	while( fgets(line, MAX_LEN, in) != NULL)  {
		//allocate memory for array
		lineList[count] = calloc(strlen(line)+1, 1);
		//copy the line into the lineList 
		strcpy(lineList[count], line);
		//increment the counter for number of lines in the file
		count++;
	}
	//fprintf(out, "lineList: %s \n", lineList[0]);
	//fprintf(out, "count: %d \n", count);
	//for (int i = 0; i < count; i++){
		//fprintf(out, "lineList: %s \n", lineList[i]);
	//}
	
	//put a 0 into the list for the first index 
	append(L, 0);
	//move to the front of said list
	moveFront(L);
	
	//loop though the list from the second element in the list to the last
	for(int j = 1; j < count; j++){
		//while the index is defined in the list L loop though it
		while(index(L)>= 0){
			//if the element in the lineList comes before the element already in
			//the list L sort its index before that element in list L
			//if elements are equal sort before
			if(strcmp(lineList[j], lineList[get(L)])<0 || strcmp(lineList[j], lineList[get(L)])==0){
				insertBefore(L, j);
				break;
			}
			//if we get to the end of the list append the list to add the index of
			//the element to the end
			else if(index(L) == length(L)-1 && strcmp(lineList[j], lineList[get(L)])>0){
				append(L, j);
				break;
			}
			//if we havent found where it goes in the list yet move to the
			//next element in list L
			else{
				moveNext(L);
			}
		}
		//move the index to the front of list L so we can loop through it again
		moveFront(L);
	  }
	  
	  //move to the front of list L that has sorted indicies of 
	  //elements in lineList
	  moveFront(L);
	  //while we are in the list loop through it
	  while(index(L)>= 0){
		  //print the element in lineList at the index given by list L
		  fprintf(out, "%s", lineList[get(L)]);
		  //move to the enxt element in the list L
		  moveNext(L);
	  }
	
	//free the memory for the list
	freeList(&L);
	//close the files
	fclose(in);
	fclose(out);

	return(0);
}