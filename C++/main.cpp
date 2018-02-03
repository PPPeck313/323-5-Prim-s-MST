//Preston Peck
//CS 323
//November 8, 2016
//Project 5

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class graphNode {
	private:
		int nodeID;
		graphNode* Next;

	public:
		graphNode();
		graphNode(int id);
		bool isEmpty();
		bool contains(int id);
		void insert(graphNode* gN);
		graphNode* remove(int id);
		void printGraphNode(ofstream& outFile);

	friend class PrimMST;
};

class edgeNode {
	private:
		int Ni;
		int Nj;
		int edgeCost;
		edgeNode* Next;

	public:
		edgeNode();
		edgeNode(int i, int j, int c);
		void insert(edgeNode* eN);
		edgeNode* remove();
		void printEdgeNode(ofstream& outFile, int num);

	friend class PrimMST;
};

class PrimMST {
	private:
		int N;
		int totalCost;
		int* graphNodeIDarray;

		edgeNode* edgeList;
		graphNode* setA;
		graphNode* setB;
		edgeNode* MSTofG;

	public:
		PrimMST();
		void PrimsMST(ifstream& inFile, ofstream& outFile1, ofstream& outFile2);
};

	
int main(int argc, char *argv[]) {
	ifstream inFile;
	ofstream outFile1;
	ofstream outFile2;

	inFile.open(argv[1]);
	if (!inFile.is_open()) {
    	cerr<<"File failed to open!"<<endl;
    	return 0;
	}

	outFile1.open(argv[2]);
	outFile2.open(argv[3]);

	PrimMST* mst = new PrimMST();
	mst->PrimsMST(inFile, outFile1, outFile2);

	inFile.close();
	outFile1.close();
	outFile2.close();
}
	


graphNode::graphNode() {
	nodeID = 0;
	Next = NULL;
}

graphNode::graphNode(int id) {
	nodeID = id;
	Next = NULL;
}

bool graphNode::isEmpty() {
if (Next != NULL) {
		return false;
	}
	return true;
}

bool graphNode::contains(int id) {
	graphNode* traveler = this;
	
	while (!traveler->isEmpty()) {
		traveler = traveler->Next;
		
		if (traveler->nodeID == id) {
			return true;
		}	
	}
	return false;
}

void graphNode::insert(graphNode* gN) {
	if (isEmpty()) {
		Next = gN;
	}
	
	else {
		gN->Next = Next;
		Next = gN;
	}
}

graphNode* graphNode::remove(int id) {
	graphNode* temp = NULL;
	graphNode* traveler = this;
	
	while (!traveler->isEmpty()) {
		if (traveler->Next->nodeID == id) {
			temp = traveler->Next;
			
			if (!temp->isEmpty()) {
				traveler->Next = temp->Next;
			}
			
			else {
				traveler->Next = NULL;
			}
			
			break;
		}
		
		traveler = traveler->Next;
	}
	return temp;
}

void graphNode::printGraphNode(ofstream& outFile) {
	graphNode* traveler = this;
	
	while (!traveler->isEmpty()) {
		traveler = traveler->Next;
		outFile << traveler->nodeID << " ";
	}
}



edgeNode::edgeNode() {
	Ni = 0;
	Nj = 0;
	edgeCost = 0;
	Next = NULL;
}

edgeNode::edgeNode(int i, int j, int c) {
	Ni = i;
	Nj = j;
	edgeCost = c;
	Next = NULL;
}

void edgeNode::insert(edgeNode* eN) {
	edgeNode* traveler = this;

	while (traveler->Next != NULL && eN->edgeCost > traveler->Next->edgeCost) {
		traveler = traveler->Next;
	}
	
	eN->Next = traveler->Next;
	traveler->Next = eN;
}

edgeNode* edgeNode::remove() {
	edgeNode* temp = NULL;
	
	if (Next != NULL) {
		temp = Next;
		
		if (Next->Next != NULL) {
			Next = Next->Next;
		}
		
		else {
			Next = NULL;
		}
	}
	return temp;
}

void edgeNode::printEdgeNode(ofstream& outFile, int num) {
	int counter = 0;
	edgeNode* traveler = this;
	
	while (traveler->Next != NULL && counter < num) {
		traveler = traveler->Next;
		outFile << traveler->Ni << " " << traveler->Nj << " " << traveler->edgeCost << endl;
		counter++;
	}
}



PrimMST::PrimMST() {
	N = 0;
	totalCost = 0;
	graphNodeIDarray = new int[N];
	edgeList = new edgeNode();
	setA = new graphNode();
	setB = new graphNode();
	MSTofG = new edgeNode();
}

void PrimMST::PrimsMST(ifstream& inFile, ofstream& outFile1, ofstream& outFile2) {
	inFile >> N;
	graphNodeIDarray = new int[N];
	
	int i = 0;
	int j = 0;
	int c = 0;
	while (inFile >> i) {//0
		inFile >> j;
		inFile >> c;
		edgeNode* newEdgeNode = new edgeNode(i, j, c);//1.1
		edgeList->insert(newEdgeNode);//1.2
		graphNodeIDarray[newEdgeNode->Ni - 1]++;//1.3
		graphNodeIDarray[newEdgeNode->Nj - 1]++;
	}//2
	
	outFile2 << "Graph Node 1D Array:" << endl;//3
	for (int i = 0; i < N; i++) {
		outFile2 << graphNodeIDarray[i] << " ";
	}
	
	outFile2 << endl << endl << "Edge List:" << endl;
	if (edgeList != NULL) {
		edgeNode* traveler = edgeList;
		
		traveler = traveler->Next;
		traveler->printEdgeNode(outFile2, 10);
	}
	
	bool A = false;
	for (int i = 0; i < N; i++) {
		if (graphNodeIDarray[i] > 0 && A == false) {//4
			graphNode* newGraphNode = new graphNode(i + 1);
			setA->insert(newGraphNode);
			A = true;
		}
		
		else {//5
			graphNode* newGraphNode = new graphNode(i + 1);
			setB->insert(newGraphNode);
		}
	}//6
	
	int num = 1;
	while (!setB->isEmpty()) {
		bool mst = false;
		edgeNode* newEdge = edgeList;//7
		
		while (mst == false && newEdge->Next != NULL) {
			
			if (setA->contains(newEdge->Next->Ni) && setB->contains(newEdge->Next->Nj)) {
				setA->insert(setB->remove(newEdge->Next->Nj));
				mst = true;
			}
			
			else if (setA->contains(newEdge->Next->Nj) && setB->contains(newEdge->Next->Ni)) {	
				setA->insert(setB->remove(newEdge->Next->Ni));
				mst = true;
			}
			
			if (mst == true) {
				totalCost += newEdge->Next->edgeCost; 
				MSTofG->insert(new edgeNode(newEdge->Next->Ni, newEdge->Next->Nj, newEdge->Next->edgeCost));//8
				
				outFile2 << endl << "Set A: ";//9
				setA->printGraphNode(outFile2);
				outFile2 << endl << "Set B: ";
				setB->printGraphNode(outFile2);
				outFile2 << endl << "Minimum Spanning Tree: " << endl;
				MSTofG->printEdgeNode(outFile2, num);
				newEdge->remove();
				num++;
			}
			newEdge = newEdge->Next;
		}
	}//10
	
	outFile1 << "Minimum Spanning Tree" << endl << N << endl;//11
	MSTofG->printEdgeNode(outFile1, num);
	outFile1 << "Total Cost is: " << totalCost;
}