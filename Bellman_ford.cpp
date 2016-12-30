// Bellman - Ford 

void solve() {
	
	vector<int> d (n, INF);
	d[v] = 0; // It can be any source vertex
	vector<int> p (n, -1); // parents 
	int x;
	for (int i=0; i<n; ++i) {  // looping for all vertices 
		x = -1;
		for (int j=0; j<m; ++j) // looping al edges 
			if (d[e[j].a] < INF) // done for handling negative wieghts
				if (d[e[j].b] > d[e[j].a] + e[j].cost) {   // Relaxation condition
					d[e[j].b] = max (-INF, d[e[j].a] + e[j].cost);
					p[e[j].b] = e[j].a;
					x = e[j].b;
				}
	}

 
	if (x == -1)
		cout << "No negative cycle from " << v;
	else {
		int y = x;
		for (int i=0; i<n; ++i)
			y = p[y];
 
		vector<int> path;
		for (int cur=y; ; cur=p[cur]) {
			path.push_back (cur);
			if (cur == y && path.size() > 1)  break;
		}
		reverse (path.begin(), path.end());
 
		cout << "Negative cycle: ";
		for (size_t i=0; i<path.size(); ++i)
			cout << path[i] << ' ';
	}
	
}


