//Justin Fortner
//ID#1481947
//jfortner
//CS101 PA4 Tantalo
//List.c

#include"List.h"
#include<stdio.h>
#include <stdlib.h>

//Constructor for the nodes in the list
typedef struct NodeObj{
	//Give node a previous and next pointer
	struct NodeObj* previous;
	struct NodeObj* next;
	//the node can hold data
	int data;
} NodeObj;

typedef NodeObj* Node;

//Constructor for list	
typedef struct ListObj{
	//keep track of the front, back and current Node in the list
	Node front;
	Node current;
	Node back;
	//keep track of the current index and list length
	int index;
	int length;
} ListObj;

// initialize a new list
List newList(void){ // Creates a new empty list.
	//declare a new list and allocate memory for the list
	List L = malloc(sizeof(ListObj));
	//set front, back and current element to NULL
	L->front = NULL;
	L->current = NULL;
	L->back = NULL;
	//set the index to off the list
	L->index = -1;
	//set the length to 0
	L->length = 0;
	//return the initialized list
	return(L);
}

//free the memory allocated for the list
void freeList(List* pL){
   if(pL!=NULL && *pL!=NULL) { 
      while( !isEmpty(*pL) ) { 
         deleteFront(*pL); 
      }
   }
   free(*pL);
   *pL = NULL;
}

// initialize a new node
Node newNode(int data){
	//declare a new node and allocate memory for the node
   Node N = malloc(sizeof(NodeObj));
   N->previous = NULL;
   N->next = NULL;
   N->data = data;
   return(N);
}

//free the memory allocated for the node
void freeNode(Node* pN){
   if( pN!=NULL && *pN!=NULL ){
      free(*pN);
      *pN = NULL;
   }
}

//check if the list is empty
int isEmpty(List L){
	//if the length is 0 then empty and return 1
	if(L->length == 0){
		return 1;
	}
	//otherwise return 0
	else{
		return 0;
	}
}

// Access functions
// Returns the number of elements in this List.
int length(List L){ 
	//returns the length of the lsit
	return L->length;
}
// If cursor is defined, returns the index of the cursor element,
// otherwise returns -1.
int index(List L){
	//if the index is greater than the list then it is off the list
	//if the index is before the first element in the list then it is off the list
	if(L->index > L->length-1 || L->index < 0){
		//-1 indicates undefinded index
		L->index = -1;
	}
	//otherwise return the index
	return L->index;
}
// Returns front element. Pre: length()>0
int front(List L){
	//get data in front element and return it
	return L->front->data;
}
// Returns back element. Pre: length()>0
int back(List L){
	//get data in back element and return it
	return L->back->data;
}
// Returns cursor element. Pre: length()>0, index()>=0
int get(List L){
	//get data in current element and return it
	return L->current->data;
}
// Returns true if and only if this List and L are the same
// integer sequence. The states of the cursors in the two Lists
// are not used in determining equality.
// Manipulation procedures
int equals(List A, List B){
	//set temp nodes to keep track of positions in the two lists
	Node temp1 = A->front;
	Node temp2 = B->front;
	//if the lengths are different of course they wont be equal
	if(A->length != B->length){
		return 0;
	}
	//loop through the lists
	while(temp1!=NULL){
		//if data in the lists when they are at the same element isnt equal
		//then they arent equal
		if(temp1->data != temp2->data){
			return 0;
		}
		//increment spot in the lists
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	//if they are equal return true
	return 1;
}
// Resets this List to its original empty state.
void clear(List L){
	//reset length to 0 and index to undefinded
	L->length = 0;
	L->index = -1;
	//set pointers to null
	L->front = NULL;
	L->current = NULL;
	L->back = NULL;
}
// If List is non-empty, places the cursor under the front element,
// otherwise does nothing.
void moveFront(List L){
	//if the length of the list is greater then 0 set the current element to be the front element
	if(L->length > 0){
		//set the current to the front
		L->current = L->front;
		//set the index to the first element
		L->index = 0;
	}
	//otherwise do nothing because either no elements or 1 in which case already at front
}
// If List is non-empty, places the cursor under the back element,
// otherwise does nothing.
void moveBack(List L){
	//if the length of the list is greater then 0 set the current element to be the back element
	if(L->length > 0){
		//set the current element to the back
		L->current = L->back;
		//set the index to the last element in the list
		L->index = L->length-1;
	}
	//otherwise do nothing because either no elements or 1 in which case already at back
}
// If cursor is defined and not at front, moves cursor one step toward
// front of this List, if cursor is defined and at front, cursor becomes
// undefined, if cursor is undefined does nothing.
void movePrev(List L){
	//if there is a current element and its not the front 
	if(L->current!=NULL && L->current!=L->front){
		//move the current to be previous and set the index to be one less
		L->current = L->current->previous;
		L->index--;
	}
	//if there is a current element and its the front 
	else if(L->current!=NULL && L->current==L->front){
		//set the current element to NULL and put the index off the list
		L->current = NULL;
		L->index = -1;
	}
	//otherwise set the index to off the list
	else{
		L->index = -1;
	}
}
// If cursor is defined and not at back, moves cursor one step toward
// back of this List, if cursor is defined and at back, cursor becomes
// undefined, if cursor is undefined does nothing.
void moveNext(List L){
	//if there is a current element and its not the back 
	if(L->current!=NULL && L->current!=L->back){
		//set the current element to NULL and increment the index
		L->current = L->current->next;
		L->index++;
	}
	//if there is a current element and its the back 
	else if(L->current!=NULL && L->current==L->back){
		//set the current element to NULL and put the index off the list
		L->current = NULL;
		L->index = -1;
	}
	else{
		L->index = -1;
	}
}
// Insert new element into this List. If List is non-empty,
// insertion takes place before front element.
void prepend(List L, int data){
	//create the new element node
	Node newEle = newNode(data);
	//if empty place at front. no pointers to rearrange
	if(L->length <= 0){
		L->front = newEle;
		L->current = newEle;
		L->back = newEle;
	}
	//place at front and rearrange pointers
	else{
		L->front->previous = newEle;
		newEle->next = L->front;
		L->front = newEle;
		L->index++;
	}
	//increment the length
	L->length++;
}
// Insert new element into this List. If List is non-empty,
// insertion takes place after back element.
void append(List L, int data){
	//create the new element node
	Node newEle = newNode(data);
	//if empty place at end. no pointers to rearrange
	if(L->length <= 0){
		L->front = newEle;
		L->current = newEle;
		L->back = newEle;
	}
	//place at end and rearrange pointers
	else{
		L->back->next = newEle;
		newEle->previous = L->back;
		L->back = newEle;
	}
	//increment the length
	L->length++;
}
// Insert new element before cursor.
// Pre: length()>0, index()>=0
void insertBefore(List L, int data){
	//create the new element node
	Node newEle = newNode(data);	
	//if it is the first element just call prepend
	if(L->index <= 0){
		prepend(L, data);
	}
	//otherwise rearrange pointers and increment the index/length
	else{
		L->current->previous->next = newEle;
		newEle->previous = L->current->previous;
		newEle->next = L->current;
		L->current->previous = newEle;
		L->length++;
		L->index++;
	}
}
// Inserts new element after cursor.
// Pre: length()>0, index()>=0
void insertAfter(List L, int data){
	//create the new element node
	Node newEle = newNode(data);
	//if it is the first element just call append
	if(L->index<=0 || L->index==L->length-1){
		append(L, data);
	}
	//otherwise rearrange pointers and increment the index/length
	else{
		L->current->next->previous = newEle;
		newEle->next = L->current->next;
		newEle->previous = L->current;
		L->current->next = newEle;
		L->length++;
	}
}
// Deletes the front element. Pre: length()>0
void deleteFront(List L){
	//if there is only one elemt just clear the list
	if(L->length <= 1){
		 clear(L);
	}
	//rearrange pointers and decrement length/index
	else{
		L->front = L->front->next;
		L->front->previous = NULL;
		L->length--;
		L->index--;
	}
}
// Deletes the back element. Pre: length()>0
void deleteBack(List L){
	//if there is only one element just clear the list
	if(L->length <= 1){
		 clear(L);
	}
	//rearrange pointers and decrement length
	else{
		L->back = L->back->previous;
		L->back->next = NULL;
		L->length--;
	}
}
// Deletes cursor element, making cursor undefined.
// Pre: length()>0, index()>=0
// Other methods
void delete(List L){
	//if the current is back use deleteBack
	if(L->current == L->back){
		deleteBack(L);
	}
	//if current is front use delete front
	else if(L->current == L->front){
		deleteFront(L);
	}
	//otherwise rearrange pointers to no longer point at current node
	//fix length and index
	else{
		L->current->next->previous = L->current->previous;
		L->current->previous = L->current->next;
		L->current = NULL;
		L->length--;
		L->index = -1;
	}
}
// Overrides Object's toString method. Returns a String
// representation of this List consisting of a space
// separated sequence of integers, with front on left.
void printList(FILE* out, List L){
	//set the temp node to the front node in the lsit
	Node temp = L->front;
	//while that node isnt null loop through the list
	while (temp != NULL){
		//print out that data
		fprintf(out,"%d ", temp->data);
		//move temp to the next node in the list
		temp = temp->next;
	}
}
// Returns a new List representing the same integer sequence as this
// List. The cursor in the new list is undefined, regardless of the
// state of the cursor in this List. This List is unchanged.
List copyList(List L){
	//create a new list to copy to
	List newL = newList();
	//create a temp node to keep track
	Node temp = L->front;	
	//loop through the list until no elements left
	while(temp != NULL){
		//add an element to the end of copy list
		insertAfter(newL, temp->data);
		//increment elelemtn in origional list
		temp = temp->next;
	}
	//return the new list
	return newL;
}
// Returns a new List which is the concatenation of
// this list followed by L. The cursor in the new List
// is undefined, regardless of the states of the cursors
// in this List and L. The states of this List and L are
// unchanged.
//List concatList(List A, List B){
	
//}