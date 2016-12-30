// Connected - Components  

/************* Using Disjoint Sets ***********************/
void make_set (int v) {
	parent[v] = v;
	rank[v] = 0;
}
 
int find_set (int v) {
	if (v == parent[v])
		return v;
	return parent[v] = find_set (parent[v]);
}
 
void union_sets (int a, int b) {
	a = find_set (a);
	b = find_set (b);
	if (a != b) {
		if (rank[a] < rank[b])
			swap (a, b);
		parent[b] = a;
		if (rank[a] == rank[b])
			++rank[a];
	}
}


/*************** Using Dfs ****************/
int n;
vector<int> g[MAXN];
bool used[MAXN];
vector<int> comp;
 
void dfs (int v) {
	used[v] = true;
	comp.push_back (v);
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (! used[to])
			dfs (to);
	}
}
 
void find_comps() {
	for (int i=0; i<n; ++i)
		used[i] = false;
	for (int i=0; i<n; ++i)
		if (! used[i]) {
			comp.clear();
			dfs (i);
 
			cout << "Component:";
			for (size_t j=0; j<comp.size(); ++j)
				cout << ' ' << comp[j];
			cout << endl;
		}
}