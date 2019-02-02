//Justin Fortner
//ID#1481947
//jfortner
//CS101 PA1 Tantalo
//List.java

//Some function descriptions taken from the PA1 manual
//Some functions based on examples from Queue and Stack as 
//allowed in the PA1 manual

public class List{
	//Constructor for the nodes in the list
	private class Node{
		Node previous;
		int data;
		Node next;
		Node(int data){
			previous = null;
			this.data = data;
			next = null;
		}
	}
	
	//initialize the length to be 0
	private int length = 0;
	//initialize the index to be undefined
	private int index = -1;
	//initialize the nodes to point in front, behind, and to the current element
	private Node front;
	private Node current;
	private Node back;
	
	//Constructor for the list
	List(){ // Creates a new empty list.
		length = 0;
		index = -1;
		front = null;
		current = null;
		back = null;
	}
	// Access functions
	// Returns the number of elements in this List.
	int length(){ 
		return length;
	}
	// If cursor is defined, returns the index of the cursor element,
	// otherwise returns -1.
	int index(){
		if(index > length()-1){
			//-1 indicates undefinded index
			index = -1;
		}
		return index;
	}
	// Returns front element. Pre: length()>0
	int front(){
		//get data in front element
		return front.data;
	}
	// Returns back element. Pre: length()>0
	int back(){
		//get data in back element
		return back.data;
	}
	// Returns cursor element. Pre: length()>0, index()>=0
	int get(){
		//get data in current element
		return current.data;
	}
	// Returns true if and only if this List and L are the same
	// integer sequence. The states of the cursors in the two Lists
	// are not used in determining equality.
	// Manipulation procedures
	boolean equals(List L){
		//set temp nodes to keep track of positions in the two lists
		Node temp1 = this.front;
		Node temp2 = L.front;
		//if the lengths are different of course they wont be equal
		if(this.length != L.length){
			return false;
		}
		//loop through the lists
		while(temp1!=null){
			//if data in the lists when they are at the same element isnt equal
			//then they arent equal
			if(temp1.data != temp2.data){
				return false;
			}
			//increment spot in the lists
			temp1 = temp1.next;
			temp2 = temp2.next;
		}
		//if they are equal return true
		return true;
	}
	// Resets this List to its original empty state.
	void clear(){
		//reset length to 0 and index to undefinded
		length = 0;
		index = -1;
		//set pointers to null
		front = null;
		current = null;
		back = null;
	}
	// If List is non-empty, places the cursor under the front element,
	// otherwise does nothing.
	void moveFront(){
		if(length > 0){
			//set the current to the front
			current = front;
			//set the index to the first element
			index = 0;
		}
	}
	// If List is non-empty, places the cursor under the back element,
	// otherwise does nothing.
	void moveBack(){
		if(length > 0){
			//set the current element to the back
			current = back;
			//set the index to the last element in the list
			index = length-1;
		}
	}
	// If cursor is defined and not at front, moves cursor one step toward
	// front of this List, if cursor is defined and at front, cursor becomes
	// undefined, if cursor is undefined does nothing.
	void movePrev(){
		if(current!=null && current!=front){
			current = current.previous;
			index--;
		}
		else if(current!=null && current==front){
			current = null;
			index = -1;
		}
		else{
			index = -1;
		}
	}
	// If cursor is defined and not at back, moves cursor one step toward
	// back of this List, if cursor is defined and at back, cursor becomes
	// undefined, if cursor is undefined does nothing.
	void moveNext(){
		if(current!=null && current!=back){
			current = current.next;
			index++;
		}
		else if(current!=null && current==back){
			current = null;
			index = -1;
		}
		else{
			index = -1;
		}
	}
	// Insert new element into this List. If List is non-empty,
	// insertion takes place before front element.
	void prepend(int data){
		//create the new element node
		Node newEle = new Node(data);
		
		//if empty place at front. no pointers to rearrange
		if(length <= 0){
			front = newEle;
			current = newEle;
			back = newEle;
			length++;
		}
		//place at front and rearrange pointers
		else{
			front.previous = newEle;
			newEle.next = front;
			front = newEle;
			index++;
			length++;
		}
	}
	// Insert new element into this List. If List is non-empty,
	// insertion takes place after back element.
	void append(int data){
		//create the new element node
		Node newEle = new Node(data);
		
		//if empty place at end. no pointers to rearrange
		if(length <= 0){
			front = newEle;
			current = newEle;
			back = newEle;
			length++;
		}
		//place at end and rearrange pointers
		else{
			back.next = newEle;
			newEle.previous = back;
			back = newEle;
			length++;
		}
	}
	// Insert new element before cursor.
	// Pre: length()>0, index()>=0
	void insertBefore(int data){
		//create the new element node
		Node newEle = new Node(data);
		
		//if it is the first element just call prepend
		if(index <= 0){
			prepend(data);
		}
		//otherwise rearrange pointers and increment the index/length
		else{
			current.previous.next = newEle;
			newEle.previous = current.previous;
			newEle.next = current;
			current.previous = newEle;
			length++;
			index++;
		}
	}
	// Inserts new element after cursor.
	// Pre: length()>0, index()>=0
	void insertAfter(int data){
		//create the new element node
		Node newEle = new Node(data);
		
		//if it is the first element just call append
		if(index<=0 || index==length-1){
			append(data);
		}
		//otherwise rearrange pointers and increment the index/length
		else{
			current.next.previous = newEle;
			newEle.next = current.next;
			newEle.previous = current;
			current.next = newEle;
			length++;
		}
	}
	// Deletes the front element. Pre: length()>0
	void deleteFront(){
		//if there is only one elemt just clear the list
		if(length <= 1){
			clear();
		}
		//if the front element is the current element then rearrange pointers
		//and set index to undefined
		if(current == front){
			front = front.next;
			front.previous = null;
			length--;
			index = -1;
		}
		//else just rearrange pointerss and realligh the index
		else{
			front = front.next;
			front.previous = null;
			length--;
			index--;
		}
	}
	// Deletes the back element. Pre: length()>0
	void deleteBack(){
		//if there is only one elemt just clear the list
		if(length <= 1){
			clear();
		}
		//rearrange pointers
		else{
			back = back.previous;
			back.next = null;
			length--;
		}
	}
	// Deletes cursor element, making cursor undefined.
	// Pre: length()>0, index()>=0
	// Other methods
	void delete(){
		//if the current is back use deleteBack
		if(current == back){
			deleteBack();
		}
		//if current is front use delete front
		else if(current == front){
			deleteFront();
		}
		//otherwise rearrange pointers to no longer point at current node
		//fix length and index
		else{
			current.next.previous = current.previous;
			current.previous = current.next;
			current = null;
			length--;
			index = -1;
		}
	}
	// Overrides Object's toString method. Returns a String
	// representation of this List consisting of a space
	// separated sequence of integers, with front on left.
	public String toString(){
		//create new string and a temp node
		String string = new String("");
		Node tempN = front;
		//loop through the list until no elements left
		while(tempN != null){
			//string is equal to the current string plus a space to separate them
			string += tempN.data + " ";
			//increment element in list
			tempN = tempN.next;
		}
		return string;
	}
	// Returns a new List representing the same integer sequence as this
	// List. The cursor in the new list is undefined, regardless of the
	// state of the cursor in this List. This List is unchanged.
	List copy(){
		//create a new list to copy to
		List L = new List();
		//create a temp node to keep track
		Node tempN = front;
		
		//loop through the list until no elements left
		while(tempN != null){
			//add an element to the end of copy list
			L.append(tempN.data);
			//increment elelemtn in origional list
			tempN = tempN.next;
		}
		return L;
	}
	// Returns a new List which is the concatenation of
	// this list followed by L. The cursor in the new List
	// is undefined, regardless of the states of the cursors
	// in this List and L. The states of this List and L are
	// unchanged.
	//List concat(List L){
		
	//}
}  