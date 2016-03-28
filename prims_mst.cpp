// Prims Minimum Spanning Tree

int n;
vector < vector<int> > g; // graph to store edges 
const int INF = 1000000000; 
 

vector<bool> used (n);   //  visited or not 
vector<int> min_e (n, INF), sel_e (n, -1);
min_e[0] = 0;  //setting the distance of the origin  
for (int i=0; i<n; ++i) {  // running through all the vertices 
	int v = -1;   // initially next vertex to be included in the mst to be -1
	for (int j=0; j<n; ++j)  // finding the minimum of all vertices 
		if (!used[j] && (v == -1 || min_e[j] < min_e[v]))  
			v = j; 
	if (min_e[v] == INF) {   // we cant find a vertex 
		cout << "No MST!";
		exit(0);
	}
 
	used[v] = true;
	if (sel_e[v] != -1)            
		cout << v << " " << sel_e[v] << endl;
 
	for (int to=0; to<n; ++to)  // now changing the distances of all the adjacent vertices of the vertex which we included in the mst
		if (g[v][to] < min_e[to]) {
			min_e[to] = g[v][to];
			sel_e[to] = v;
		}
}