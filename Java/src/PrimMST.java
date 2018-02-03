import java.io.PrintWriter;
import java.util.Scanner;

public class PrimMST {
	int N;
	int totalCost;
	int graphNodeIDarray[];
	
	edgeNode edgeList;
	graphNode setA;
	graphNode setB;
	edgeNode MSTofG; 	
	
	PrimMST() {
		N = 0;
		totalCost = 0;
		graphNodeIDarray = new int[N];
		edgeList = new edgeNode();
		setA = new graphNode();
		setB = new graphNode();
		MSTofG = new edgeNode();
	}
	
	void PrimsMST(Scanner inFile, PrintWriter outFile1, PrintWriter outFile2) {
		N = inFile.nextInt();
		graphNodeIDarray = new int[N];
		
		while (inFile.hasNext()) {//0
			edgeNode newEdgeNode = new edgeNode(inFile.nextInt(), inFile.nextInt(), inFile.nextInt());//1.1
			edgeList.insert(newEdgeNode);//1.2
			graphNodeIDarray[newEdgeNode.Ni - 1]++;//1.3
			graphNodeIDarray[newEdgeNode.Nj - 1]++;
		}//2
		
		outFile2.println("Graph Node 1D Array:");//3
		for (int i = 0; i < graphNodeIDarray.length; i++) {
			outFile2.print(graphNodeIDarray[i] + " ");
		}
		
		outFile2.println();
		outFile2.println();
		
		outFile2.println("Edge List:");
		if (edgeList != null) {
			edgeNode traveler = edgeList;
			
			traveler = traveler.Next;
			traveler.printEdgeNode(outFile2, 10);
		}
		
		boolean A = false;
		for (int i = 0; i < graphNodeIDarray.length; i++) {
			if (graphNodeIDarray[i] > 0 && A == false) {//4
				graphNode newGraphNode = new graphNode(i + 1);
				setA.insert(newGraphNode);
				A = true;
			}
			
			else {//5
				graphNode newGraphNode = new graphNode(i + 1);
				setB.insert(newGraphNode);
			}
		}//6
		
		int num = 1;
		while (!setB.isEmpty()) {
			boolean mst = false;
			edgeNode newEdge = edgeList;//7
			
			while (mst == false && newEdge.Next != null) {
				
				if (setA.contains(newEdge.Next.Ni) && setB.contains(newEdge.Next.Nj)) {
					setA.insert(setB.delete(newEdge.Next.Nj));
					mst = true;
				}
				
				else if (setA.contains(newEdge.Next.Nj) && setB.contains(newEdge.Next.Ni)) {	
					setA.insert(setB.delete(newEdge.Next.Ni));
					mst = true;
				}
				
				if (mst == true) {
					totalCost += newEdge.Next.edgeCost; 
					MSTofG.insert(new edgeNode(newEdge.Next.Ni, newEdge.Next.Nj, newEdge.Next.edgeCost));//8
					
					outFile2.println();
					outFile2.print("Set A: ");//9
					setA.printGraphNode(outFile2);
					outFile2.print('\n' + "Set B: ");
					setB.printGraphNode(outFile2);
					outFile2.println('\n' + "Minimum Spanning Tree: ");
					MSTofG.printEdgeNode(outFile2, num);
					newEdge.delete();
					num++;
				}
				newEdge = newEdge.Next;
			}
		}//10
		
		outFile1.println("Minimum Spanning Tree" + '\n' + N);//11
		MSTofG.printEdgeNode(outFile1, num);
		outFile1.print("Total Cost is: " + totalCost);
	}
}
