A graph is said to be Biconnected if:
(a) It is connected, i.e., it is possible to reach every vertex from every other vertex, by a simple path.
(b) Even after removing any vertex the graph remains connected.

Given an undirected connected graph G and a start vertex s,
write a pseudocode algorithm that determines if the connected graph G is biconnected.

Init(G):
  foreach v ∈ G.V do
      v.color = W;
      v.deleted = false;
  return isBiConnected(G);

isBiConnected(G):
  foreach v ∈ G.V do
      v.deleted = true;
      if isConnected(G) == false then
          return false;
      v.deleted = false;
  return true;

isConnected(G):
  InitQueue(Q);
  s = randVertex(G);
  Enqueue(Q, s);
  while Q ≠ φ do
      v = Dequeue(Q);
      v.color = G;
      foreach u ∈ v.adj do
          if u.color == W and u.deleted == false then
              Enqueue(Q, u);

  foreach v ∈ G.V do
      if v.color == W and v.deleted == false then
          return false;

  foreach v ∈ G.V do
      v.color = W;
      v.deleted = false;
  return true;

randVertex(G):
  foreach v ∈ G.V do
    if v.deleted == false then
      return v

