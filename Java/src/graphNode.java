import java.io.PrintWriter;

public class graphNode {
	int nodeID;
	graphNode Next;
	
	boolean isEmpty() {
		if (Next == null) {
			return true;
		}
		return false;
	}
		
	graphNode() {
		nodeID = 0;
		Next = null;
	}
	
	graphNode(int id) {
		nodeID = id;
		Next = null;
	}
	
	boolean contains(int id) {
		graphNode traveler = this;
		
		while (!traveler.isEmpty()) {
			traveler = traveler.Next;
			
			if (traveler.nodeID == id) {
				return true;
			}	
		}
		return false;
	}
	
	void insert(graphNode gN) {
		if (isEmpty()) {
			Next = gN;
		}
		
		else {
			gN.Next = Next;
			Next = gN;
		}
	}
	
	graphNode delete(int id) {
		graphNode temp = null;
		graphNode traveler = this;
		
		while (!traveler.isEmpty()) {
			if (traveler.Next.nodeID == id) {
				temp = traveler.Next;
				
				if (!temp.isEmpty()) {
					traveler.Next = temp.Next;
				}
				
				else {
					traveler.Next = null;
				}
				
				break;
			}
			
			traveler = traveler.Next;
		}
		return temp;
	}
	
	void printGraphNode(PrintWriter outFile) {
		graphNode traveler = this;
		
		while (!traveler.isEmpty()) {
			traveler = traveler.Next;
			outFile.print(traveler.nodeID + " ");
		}
	}
}
