/* Floyd - Warshall  Complexity O( V* V* V ) **/

// Case of Integer weights 

for( int i =  0 ; i <  n ; i ++ ) 
	d[i][i] =  0 ;

for (int k=0; k<n; ++k)
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			if (d[i][k] < INF && d[k][j] < INF)  // done to take care of negative edges else case like INF - 1 , INF  - 2 will arise ;
				d[i][j] = min (d[i][j], d[i][k] + d[k][j]); // k is an intermediate vertice i ---> k ----> j 
 

 // Case of Real  weights 


for (int k=0; k<n; ++k)
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			if (d[i][k] + d[k][j] < d[i][j] - EPS)
	                d[i][j] = d[i][k] + d[k][j];

 

 /**

 The case of negative cycles
If the graph has cycles of negative weight, then formally the algorithm of Floyd-Uorshella not apply to such a graph.

In fact, for those pairs of vertices iand jbetween which it is impossible to go into a negative weight cycle, the algorithm will work correctly.

For those pairs of the vertices, for which the answer does not exist (due to the presence of the negative cycle of the path between them), Floyd's algorithm to find an answer for a number of (possibly strongly negative, but not necessarily). Nevertheless, we can improve the algorithm of Floyd that he carefully cultivated such pair of vertices and drew for them, for example - \ Infty.

This can be done, for example, the next criterion is "not the existence of the way." Thus, even for a given graph has worked usual algorithm Floyd. Then, between the peaks iand jnot the shortest path exists if and only if there exists a vertex t, accessible from iand from which is attainable j, which is performed for d [t] [t] <0.

In addition, when using the Floyd algorithm for graphs with negative cycles should remember that arise during operation distance can go into much less exponentially with each phase. Therefore, action should be taken against integer overflow by limiting the distances from the bottom of any value (for example, - {\ Rm INF}).

For more information about this task, see the separate article:. "Finding a negative cycle in the graph" .

 **/



report writing topic ->  Quantum Computing 
