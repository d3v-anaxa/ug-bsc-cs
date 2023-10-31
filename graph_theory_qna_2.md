01. **Complete Graph :** A Simple connected graph is said to be complete if all vertices are interconnected.
02. **Regular Graph :** A every vertex of graph G consist of degree K, then the graph is called k-regular graph.
03. **Biparted Graph :** If the vertex set V of graph G can be partitioned into two non-empty disjoint subset X and Y in a way such that edge of G has one end in X and another end in Y, then G is called Biparted.
04. **Connected Graph :** An undirected graph is said to be connected if there is a path between every two vertices. 
_*[NOTE : If a graph is connected it will not bipartite.]*_

05. **Self loop :** If edge having the same vertexas both its end vertices is called self loop.
06. **Proper Edge :** An edge which is not a self loop is called a proper edge.
07. **Multi/Parallel Edge :** A collection of two or more edges having identically same end points are called multi/parallel edges. Example : 
  ```mermaid
     flowchart LR;
     n1(("V1")) ----- n2(("V2"))
     n1 --- n2
     n1 --- n2
  ```
   
08. **Simple Graph :** A Graph that does not contain any self loop or multi-edge is called  a simple graph. Example :
  ```mermaid
     graph TD;
     n1 --- n2
     n2 --- n3
     n3 --- n4
     n4 --- n1
     n1 --- n3
     n2 --- n4
  ```
   
09. **Multi Graph :** A Graph that does not contain any self loop and consist atleast one multi-edge is called a multi graph. Example :
  ```mermaid
    flowchart LR;
    a(("V1")) & b(("V2")) ----- c(("V3")) & d(("V4"))
    b ----- c
    d ----- e(("V5"))
    d ----- e
  ```
     
10. **Pseudo Graph :** A Graph that consist atleast one multi-edge and self loop is called a pseudo graph. Example :
  ```mermaid
    flowchart RL;
    a(("V1")) & b(("V2")) -- " e " --- c(("V3")) & d(("V4"))
    d(("V4")) -- " e " --- e(("V5"))
    d(("V4")) -- " e " --- e(("V5"))
    e(("V4")) -- " e " --- e(("V5"))
  ```
    
11. **Incidence and Adjacency :** Let $e_{k}$ be an edge joining two vertices $V_{1}$ and $V_{2}$. Then $e_{k}$ is said to be incident of $V_{1}$ and $V_{2}$. Two vertices are said to be adjacent if there exist an edge joining this vertices.
12. **Degree of Vertex :** In a graph, the number of edges incident on a vertex with counting a self loop twice is called the degree of the vertex. The degree of a vertex V is denoted as $d(V)$.
13. **Isolated Vertex :** In a graph, if the degree of a vertex V is 0, then V is said to be an ISOLATED VERTEX.
14. **Pendent Vertex :** In a graph, if the degree of a vertex V is 1, then V is said to be an PENDENT VERTEX.
15. **Finite and Infinite Graph :** A Finite Graph consists a finite number of edges and vertices. Whereas, an infinite graph contains infinite edges and vertices.
