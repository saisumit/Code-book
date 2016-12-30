// Topological Sort

int n; // number of vertices
vector<int> g[MAXN]; 
bool used[MAXN];
vector<int> ans;
 
void dfs (int v) {  // basicall topological sort ==  reverse of dfs tree 
	used[v] = true;
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (!used[to])
			dfs (to);
	}
	ans.push_back (v);
}
 
void topological_sort() {
	for (int i=0; i<n; ++i)
		used[i] = false;
	ans.clear();
	for (int i=0; i<n; ++i)
		if (!used[i])
			dfs (i);
	reverse (ans.begin(), ans.end());
}