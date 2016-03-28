
/* Segment - Tree - Normal */ 

int n, t[4*MAXN];


void build (int a[], int v, int tl, int tr) {
	if (tl == tr)
		t[v] = a[tl];
	else {
		int tm = (tl + tr) / 2;
		build (a, v*2, tl, tm);
		build (a, v*2+1, tm+1, tr);
		t[v] = t[v*2] + t[v*2+1];
	}
}


void update (int v, int tl, int tr, int pos, int new_val) {
	if (tl == tr)
		t[v] = new_val;
	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update (v*2, tl, tm, pos, new_val);
		else
			update (v*2+1, tm+1, tr, pos, new_val);
		t[v] = t[v*2] + t[v*2+1];
	}
}


int sum (int v, int tl, int tr, int l, int r) {
	if (l > r)
		return 0;
	if (l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	return sum (v*2, tl, tm, l, min(r,tm))
		+ sum (v*2+1, tm+1, tr, max(l,tm+1), r);
}



/*******************************************************************************************************************************/


/* 2nd Example - calculating maximum subsequence in given range  **/


 struct data {
	int sum, pref, suff, ans;
};
 
data combine (data l, data r) {
	data res;
	res.sum = l.sum + r.sum;
	res.pref = max (l.pref, l.sum + r.pref);
	res.suff = max (r.suff, r.sum + l.suff);
	res.ans = max (max (l.ans, r.ans), l.suff + r.pref);
	return res;
}


data make_data (int val) {
	data res;
	res.sum = val;
	res.pref = res.suff = res.ans = max (0, val);
	return res;
}
 
void build (int a[], int v, int tl, int tr) {
	if (tl == tr)
		t[v] = make_data (a[tl]);
	else {
		int tm = (tl + tr) / 2;
		build (a, v*2, tl, tm);
		build (a, v*2+1, tm+1, tr);
		t[v] = combine (t[v*2], t[v*2+1]);
	}
}
 
void update (int v, int tl, int tr, int pos, int new_val) {
	if (tl == tr)
		t[v] = make_data (new_val);
	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update (v*2, tl, tm, pos, new_val);
		else
			update (v*2+1, tm+1, tr, pos, new_val);
		t[v] = combine (t[v*2], t[v*2+1]);
	}
}

data query (int v, int tl, int tr, int l, int r) {
	if (l == tl && tr == r)
		return t[v];
	int tm = (tl + tr) / 2;
	if (r <= tm)
		return query (v*2, tl, tm, l, r);
	if (l > tm)
		return query (v*2+1, tm+1, tr, l, r);
	return combine (
		query (v*2, tl, tm, l, tm),
		query (v*2+1, tm+1, tr, tm+1, r)
	);


/*******************************************************************************************************************************/

// 3rd type  - Saving the entire subarray segments at each vertex of the tree

	/* a)  Find the smallest integer greater than or equal to the specified in the specified interval. No modification request
           It requires responding to the following: (L, r, x)that means finding the minimum number in the interval a [l,r]that 
           is greater than or equal to x.  */ 

vector<int> t[4*MAXN];
 
void build (int a[], int v, int tl, int tr) {
	if (tl == tr)
		t[v] = vector<int> (1, a[tl]);
	else {
		int tm = (tl + tr) / 2;
		build (a, v*2, tl, tm);
		build (a, v*2+1, tm+1, tr);
		merge (t[v*2].begin(), t[v*2].end(), t[v*2+1].begin(), t[v*2+1].end(),
			back_inserter (t[v]));
	}
}
        


int query (int v, int tl, int tr, int l, int r, int x) {
	if (l > r)
		return INF;
	if (l == tl && tr == r) {
		vector<int>::iterator pos = lower_bound (t[v].begin(), t[v].end(), x);
		if (pos != t[v].end())
			return *pos;
		return INF;
	}
	int tm = (tl + tr) / 2;
	return min (
		query (v*2, tl, tm, l, min(r,tm), x),
		query (v*2+1, tm+1, tr, max(l,tm+1), r, x)
	);
}        




// when modification is allowed we will use a set instead of array 

void update (int v, int tl, int tr, int pos, int new_val) {
	t[v].erase (t[v].find (a[pos]));
	t[v].insert (new_val);
	if (tl != tr) {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update (v*2, tl, tm, pos, new_val);
		else
			update (v*2+1, tm+1, tr, pos, new_val);
	}
	else
		a[pos] = new_val;
}