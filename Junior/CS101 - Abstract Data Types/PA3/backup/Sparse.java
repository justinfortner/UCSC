//Justin Fortner
//ID#1481947
//jfortner
//CS101 PA3 Tantalo
//Sparse.java

import java.io.*;
import java.util.Scanner;
   
public class Sparse{
   public static void main(String[] args) throws IOException{
      Scanner in = null;
      PrintWriter out = null;
      String line = null;
	  int n, a, b, row, col;
	  double entry;

	  //Quit with message stderr is more or less 
	  //than two strings are given on the command line
      if(args.length != 2){
         System.err.println("stderr Usage: FileIO infile outfile");
         System.exit(1);
      }
      
	  //raken in input file and output file
      in = new Scanner(new File(args[0]));
      out = new PrintWriter(new FileWriter(args[1]));
	  
	  n = in.nextInt();
	  a = in.nextInt();
	  b = in.nextInt();
	  
	  Matrix A = new Matrix(n);
	  
	  in.nextLine();
	  
	  for(int i = 0; i < a; i++){
		  row = in.nextInt();
		  col = in.nextInt();
		  entry = in.nextDouble();
		  //System.out.println(entry);
		  A.changeEntry(row, col, entry);
	  }
	  
	  Matrix B = new Matrix(n);
	  
	  for(int i = 0; i < b; i++){
		  row = in.nextInt();
		  col = in.nextInt();
		  entry = in.nextDouble();
		  B.changeEntry(row, col, entry);
	  }
	  
	  out.println("A has " + a + " non-zero entries:");
	  out.println(A);
	  
	  out.println("B has " + b + " non-zero entries:");
	  out.println(B);
	  
	  out.println("(1.5)*A =");
	  out.println((A.scalarMult(1.5)));
	  
	  out.println("A+B = ");
	  out.println(A.add(B));
	  
	  out.println("A+A =");
	  out.println(A.add(A));
	  
	  out.println("B-A =");
	  out.println(B.sub(A));
	  
	  out.println("A-A =");
	  out.println(A.sub(A));
	  
	  out.println("Transpose(A) =");
	  out.println(A.transpose());
	  
	  out.println("A*B =");
	  out.println(A.mult(B));
	  
	  out.println("B*B = ");
	  out.println(B.mult(B));
	  
	  //close the files used in this program
      in.close();
      out.close();
   }
}