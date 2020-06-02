"# data-structure" 


### Graph
A Graph is a non-linear data structure consisting of nodes(vectices) and edges. 
//image
There are Two types of Graph:
  **Directed Graph** : have pair of ordered vertices (u,v) != (v,u)
  **Undirected Graph** : have pair of unordered vertices (u,v) == (v,u)
  
  #### Graph Representation
  **Adjacency Matrix**: A (V x V) Matrix where V is the number of vertices. If there is edge from vertex i to vertex j, then set A[i,j] = 1, else 0. If it is a weighted graph then set A[i,j] = weight/cost. Note: if all diagonals are zero, then there is no self loop.
  Advantages: Easy to implement
              Removing an edge takes O(1) time
              Search for an edge between vertex 'u' to 'v' takes O(1) time
  Disadvantages: Consumes more space O(V^2)
                 Adding a vertex is O(V^2)
                 
  **Adjacency List**: An array of linklist is used. Size of an array is equal to the number of vertices and each entry of array corresponds to a linked list of vertices adjacent to the this index.
  
   Advantages: Saves space O(v+E), worst case O(v^2)
               Adding a vertex is easier
   Disadvantage: Queries take O(v)
