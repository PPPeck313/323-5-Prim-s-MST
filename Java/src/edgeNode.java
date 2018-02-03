import java.io.PrintWriter;

public class edgeNode {
	int Ni;
	int Nj;
	int edgeCost;
	edgeNode Next;
	
	edgeNode() {
		Ni = 0;
		Nj = 0;
		edgeCost = 0;
		Next = null;
	}
	
	edgeNode(int i, int j, int c) {
		Ni = i;
		Nj = j;
		edgeCost = c;
		Next = null;
	}
	
	void insert(edgeNode eN) {
		edgeNode traveler = this;
	
		while (traveler.Next != null && eN.edgeCost > traveler.Next.edgeCost) {
			traveler = traveler.Next;
		}
		
		eN.Next = traveler.Next;
		traveler.Next = eN;
	}
	
	edgeNode delete() {
		edgeNode temp = null;
		
		if (Next != null) {
			temp = Next;
			
			if (Next.Next != null) {
				Next = Next.Next;
			}
			
			else {
				Next = null;
			}
		}
		return temp;
	}
	
	void printEdgeNode(PrintWriter outFile, int num) {
		int counter = 0;
		edgeNode traveler = this;
		
		while (traveler.Next != null && counter < num) {
			traveler = traveler.Next;
			outFile.println(traveler.Ni + " " + traveler.Nj + " " + traveler.edgeCost);
			counter++;
		}
	}
}
