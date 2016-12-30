#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cctype>
#include <queue>
#include <complex>
#include <functional>
#include <sstream>
#include <tuple>

using namespace std;

vector<int> t;
vector<vector<int>> a;

int dfs(int v, int p)
{
	int result = 0;
	for (auto u : a[v])
		if (u != p)
			result = max(result, dfs(u, p));
	return result + 1;
}

/*
Note :  since each vertex is allowed to have only one oot-edge in orignal graph , therefore  there will be atmost one incoming edge to 
any node so a situation where in longest path orignating from a double cycle contains a double cycle will not arise 
   v8 <----( v1 <---> v2 )----> v3 ----> v4 -----> v5  -----> v6 <------>v7 
                                                            ( /\ this scene cannot occur )      

so all chains will indeed be disjoint by ( 1 ) will be disjoint 



*/
int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int tn;
    cin >> tn;
    for (int tc = 0; tc < tn; tc++)
    {
    	int n;
    	cin >> n;
    	a.clear();
    	a.resize(n);
    	t.clear();
    	t.resize(n);
    	for (int i = 0; i < n; i++)
    	{
    		int d;
    		cin >> d;
    		t[i] = d - 1; // shows that  i's BFF = (d - 1) ;   
     		a[d - 1].push_back(i);  // puttinf int the reverse edges 
    	}
    	vector<pair<int, int> > ps;
    	for (int i = 0; i < n; i++)
    		for (int j = i + 1; j < n; j++)
    			if (t[i] == j && t[j] == i) //  finding all the cycles of length 2 
    				ps.push_back(make_pair(i, j));

    	int result = 0;
    	for (auto p : ps)
    		result += dfs(p.first, p.second) + dfs(p.second, p.first); // --------------- ( 1 )


   // this code is for checking the longest cycle     
    	for (int i = 0; i < n; i++) // starting node of cycle 
    	{
    		int cur = i;
    		int rep = -1;
    		for (int j = 1; j <= n; j++)  // length of the cycle , can be atmost  1 ;
    		{
    			cur = t[cur];
    			if (cur == i)
    			{
    				rep = j;
    				break;
    			}
    		}
    		if (rep + 1)
    			result = max(result, rep);
    	}

    	cout << "Case #" << tc + 1 << ": " << result << endl;
    }
    return 0;
}