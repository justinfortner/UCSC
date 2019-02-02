//Justin Fortner
//ID#1481947
//jfortner
//CS101 PA3 Tantalo
//MatrixTest.java

public class MatrixTest{
   public static void main(String[] args){
	  
	  int n = 3;
	  int a = 3;
	  int b = 3;
	  
	  Matrix A = new Matrix(n);
	  
	  for(int i = 1; i <= n; i++){
		  for(int j = 1; j <= n; i++){
			int row = i;
			int col = j;
			int entry = i;
			//System.out.println(entry);
			A.changeEntry(row, col, entry);
		  }
	  }
	  
	  Matrix B = new Matrix(n);
	  
	  for(int i = 1; i <= n; i++){
		  for(int j = 1; j <= n; i++){
			int row = i;
			int col = j;
			int entry = i;
			//System.out.println(entry);
			B.changeEntry(row, col, entry);
		  }
	  }
      
	  if(A.getSize() == n){
		  System.out.println("A size equals n");
	  }
	  
	  if(B.getSize() == n){
		  System.out.println("B size equals n");
	  }
	  
	  if(A.getSize() == a){
		  System.out.println("A NNZ equals a");
	  }
	  
	  if(B.getSize() == a){
		  System.out.println("B NNZ equals a");
	  }
	  
	  
	  if(B.equals(B)){
		  System.out.println("B equals B");
	  }
	  
	  if(A.equals(B)){
		  System.out.println("A equals A");
	  }
	  
	  if(!A.equals(B)){
		  System.out.println("A does not equal B");
	  }
	  
	  if(!B.equals(A)){
		  System.out.println("B does not equal A");
	  }
	  
	  Matrix C = new Matrix(n);
	  
	  C = B.copy();
	  
	  if(C.equals(B)){
		  System.out.println("C equals B");
	  }
	  
	  if(B.equals(C)){
		  System.out.println("B equals C");
	  }
	  
	  C.scalarMult(-1.0);
	  System.out.println("C matrix: " + C);
	  
	  C.scalarMult(-1.0);
	  System.out.println("C matrix: " + C);
	  
	  C.scalarMult(-2.0);
	  System.out.println("C matrix: " + C);
	  
	  C.scalarMult(-1.0);
	  System.out.println("C matrix: " + C);
	  
	  C.scalarMult(2.0);
	  System.out.println("C matrix: " + C);
	  
	  C.scalarMult(0.0);
	  System.out.println("C matrix: " + C);
	  
	  C = B.copy();
	  System.out.println("C matrix: " + C);
	  
	  C.add(C);
	  System.out.println("C matrix: " + C);
	  
	  C.add(B);
	  System.out.println("C matrix: " + C);
	  
	  C.sub(B);
	  System.out.println("C matrix: " + C);
	  
	  C.sub(C);
	  System.out.println("C matrix: " + C);
	  
	  C.add(A);
	  System.out.println("C matrix: " + C);
	  
	  C.add(A);
	  System.out.println("C matrix: " + C);
	  
	  C.sub(A);
	  System.out.println("C matrix: " + C);
	  
	  C.sub(A);
	  System.out.println("C matrix: " + C);
	  
	  C.transpose();
	  System.out.println("C matrix: " + C);
	  
	  A.mult(A);
	  System.out.println("A matrix: " + A);
	  
	  A.mult(A);
	  System.out.println("A matrix: " + A);
	  
	  B.mult(A);
	  System.out.println("B matrix: " + B);
	  
	  C.makeZero();
	  System.out.println("C matrix: " + C);
	  
	  B.mult(C);
	  System.out.println("C matrix: " + C);
	  
   }
}