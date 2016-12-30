// Prims Minimum Spanning Tree


O( v*v )

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


O ( Elogv )
 
 int n;
vector < vector < pair<int,int> > > g;
const int INF = 1000000000; 

vector<int> min_e (n, INF), sel_e (n, -1);
min_e[0] = 0;
set < pair<int,int> > q;

q.insert (make_pair (0, 0));  // Inserting the root node with make_pair( distance ,  vertex ) ; 
for (int i=0; i<n; ++i) {
	if (q.empty()) {
		cout << "No MST!";
		exit(0);
	}
	int v = q.begin()->second; // this is the with minimum edege vertex 
	q.erase (q.begin()); // erasing the first vertex 
 
	if (sel_e[v] != -1) 
		cout << v << " " << sel_e[v] << endl;
 
	for (size_t j=0; j<g[v].size(); ++j) {
		int to = g[v][j].first, // find all the neighbouring edges of the given vertex 
			cost = g[v][j].second; // find the edge weight 
		if (cost < min_e[to]) { // if the weight is less than the minimum weight stored 
			q.erase (make_pair (min_e[to], to));  // erase the old weight and vertex 
			min_e[to] = cost; // change the minimum weight 
			sel_e[to] = v;  // change the source vertex
			q.insert (make_pair (min_e[to], to)); // insert it into the set 
		}
	}
}