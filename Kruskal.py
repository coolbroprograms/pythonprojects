

GEEKSFORGEEKS
Kruskal’s Minimum Spanning Tree Algorithm | Greedy Algo-2
What is a Spanning Tree?
A Spanning tree is a subset to a connected graph G, where all the edges are connected, i.e, one can traverse to any edge from a particular edge with or without intermediates. Also, a spanning tree must not have any cycle in it. Thus we can say that if there are N vertices in a connected graph then the no. of edges that a spanning tree may have is N-1.

What is a Minimum Spanning Tree? 
Given a connected and undirected graph, a spanning tree of that graph is a subgraph that is a tree and connects all the vertices together. A single graph can have many different spanning trees. A minimum spanning tree (MST) or minimum weight spanning tree for a weighted, connected, undirected graph is a spanning tree with a weight less than or equal to the weight of every other spanning tree. The weight of a spanning tree is the sum of weights given to each edge of the spanning tree.

How many edges does a minimum spanning tree has? 
A minimum spanning tree has (V – 1) edges where V is the number of vertices in the given graph. 

What are the applications of the Minimum Spanning Tree? 
See this for applications of MST.



 

How to find MST using Kruskal’s algorithm?
Below are the steps for finding MST using Kruskal’s algorithm:



Sort all the edges in non-decreasing order of their weight. 
Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. If cycle is not formed, include this edge. Else, discard it. 
Repeat step#2 until there are (V-1) edges in the spanning tree.
Step #2 uses the Union-Find algorithm to detect cycles. 

So we recommend reading the following post as a prerequisite. 

Union-Find Algorithm | Set 1 (Detect Cycle in a Graph) 
Union-Find Algorithm | Set 2 (Union By Rank and Path Compression)
Kruskal’s algorithm to find the minimum cost spanning tree uses the greedy approach. The Greedy Choice is to pick the smallest weight edge that does not cause a cycle in the MST constructed so far. Let us understand it with an example:

Below is the illustration of the above approach:

Input Graph:
 


Kruskal’s Minimum Spanning Tree Algorithm

The graph contains 9 vertices and 14 edges. So, the minimum spanning tree formed will be having (9 – 1) = 8 edges. 

After sorting:
Weight   Src    Dest
1         7      6
2         8      2
2         6      5
4         0      1
4         2      5
6         8      6
7         2      3
7         7      8
8         0      7
8         1      2
9         3      4
10        5      4
11        1      7
14        3      5
Now pick all edges one by one from the sorted list of edges 
Step 1: Pick edge 7-6: No cycle is formed, include it. 
 


Kruskal’s Minimum Spanning Tree Algorithm



Step 2:  Pick edge 8-2: No cycle is formed, include it. 
 


Kruskal’s Minimum Spanning Tree Algorithm

Step 3: Pick edge 6-5: No cycle is formed, include it. 
 


Kruskal’s Minimum Spanning Tree Algorithm

Step 4: Pick edge 0-1: No cycle is formed, include it. 
 


Kruskal’s Minimum Spanning Tree Algorithm

Step 5: Pick edge 2-5: No cycle is formed, include it. 
 


Kruskal’s Minimum Spanning Tree Algorithm

Step 6: Pick edge 8-6: Since including this edge results in the cycle, discard it.
Step 7: Pick edge 2-3: No cycle is formed, include it. 
 


Kruskal’s Minimum Spanning Tree Algorithm



Step 8: Pick edge 7-8: Since including this edge results in the cycle, discard it.
Step 9: Pick edge 0-7: No cycle is formed, include it. 
 


Kruskal’s Minimum Spanning Tree Algorithm

Step 10: Pick edge 1-2: Since including this edge results in the cycle, discard it.
Step 11: Pick edge 3-4: No cycle is formed, include it. 
 


Kruskal’s Minimum Spanning Tree Algorithm

Note: Since the number of edges included in the MST equals to (V – 1), so the algorithm stops here.

Recommended: Please try your approach on {IDE} first, before moving on to the solution.
Below is the implementation of the above approach:

# Python program for Kruskal's algorithm to find
# Minimum Spanning Tree of a given connected,
# undirected and weighted graph
 
# Class to represent a graph
 
 

class Graph:
 

    def __init__(self, vertices):

        self.V = vertices  # No. of vertices

        self.graph = []

        # to store graph
 

    # function to add an edge to graph

    def addEdge(self, u, v, w):

        self.graph.append([u, v, w])
 

    # A utility function to find set of an element i

    # (truly uses path compression technique)

    def find(self, parent, i):

        if parent[i] != i:

          # Reassignment of node's parent to root node as

          # path compression requires

            parent[i] = self.find(parent, parent[i])

        return parent[i]
 

    # A function that does union of two sets of x and y

    # (uses union by rank)

    def union(self, parent, rank, x, y):

        

        # Attach smaller rank tree under root of

        # high rank tree (Union by Rank)

        if rank[x] < rank[y]:

            parent[x] = y

        elif rank[x] > rank[y]:

            parent[y] = x
 

        # If ranks are same, then make one as root

        # and increment its rank by one

        else:

            parent[y] = x

            rank[x] += 1
 

    # The main function to construct MST using Kruskal's

        # algorithm

    def KruskalMST(self):
 

        result = []  # This will store the resultant MST
 

        # An index variable, used for sorted edges

        i = 0
 

        # An index variable, used for result[]

        e = 0
 

        # Step 1:  Sort all the edges in

        # non-decreasing order of their

        # weight.  If we are not allowed to change the

        # given graph, we can create a copy of graph

        self.graph = sorted(self.graph,

                            key=lambda item: item[2])
 

        parent = []

        rank = []
 

        # Create V subsets with single elements

        for node in range(self.V):

            parent.append(node)

            rank.append(0)
 

        # Number of edges to be taken is equal to V-1

        while e < self.V - 1:
 

            # Step 2: Pick the smallest edge and increment

            # the index for next iteration

            u, v, w = self.graph[i]

            i = i + 1

            x = self.find(parent, u)

            y = self.find(parent, v)
 

            # If including this edge doesn't

            # cause cycle, then include it in result

            # and increment the index of result

            # for next edge

            if x != y:

                e = e + 1

                result.append([u, v, w])

                self.union(parent, rank, x, y)

            # Else discard the edge
 

        minimumCost = 0

        print("Edges in the constructed MST")

        for u, v, weight in result:

            minimumCost += weight

            print("%d -- %d == %d" % (u, v, weight))

        print("Minimum Spanning Tree", minimumCost)
 
 
# Driver's code

if __name__ == '__main__':

    g = Graph(4)

    g.addEdge(0, 1, 10)

    g.addEdge(0, 2, 6)

    g.addEdge(0, 3, 5)

    g.addEdge(1, 3, 15)

    g.addEdge(2, 3, 4)
 

    # Function call

    g.KruskalMST()
