//Justin Fortner
//ID#1481947
//jfortner
//CS101 PA1 Tantalo
//Lex.java

import java.io.*;
import java.util.Scanner;
   
public class Lex{
   public static void main(String[] args) throws IOException{
      Scanner in = null;
      PrintWriter out = null;
      String line = null;
      String[] token = null;
      int i, n, lineNumber = 0;

	  //Quit with message stderr is more or less 
	  //than two strings are given on the command line
      if(args.length < 2 || args.length > 2){
         System.err.println("stderr Usage: FileIO infile outfile");
         System.exit(1);
      }
      
	  //raken in input file and output file
      in = new Scanner(new File(args[0]));
      out = new PrintWriter(new FileWriter(args[1]));

	  //intitalizes string to be empty
	  String file = "";
	  //out.println("before while");
      //while there is another line in the file add it to the string
	  while(in.hasNextLine()){
         line = in.nextLine()+"\n";
		 file += line;
		 //out.println("this is file: " + file);
		 //out.println("in while");
      }
	  //out.println("after while");
	  out.println("file: " + file);
	  //split around the new line characters
	  //and put those strings into an array
	  String[] fileArray = file.split("\n");
	  
	  //out.println(fileArray.length);
	  
	  for(int j = 0; j < fileArray.length; j++){
		  out.println("fileArray: " + fileArray[j]);
	  }
	  //create a new list
	  List L = new List();
	  //out.println(fileArray.length);
	  //place the index of the first element of fileArray
	  //into the new list
	  L.append(0);
	  //move the cursor to the front of the new list
	  L.moveFront();
	  
	  //the first element of fileArray is already in the list so skip over it
	  //loop through the rest of fileArray
	  for(int j = 1; j < fileArray.length; j++){
		//out.println(fileArray[j]);
		//while the index is defined in the list L loop though it
		while(L.index()>= 0){
			//out.println("in while");
			//if the element in the fileArray comes before the element already in
			//the list L sort its index before that element in list L
			//if elements are equal sort before
			if(fileArray[j].compareTo(fileArray[L.get()])<0 || fileArray[j].compareTo(fileArray[L.get()])==0){
				L.insertBefore(j);
				break;
			}
			//if we get to the end of the list append the list to add the index of
			//the element to the end
			else if(L.index() == L.length()-1 && fileArray[j].compareTo(fileArray[L.get()])>0){
				L.append(j);
				break;
			}
			//if we havent found where it goes in the list yet move to the
			//next element in list L
			else{
				L.moveNext();
			}
		}
		//out.println("out while");
		//move the index to the front of list L so we can loop through it again
		L.moveFront();
	  }
	  
	  //out.println(L.toString());
	  //move to the front of list L that has sorted indicies of 
	  //elements in fileArray
	  L.moveFront();
	  //while we are in the list loop through it
	  while(L.index()>= 0){
		  //print the element in fileArray at the index given by list L
		  out.println(fileArray[L.get()]);
		  //move to the enxt element in the list L
		  L.moveNext();
	  }
	  
	  //close the files used in this program
      in.close();
      out.close();
   }
}