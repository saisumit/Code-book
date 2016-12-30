
#include<bit/stdc++.h>
/*
 Euler_path : A path that travels each each edge exactly one time and starting and endpoint are not same 
 Conditions : all nodes should be even-degree except two nodes which can be odd-degree ( starting and ending node  ) ; 

 Euler_circuit : A path that travels each edge exactly once and starting and end point are same ( cycle  ) . 
 Conditions : All nodes should be even-degree . 


 This whole  Algorithm is implemented from http://www.graph-magics.com/articles/euler.php 

 Algorithm for undirected graphs:

Start with an empty stack and an empty circuit (eulerian path).
- If all vertices have even degree - choose any of them.
- If there are exactly 2 vertices having an odd degree - choose one of them.
- Otherwise no euler circuit or path exists.
If current vertex has no neighbors - add it to circuit, remove the last vertex from the stack and set it as the current one. Otherwise (in case it has neighbors) - add the vertex to the stack, take any of its neighbors, remove the edge between selected neighbor and that vertex, and set that neighbor as the current vertex.
Repeat step 2 until the current vertex has no more neighbors and the stack is empty.



*/

// N = number of vertices 

int cnt[ N ] ; // cnt[v] = i means that ith edges needs to be consider if we reach this vertex  if its equal to size of g[v].size means no 
                  // neighbour left therefore add this to the circuit 

bool mark[ N*N ] // Marks the edges if they have been already travelled or not 

vector<vector<pair<int,int> > > g( N ) // G[u] = mp( v , i ) that is there is an edge between u to v having index i ( Edge index used for marking ). 


void Euler_path(int u, int par){
    vis[u] = 1;
    while(cnt[u] < (int)g[u].size()){
        cnt[u]++;
        if (mark[g[u][cnt[u]-1].S]) continue;
        else mark[g[u][cnt[u]-1].S] = 1, Euler_path(g[u][cnt[u]-1].F, u);
    }
    ans.pb(u); // stores euler path in reverse order 
}
