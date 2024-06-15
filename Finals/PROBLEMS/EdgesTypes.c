Assume a directed graph G = (V, E) is traversed in a depth first manner. Write an
algorithm that prints the edge type of each edge of the graph during the traversal. The
edge types that must be identified are tree edges, back edges, forward edges and cross
edges.

// OFFICIAL SOLUTION //printEdges(G)
	for each v in G.V do
		v.stime = -1
		v.etime = -1
		v.pred = NULL

	t = 0
	for each v in G.V do
		if v.stime == -1
			DFS(G, v, t)

DFS(G, s, t)
	t++
	s.stime = t

	for each u in s.adj
		if u.stime == -1 		// has not yet been visited
			u.pred = s
			print(Tree Edge)
			DFS(G, u, t)

		else if s.etime == -1    // still not done with the dfs of v
			print(Back Edge u to s)

		else if s.stime < u.stime
			print(Forward Edge u to s)

		else print(Cross edge u to s)
	t++
	s.etime = t



// EASY SOLUTION //
checkAncensorts(G, s, u)
	p = s
	while (p != u && p != NULL)
		if p == u return true
		p = p.pred
	return false

EdgePrint(G)
	for v in G.V
		v.col = WHITE
		v.pred = NULL

	for v in G.V
		if v.col == WHITE
			DFS(v)

DFS(G, s)
	s.col = GRAY
	for u in s.adj
		if u.col == WHITE
			print("%d -> %d Tree Edge", s, u)
			u.pred = s
			DFS(G, u)

		if u.col == GRAY
			print("%d -> %d Back Edge", s, u)

		else if u.col == BLACK
			if checkAncestors(G, s, u)
				print("%d -> %d Forward Edge", s, u)
		else
			print("%d -> %d Cross Edge", s, u)
	s.col = BLACK

