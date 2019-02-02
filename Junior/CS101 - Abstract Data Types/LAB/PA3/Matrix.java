//Justin Fortner
//ID#1481947
//jfortner
//CS101 PA3 Tantalo
//Matrix.java

@SuppressWarnings("overrides")
public class Matrix{
	// Constructor
	private class Entry{
		int col;
		double data;
		Entry(int col, double data){
			this.col = col;
			this.data = data;
		}
		public boolean equals(Object e){
			Entry E = (Entry) e;
			if(col==E.col && data==E.data){
				return true;
			}
			else{
				return false;
			}
		}
		public String toString(){
			String string = "(" + col + ", " + data + ") ";
			return string;
		}
	}
	private int size, NNZ;
	private List[] row;
	
	// Makes a new n x n zero Matrix. pre: n>=1
	Matrix(int n){
		size = n;
		NNZ = 0;
		row = new List[n+1];
		for(int i = 1; i <= n; i++){
			row[i] = new List();
		}
	}	
	
	// Access functions
	
	// Returns n, the number of rows and columns of this Matrix
	int getSize(){
		return size;
	}
	
	// Returns the number of non-zero entries in this Matrix
	int getNNZ(){
		//System.out.println("NNZ: " + NNZ);
		return NNZ;
	}
	
	// overrides Object's equals() method
	public boolean equals(Object x){
		Matrix M = (Matrix)x;
		if(getSize()!=M.getSize()){
			return false;
		}	
		for(int i = 1; i <= getSize(); i++){
			if(!(M.row[i].equals((row[i])))){
				//System.out.println(M.row[i]);
				//System.out.println(row[i]);
				return false;
			}
		}
		return true; 
	}
	
	// Manipulation procedures
	
	// sets this Matrix to the zero state
	void makeZero(){
		for(int i = 1; i <= getSize(); i++){
			row[i].clear();
		}
		NNZ = 0;
	}	
	
	// returns a new Matrix having the same entries as this Matrix
	Matrix copy(){
		Matrix M = new Matrix(getSize());
		for(int i = 1; i <= getSize(); i++){
			row[i].moveFront();
			while(row[i].index() >= 0){
				Entry entry = (Entry) row[i].get();
				M.changeEntry(i, entry.col, entry.data);
				row[i].moveNext();
			}
		}
		return M;
	}
	
	// changes ith row, jth column of this Matrix to x
	// pre: 1<=i<=getSize(), 1<=j<=getSize()
	void changeEntry(int i, int j, double x){
		//System.out.println(x);
		Entry E = new Entry (j, x);
		row[i].moveFront();
		if(((row[i].length()<j && E.data!=x) || row[i].length()==0) && x!=0){
			row[i].append(E);
			NNZ++;
			return;
		}
		else if(row[i].length() > 0 && x == 0){
			row[i].moveFront();
			while(row[i].index() >= 0){
				Entry entry = (Entry) row[i].get();
				if(entry.col == j){
					row[i].delete();
					NNZ--;
				}
				row[i].moveNext();
			}
			return;
		}
		else if(row[i].length() > 0 && x != 0){
			row[i].moveFront();
			Entry entry = (Entry) row[i].get();
			if(j > row[i].length()){
				row[i].append(E);
				NNZ++;
			}
			else if(j < entry.col){
				row[i].prepend(E);
				NNZ++;
			}
			else{
				while(row[i].index() >= 0){
					if(entry.col == j){
						if(entry.data == 0){
							NNZ++;
						}
						//System.out.println("entry data" + entry.data);
						//System.out.println("E data" + E.data);
						entry.data = E.data;
						break;
					}
					else if(entry.col > j){
						row[i].insertBefore(E);
						NNZ++;
						break;
					}
					row[i].moveNext();
				}
			}
		}
	}
	
	// returns a new Matrix that is the scalar product of this Matrix with x
	Matrix scalarMult(double x){
		//System.out.println("X: " + x);
		Matrix tM = new Matrix(getSize());
		double mult;
		for(int i = 1; i <= getSize(); i++){
			row[i].moveFront();
			while(row[i].index() >= 0){
				Entry entry = (Entry) row[i].get();
				mult = entry.data * x;
				//System.out.println("Mult: " + mult);
				tM.changeEntry(i, entry.col, mult);
				//System.out.println("MScalar: " + tM);
				row[i].moveNext();
			}
		}
		//System.out.println("MScalar Final: " + tM);
		return tM;
	}
	
	// returns a new Matrix that is the sum of this Matrix with M
	// pre: getSize()==M.getSize()
	Matrix add(Matrix M){
		double add;
		Matrix tempM = new Matrix(getSize());
		List temp1, temp2;
		if(equals(M)){
			return M.scalarMult(2.0);
		}
		else{
			//System.out.println("In else");
			for(int i = 1; i <= getSize(); i++){
				temp1 = row[i];
				temp2 = M.row[i];
				temp1.moveFront();
				temp2.moveFront();
				while(temp1.index() >= 0 || temp2.index() >= 0){
					if(temp1.length()!=0 && temp2.length()!=0 && temp1.index() >= 0 && temp2.index() >= 0){
						Entry entry1 = (Entry) temp1.get();
						//System.out.println("Entry1 data1: " + entry1.data);
						//System.out.println("Entry1 col1: " + entry1.col);
						Entry entry2 = (Entry) temp2.get();
						//System.out.println("Entry2 data: " + entry2.data);
						//System.out.println("Entry2 col: " + entry2.col);
						if(entry1.col == entry2.col){
							add = entry1.data + entry2.data;
							//System.out.println("Add: " + add);
							//System.out.println("M1: " + tempM);
							tempM.changeEntry(i, entry2.col, add);
							//System.out.println("M2: " + tempM);
							temp1.moveNext();
							temp2.moveNext();
						}
						if(entry1.col < entry2.col){
							//System.out.println("M3: " + tempM);
							//System.out.println("Entry1 data2: " + entry1.data);
							//System.out.println("Entry1 col2: " + entry1.col);
							tempM.changeEntry(i, entry1.col, entry1.data);
							//System.out.println("M4: " + tempM);
							temp1.moveNext();
						}
						if(entry1.col > entry2.col){
							//System.out.println("M5: " + tempM);
							//System.out.println("Entry1 data2: " + entry1.data);
							//System.out.println("Entry1 col2: " + entry1.col);
							tempM.changeEntry(i, entry2.col, entry2.data);
							//System.out.println("M6: " + tempM);
							temp2.moveNext();
						}
					}
					else if(temp1.index() == -1){
						Entry entry2 = (Entry) temp2.get();
						tempM.changeEntry(i, entry2.col, entry2.data);
						break;
					}
					else if(temp2.index() == -1){
						Entry entry1 = (Entry) temp1.get();
						tempM.changeEntry(i, entry1.col, entry1.data);
						break;
					}
					else if(temp1.length()!=0 && temp2.length()==0){
						tempM.row[i] = temp1;
						break;
					}
					else if(temp1.length()==0 && temp2.length()!=0){
						tempM.row[i] = temp2;
						break;
					}
				}
			}
		}
		//System.out.println("M7: " + tempM);
		return tempM;
	}
	
	// returns a new Matrix that is the difference of this Matrix with M
	// pre: getSize()==M.getSize()
	Matrix sub(Matrix M){
		double add;
		Matrix tempM = new Matrix(getSize());
		List temp1, temp2;
		if(equals(M)){
			return M.scalarMult(0.0);
		}
		else{
			M = M.scalarMult(-1.0);
			tempM = add(M);
		}
		//System.out.println("M7: " + tempM);
		return M;
	}
	
	// returns a new Matrix that is the transpose of this Matrix
	Matrix transpose(){
		Matrix transM = new Matrix(getSize());
		for(int i = 1; i <= getSize(); i++){
			row[i].moveFront();
			while(row[i].index() >= 0){
				Entry entry = (Entry) row[i].get();
				transM.changeEntry(entry.col, i, entry.data);
				row[i].moveNext();
			}
		}
		//System.out.println("trans final: " + transM); 
		return transM;
	}
	
	// returns a new Matrix that is the product of this Matrix with M
	// pre: getSize()==M.getSize()
	Matrix mult(Matrix M){
		//System.out.println("this: " + this);
		Matrix tempM1 = M.transpose();
		Matrix tempM3 = new Matrix(getSize());
		//System.out.println("TempM1: " + tempM1);
		for(int i = 1; i <= getSize(); i++){
			if(row[i].length() != 0){
				//System.out.println("i: " + i);
				for(int k = 1; k <= tempM3.getSize(); k++){
					if(tempM1.row[k].length() != 0){
						//System.out.println("k: " + k);
						double dot = dot(row[i], tempM1.row[k]);
						tempM3.changeEntry(i, k, dot);
						//System.out.println("TempM3 NNZ: " + tempM3.NNZ);
						//System.out.println("TempM3 1: " + tempM3);
					}
				}
			}
		}
		//System.out.println("TempM3 2: " + tempM3);
		return tempM3;
	}
	
	
	private static double dot(List P, List Q){
		double num = 0;
		P.moveFront();
		Q.moveFront();
		//System.out.println("P Init Index: " + P.index());
		//System.out.println("Q Init Index: " + Q.index());
		//System.out.println("In dot");
		while(P.index() >= 0 || Q.index() >= 0){
			if(P.length()!=0 && Q.length()!=0 && P.index() >= 0 && Q.index() >= 0){
				Entry entryP = (Entry) P.get();
				Entry entryQ = (Entry) Q.get();
				//System.out.println("EntryP data: " + entryP.data);
				//System.out.println("EntryP col: " + entryP.col);
				//System.out.println("EntryQ data: " + entryQ.data);
				//System.out.println("EntryQ col: " + entryQ.col);
				if(entryP.col == entryQ.col){
					num = num + entryP.data * entryQ.data;
					//System.out.println("num " + num);
					//System.out.println("");
					P.moveNext();
					Q.moveNext();
				}
				if(entryP.col < entryQ.col){
					//System.out.println("P next");
					P.moveNext();
					//System.out.println("P Index: " + P.index());
				}
				if(entryP.col > entryQ.col){
					//System.out.println("Q next");
					Q.moveNext();
					//System.out.println("Q Index: " + Q.index());
				}
			}
			else if(P.index() == -1){
				num = num;
				break;
			}
			else if(Q.index() == -1){
				num = num;
				break;
			}
			else if(P.length()!=0 && Q.length()==0){
				num = num;
				break;
			}
			else if(P.length()==0 && Q.length()!=0){
				num = num;
				break;
			}
		}
		//System.out.println("");
		//System.out.println("num final " + num);
		//System.out.println("");
		return num;
	}
	
	// Other functions
	
	// overrides Object's toString() method
	public String toString(){
		String string = "";
		int col;
		double data;
		for(int i = 1; i <= getSize(); i++){
			row[i].moveFront();
			if(row[i].length() != 0){
				string = string + (i + ": ");
				while(row[i].index() >= 0){
					Entry entry = (Entry) row[i].get();
					col = entry.col;
					data = entry.data;
					string = string + "(" + col + ", " + data + ") ";
					row[i].moveNext();
				}
				string = string + "\n";
			}
		}
			
		return string;
	}
}