// Strongly Connected Components  SPOJ- CAPCITY

// Note - A scc graph is acyclic  

vector < vector<int> > g, gr;
vector<char> used;
vector<int> order, component;
 
void dfs1 (int v) {  // running a topological sort to get the order 
	used[v] = true;
	for (size_t i=0; i<g[v].size(); ++i)
		if (!used[ g[v][i] ])
			dfs1 (g[v][i]);
	order.push_back (v);
}
 
void dfs2 (int v) {  
	used[v] = true;
	component.push_back (v); // same component 
	for (size_t i=0; i<gr[v].size(); ++i)
		if (!used[ gr[v][i] ])
			dfs2 (gr[v][i]);
}
 
int main() {
	int n;

	for (;;) {
		int a, b;

		g[a].push_back (b);
		gr[b].push_back (a);
	}
 
	used.assign (n, false);
	for (int i=0; i<n; ++i)
		if (!used[i])
			dfs1 (i);

	used.assign (n, false);

	for (int i=0; i<n; ++i) {
		int v = order[n-1-i];
		if (!used[v]) {
			dfs2 (v);
	     	component.clear(); // clearing the components 
		}
	}
}