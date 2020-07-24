# Data Structure : Graph 

## Minimum Spanning Tree

### Spanning Tree
A connected and undirecred graph G=(V,E), a spanning tree of the graph G is a tree that spans G(that is, it includes every vertex of G) and is a subgraph of G(every edge in the tree belongs to G).
### Minimum spanning Tree
The cost of the spanning tree is the sum of the weights of all the edges in the tree. There can be many spanning trees. Minimum spanning tree is the spanning tree where the cost is minimum among all the spanning trees.
    1) Minimum cost of covering/spaning all the vertex
    2) There can be many spanning Tree

![spanning-tree](https://he-s3.s3.amazonaws.com/media/uploads/146b47a.jpg)


### Algorithms For Finding the Minimum Spanning Tree
 1) **Kruskal's Algorithm**
 2) **Prim's Algorithm**
     
### Kruskal's Algorithm
Kruskal’s Algorithm builds the spanning tree by adding edges one by one into a growing spanning tree. Kruskal's algorithm follows greedy approach as in each iteration it finds an edge which has least weight and add it to the growing spanning tree. 

     Algorithm Steps:
          * Sort the graph edges with respect to their weights.
          * Start adding edges to the MST from the edge with smallest weight until the edge of the largest weight.
          * Only add edges which doesn't form a cycle, edges which connect only disconnected components.
       
