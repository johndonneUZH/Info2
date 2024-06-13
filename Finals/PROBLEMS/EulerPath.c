 A graph is said to have an Euler Path if
-> it is a connected graph, and
-> it contains no more than two vertices of odd degree.

/*----------------------------------------------------------------------------------------------*/
WITH BFS

BFS(G)
    s.col = G;
    InitQueue(Q);
    Enqueue(Q,s);
    while Q ̸= ϕ do
        v = Dequeue(Q);
        foreach u ∈ v.adj do
            u.degree ++;
            if u.col == W then
                u.col = G; 
                Enqueue(Q,u);
        v.col = B;

hasEulerPath(G)
    foreach v ∈ G.V do
        v.col = W; 
        v.degree = 0;
    
    s = RandomVertex(G);
    G = BFS(G,s);
    oddCount = 0;
    
    foreach v ∈ G.V do
        if v.degree mod 2 ==1 then
            oddCount++;
            if oddCount > 2 or v.degree == 0 then
                return False;
    
    return True;

/*----------------------------------------------------------------------------------------------*/

Conclusion:
Incrementing u.degree before the DFS call is a valid approach for counting degrees in an undirected graph
when implementing algorithms like determining Euler paths or cycles. 
It ensures that each vertex's degree is correctly calculated considering both incoming and outgoing edges.

WITH DFS

DFS(G, v)   
    v.col = G
    for u in v.adj
        if u.col == W
            u.degree++
            DFS(G, u)
    v.col = B

  
isEuler(G)
    for v in G.V
        v.col = W
        v.degree = 0
    
    DFS_counter = 0
    for v in G.V
        if v.col = W
            DFS(G, v)
            DFS_counter++
    
    if DFS_couter > 1 return false
    
    odd_degree = 0
    for v in G.V
        if v.degree % 2 == 1
            odd_degree++
        if odd_degree > 2 return false
    
    return true


