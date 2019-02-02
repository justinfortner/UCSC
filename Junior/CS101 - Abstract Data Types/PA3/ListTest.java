//Justin Fortner
//ID#1481947
//jfortner
//CS101 PA3 Tantalo
//ListTest.java

public class ListTest{
   public static void main(String[] args){
      List A = new List();
      List B = new List();
      
	  System.out.println("List A: " + A);
	  System.out.println("List B: " + B);
	  
	  for(int i=1; i<=3; i++){
         A.append(i);
         B.append(i);
      }
	  
	  if(A.equals(B)){
		  System.out.println("A equals B");
	  }
	  
	  System.out.println("List A: " + A);
	  System.out.println("List B: " + B);
	  
	  for(int i=1; i<=3; i++){
         A.prepend(i);
         B.prepend(i);
      }
	  
	  if(B.equals(A)){
		  System.out.println("B equals A");
	  }
	  
	  System.out.println("List A: " + A);
	  System.out.println("List B: " + B);
	  
	  System.out.println("List A Front: " + A.front());
	  System.out.println("List B Front: " + B.front());
	  
	  System.out.println("List A Front: " + A.back());
	  System.out.println("List B Front: " + B.back());
	  
	  System.out.println("List A Undefined Index: " + A.index());
	  System.out.println("List B Undefined Index: " + B.index());
	  
	  A.moveFront();
	  B.moveBack();
	  
	  System.out.println("List A Front Index: " + A.index());
	  System.out.println("List B Front Index: " + B.index());
	  
	  for(int i = 0; i < A.length(); i++){
		System.out.println("List A Current Index: " + A.index());
		System.out.println("List A Current Item: " + A.get());
		A.moveNext();
	  }
	  
	  for(int i = 0; i < B.length(); i++){
		System.out.println("List B Current Index: " + B.index());
		System.out.println("List B Current Item: " + B.get());
		B.movePrev();
	  }
	  
	  A.moveFront();
	  B.moveFront();
	  
	  A.deleteFront();
	  B.deleteFront();
	  
	  System.out.println("List A: " + A);
	  System.out.println("List B: " + B);
	  
	  A.deleteBack();
	  B.deleteBack();
	  
	  System.out.println("List A: " + A);
	  System.out.println("List B: " + B);
	  
	  A.moveFront();
	  A.insertBefore(0);
	  
	  
	  B.moveBack();
	  B.insertAfter(0);
	  
	  if(!B.equals(A)){
		  System.out.println("B does not equal A");
	  }
	  
	  if(!A.equals(B)){
		  System.out.println("A does not equal B");
	  }
	  
	  A.moveFront();
	  B.moveBack();
	  
	  A.delete();
	  B.delete();
	  
	  if(A.equals(B)){
		  System.out.println("A equals B");
	  }
	  
	  if(B.equals(A)){
		  System.out.println("B equals A");
	  }
	
   }
}