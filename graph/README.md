# Data Structure : Graph 

## Breadth First Search
BFS is a traversing algorithm where you start with a node and traverse all its child node before traversing children of its child i.e travese the graph layerwise thus exploring the neighbour nodes(nodes which are directly connected to source node). You must then move towards the next-level neighbour nodes.
As the name BFS suggests, you are required to traverse the graph breadthwise as follows:
    1. First move horizontally and visit all the nodes of the current layer
    2. Move to next layer
Consider the following diagram:
![bfs-tree](https://he-s3.s3.amazonaws.com/media/uploads/fdec3c2.jpg)

The distance between the nodes in layer 1 is comparitively lesser than the distance between the nodes in layer 2. Therefore, in BFS, you must traverse all the nodes in layer 1 before you move to the nodes in layer 2.

Traversing child nodes

A graph can contain cycles, which may bring you to the same node again while traversing the graph. To avoid processing of same node again, use a boolean array which marks the node after it is processed. While visiting the nodes in the layer of a graph, store them in a manner such that you can traverse the corresponding child nodes in a similar order.

In the earlier diagram, start traversing from 0 and visit its child nodes 1, 2, and 3. Store them in the order in which they are visited. This will allow you to visit the child nodes of 1 first (i.e. 4 and 5), then of 2 (i.e. 6 and 7), and then of 3 (i.e. 7) etc.

To make this process easy, use a queue to store the node and mark it as 'visited' until all its neighbours (vertices that are directly connected to it) are marked. The queue follows the First In First Out (FIFO) queuing method, and therefore, the neigbors of the node will be visited in the order in which they were inserted in the node i.e. the node that was inserted first will be visited first, and so on. 

**Pseudocode**
```
BFS (G, s)                   //Where G is the graph and s is the source node
      let Q be queue.
      Q.enqueue( s ) //Inserting s in queue until all its neighbour vertices are marked.

      mark s as visited.
      while ( Q is not empty)
           //Removing that vertex from queue,whose neighbour will be visited now
           v  =  Q.dequeue( )

          //processing all the neighbours of v  
          for all neighbours w of v in Graph G
               if w is not visited 
                        Q.enqueue( w )             //Stores w in Q to further visit its neighbour
                        mark w as visited.
```

**Complexity**
The time complexity of BFS is O(V+E), where V is the number of nodes and E is the number of edges.
**Application**
How to determine the level of each node in the given tree?

### 0-1 BFS
This type of BFS is used to find the shortest distance between two nodes in a graph provided that the edges have the weights 0 or 1.
In this approach, a boolean array in not used to mark the node because the condition of the optimal distance will be checked when you visit each node. A double-ended queue is used to store the node. In 0-1 BFS, if the weight of the edge = 0, then the node is pushed to the front of the dequeue. If the weight of the edge =1, then the node is pushed to the back of the dequeue.

**implementation**

Here, edges[ v ] [ i ] is an adjacency list that exists in the form of pairs i.e. edges[ v ][ i ].first will contain the node to which v is connected and edges[ v ][ i ].second will contain the distance between v and edges[ v ][ i ].first.

Q is a double-ended queue. The distance is an array where, distance[ v ] will contain the distance from the start node to v node. Initially the distance defined from the source node to each node is infinity.

```
void bfs (int start)
{
            deque <int > Q;     //Double-ended queue
            Q.push_back( start); 
            distance[ start ] = 0;       
            while( !Q.empty ())
            {
                int v = Q.front( );
                Q.pop_front(); 
                for( int i = 0 ; i < edges[v].size(); i++)
               {


/* if distance of neighbour of v from start node is greater than sum of distance of v from start node and edge weight between v and its neighbour (distance between v and its neighbour of v) ,then change it */  


                    if(distance[ edges[ v ][ i ].first ] > distance[ v ] + edges[ v ][ i ].second ) 
                {

                    distance[ edges[ v ][ i ].first ] = distance[ v ] + edges[ v ][ i ].second;

                /*if edge weight between v and its neighbour is 0 then push it to front of
        double ended queue else push it to back*/

                    if(edges[ v ][ i ].second == 0)
                    {
                        Q.push_front( edges[ v ][ i ].first);
                    }
                    else
                    {
                            Q.push_back( edges[ v ][ i ].first);

                    }
                }
              }
           }
    }

```
Let's understand this code with the following graph:

![bfs-01](https://he-s3.s3.amazonaws.com/media/uploads/2ffb073.jpg)

**Processing**

Starting from the source node, i.e 0, it will move towards 1, 2, and 3. Since the edge weight between 0 and 1 and 0 and 2 is 1 respectively, 1 and 2 will be pushed to the back of the queue. However, since the edge weight between 0 and 3 is 0, 3 will pushed to the front of the queue. The distance will be maintained in distance array accordingly.

3 will then be popped from the queue and the same process will be applied to its neighbours, and so on.

<hr>

## Depth First Search
The DFS algorithm is a recursive alorithm that uses the idea of backtracking. It involves exhaustive searches of all the nodes by going ahead, if possible, else by backtracking.
Here, the word backtrack means that when you are moving forward and there are no more nodes along the current path, you move backwards on the same path to find nodes to traverse. All the nodes will be visisted on the current path till all the unvisisited nodes have been traversed after which the next path will be selected.
This recursive nature of DFS can be implemented using stacks. The basic idea is as follows:
Pick a starting node and push all its adjacent nodes into a stack.
Pop a node from stack to select the next node to visit and push all its adjacent nodes into a stack.
Repeat this process until the stack is empty. However, ensure that the nodes that are visited are marked. This will prevent you from visiting the same node more than once. If you do not mark the nodes that are visited and you visit the same node more than once, you may end up in an infinite loop. 

** Pseudocode **
```
  DFS-iterative (G, s):                                   //Where G is graph and s is source vertex
      let S be stack
      S.push( s )            //Inserting s in stack 
      mark s as visited.
      while ( S is not empty):
          //Pop a vertex from stack to visit next
          v  =  S.top( )
         S.pop( )
         //Push all the neighbours of v in stack that are not visited   
        for all neighbours w of v in Graph G:
            if w is not visited :
                     S.push( w )         
                    mark w as visited


    DFS-recursive(G, s):
        mark s as visited
        for all neighbours w of s in Graph G:
            if w is not visited:
                DFS-recursive(G, w)

```

The following image shows how DFS works:
![dfs-traversel](https://he-s3.s3.amazonaws.com/media/uploads/9fa1119.jpg)

** Time Complexity **
O(V+E), when implemented using an adjacency list.
** Application **
How to find connected components using DFS?

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
       
