# 323 5-Prim-s-MST<br />
CSC 323-32: Project 5 <Prim's MST > (C++)<br />
Preston Peck<br />
Due date: Nov. 10, 2016 <br />

**** Algorithm steps for Prim's Algorithm:<br />

Step 0:  N ê get from input file<br />
     0.1: initialize all objects in PrimMST class accordingly<br />

Step 1: newEdgeNode ê read each <Ni, Nj, cost> from input file to create an edgeNode<br />
     1.1: insert newEdgeNode into edgeList (in ascending order by the cost)<br />
     1.2: graphNodeIDarray[Ni]++<br />
            graphNodeIDarray[Nj]++<br />

Step 2: repeat step 1 until the input file is empty<br />

Step 3: print graphNodeIDarry to output-2 file<br />
     3.1: print edgeList (only the first 10 edges) to output-2 file <br />
        
Step 4: k ê find the first none zero graphNodeIDarray[k],<br />
     4.1: newGraphNode ê create a new graphNode for k<br />
     4.2: insert newGraphNode into SetA <br />

Step 5: k ê get the next none zero graphNodeIDarray[k]<br />
     5.1: newGraphNode ê create a new graphNode for k<br />
     5.2: insert newGraphNode in the front of setB<br />

Step 6: repeat step 5 until reach the end of graphNodeIDarray<br />

Step 7: newEdge ê remove the front edge, say <Ni, Nj,cost>, from the edgeList<br />
            if Ni and Nj are in the same set, discards newEdge<br />
     7.1: repeat step 7 until Ni and Nj are one in setA and the other in setB<br />

Step 8: insert newEdge in the front of MSTofG<br />
     8.1: add the cost in the newEdge to totalCost<br />
     8.2: move the graphNode (Ni or Nj whoever in setB) from setB to setA <br />

Step 9: print setA to output-2 file<br />
     9.1: print setB to output-2 file<br />
     9.2: print MSTofG to output-2 file<br />

Step 10: repeat step 7 - step 9 until setB is empty<br />

Step 11: output MSTofG and the totalCost to output-1 file with proper heading, one edge with <br />
              cost per text line.<br />

Input<br />
12<br />
6 4 13<br />
12 7 13<br />
6 12 17<br />
10 12 27<br />
9 10 24<br />
2 4 18<br />
9 11 15<br />
3 2 11<br />
5 7 25<br />
1 6 13<br />
8 6 22<br />
9 8 32<br />
8 10 31<br />
5 4 26<br />
4 3 13<br />
1 2 16<br />
1 11 26<br />
3 5 14<br />
6 7 12<br />

Output<br />
Minimum Spanning Tree<br />
12<br />
3 2 11<br />
6 7 12<br />
4 3 13<br />
6 4 13<br />
1 6 13<br />
3 5 14<br />
9 11 15<br />
6 12 17<br />
8 6 22<br />
9 10 24<br />
1 11 26<br />
Total Cost is: 180<br />


Graph Node 1D Array:<br />
3 3 3 4 3 5 3 3 3 3 2 3 <br />

Edge List:<br />
6 7 12<br />
4 3 13<br />
1 6 13<br />
6 4 13<br />
3 5 14<br />
9 11 15<br />
1 2 16<br />
6 12 17<br />
2 4 18<br />
8 6 22<br />

Set A: 6 1 <br />
Set B: 12 11 10 9 8 7 5 4 3 2 <br />
Minimum Spanning Tree: <br />
1 6 13<br />

Set A: 7 6 1 <br />
Set B: 12 11 10 9 8 5 4 3 2 <br />
Minimum Spanning Tree: <br />
6 7 12<br />
1 6 13<br />

Set A: 4 7 6 1 <br />
Set B: 12 11 10 9 8 5 3 2 <br />
Minimum Spanning Tree: <br />
6 7 12<br />
6 4 13<br />
1 6 13<br />

Set A: 3 4 7 6 1 <br />
Set B: 12 11 10 9 8 5 2 <br />
Minimum Spanning Tree: <br />
6 7 12<br />
4 3 13<br />
6 4 13<br />
1 6 13<br />

Set A: 2 3 4 7 6 1 <br />
Set B: 12 11 10 9 8 5 <br />
Minimum Spanning Tree: <br />
3 2 11<br />
6 7 12<br />
4 3 13<br />
6 4 13<br />
1 6 13<br />

Set A: 5 2 3 4 7 6 1 <br />
Set B: 12 11 10 9 8 <br />
Minimum Spanning Tree: <br />
3 2 11<br />
6 7 12<br />
4 3 13<br />
6 4 13<br />
1 6 13<br />
3 5 14<br />

Set A: 12 5 2 3 4 7 6 1 <br />
Set B: 11 10 9 8 <br />
Minimum Spanning Tree: <br />
3 2 11<br />
6 7 12<br />
4 3 13<br />
6 4 13<br />
1 6 13<br />
3 5 14<br />
6 12 17<br />

Set A: 8 12 5 2 3 4 7 6 1 <br />
Set B: 11 10 9 <br />
Minimum Spanning Tree: <br />
3 2 11<br />
6 7 12<br />
4 3 13<br />
6 4 13<br />
1 6 13<br />
3 5 14<br />
6 12 17<br />
8 6 22<br />

Set A: 11 8 12 5 2 3 4 7 6 1 <br />
Set B: 10 9 <br />
Minimum Spanning Tree: <br />
3 2 11<br />
6 7 12<br />
4 3 13<br />
6 4 13<br />
1 6 13<br />
3 5 14<br />
6 12 17<br />
8 6 22<br />
1 11 26<br />

Set A: 9 11 8 12 5 2 3 4 7 6 1 <br />
Set B: 10 <br />
Minimum Spanning Tree: <br />
3 2 11<br />
6 7 12<br />
4 3 13<br />
6 4 13<br />
1 6 13<br />
3 5 14<br />
9 11 15<br />
6 12 17<br />
8 6 22<br />
1 11 26<br />

Set A: 10 9 11 8 12 5 2 3 4 7 6 1 <br />
Set B: <br />
Minimum Spanning Tree: <br />
3 2 11<br />
6 7 12<br />
4 3 13<br />
6 4 13<br />
1 6 13<br />
3 5 14<br />
9 11 15<br />
6 12 17<br />
8 6 22<br />
9 10 24<br />
1 11 26<br /><br />
