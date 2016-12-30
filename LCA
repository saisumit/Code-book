
 #include <bits/stdc++.h>
using namespace std;
 /*
  Mistakes -
   0) Dont rush to conclusion on seeing a question , keep yourself relaxed and go easy on ques .
   1) To see at each step if integer is not causing an error , best way is to use long long always.
   2) To see if my solution can be verified , if yes then do that .
   3) To see if my code can be simplified , if yes make it simple.
   4) If my code is wrong , dont be in a hurry to change to the code, first think for 2 min if any modification can be done to make it
      right.
   5) always typecast (int) arr.size() because   size_t does not support subtraction.
   6) Never use such expression   Int ct = max( ct ,left) ; (declartion should be done before assignment , absurd behaviour)
   7) Using long long for everything may cause Time Limit Exceeded some times , so better be sure
   8) appending at the end of the string takes too much time 339 Div2 - B
   9) n*n*log(n) doesnt wrk for n >1000 on codeforces
   10) read the question carefully and before submitting soln read ques , it will hardly take 1min and save u  time cost of 15-30 min
   11) Keep calm and Code.

 */
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define Int long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define ff first
#define ss second
#define bit(n) (1<<(n))
#define Last(i) ( (i) & (-i) )
#define sq(x) ((x) * (x))
#define INF INT_MAX
#define mp make_pair
#define MAXN 1000
#define LOGMAX 20

int T[MAXN];
int P[MAXN][ LOGMAX ] ;
int L[MAXN] ;
int N ;
vector<vector<int> >g(0) ;

// T stores the immidiate parent of T[i]  ;
// P  is a dp table where P[i][j]  =  2^j th parent of P[i]
/*

Overall Working - >

This takes O(N logN) time and space. Now let’s see how we can make queries.
Let L[i] be the level of node i in the tree. We must observe that if p and q are on the same level in the tree we can compute LCA(p, q)
using a meta-binary search. So, for every power j of 2 (between log(L[p]) and 0, in descending order),
if P[p][j] != P[q][j] then we know that LCA(p, q) is on a higher level and we will continue searching for LCA(p = P[p][j], q = P[q][j]).
At the end, both p and q will have the same father,
so return T[p]. Let’s see what happens if L[p] != L[q].
Assume, without loss of generality, that L[p] < L[q]. We can use the same meta-binary search  for finding the ancestor of p situated
on the same level with q, and then we can compute the LCA  as described below. Here is how the query function should look:


*/


 void PreProcess()
  {
      int i, j;

  //we initialize every element in P with -1
      for (i = 0; i < N; i++)
          for (j = 0; 1 << j < N; j++)
              P[i][j] = -1;

  //the first ancestor of every node i is T[i]
      for (i = 0; i < N; i++)
          P[i][0] = T[i];

  //bottom up dynamic programing
      for (j = 1; 1 << j < N; j++)
         for (i = 0; i < N; i++)
             if (P[i][j - 1] != -1)
                 P[i][j] = P[P[i][j - 1]][j - 1];  // 2^(j-1) * 2^(j-1) = 2^j

  }

  void  bfs ( )
   {

       queue<int> q;
       while( !q.empty())q.pop();

       q.push( 0 ) ;
       L[0] = 0 ;

      while ( !q.empty() )
       {

          int v = q.front() ;
          q.pop() ;
         // cout<< "V" << v << endl;
          for( int i = 0 ; i < g[v].size() ; i ++ )
          	     {
          	     	 int ch =  g[v][i] ;
                     L[ch] = L[v] + 1  ;
                     //cout<< "Ch" << ch << endl;
                     q.push(ch);
          	     }


       }

     return ;

   }



  int query(int p, int q)
  {
      int tmp, log, i;

  //if p is situated on a higher level than q then we swap them
      if (L[p] < L[q])
          swap( p , q ) ;

  //we compute the value of [log(L[p)]
      for (log = 1; 1 << log <= L[p]; log++);
      log--;

  //we find the ancestor of node p situated on the same level
  //with q using the values in P
      for (i = log; i >= 0; i--)
          if (L[p] - (1 << i) >= L[q])
              p = P[p][i];

      if (p == q)
          return p;

  //we compute LCA(p, q) using the values in P
      for (i = log; i >= 0; i--)
          if (P[p][i] != -1 && P[p][i] != P[q][i])
              p = P[p][i], q = P[q][i];

      return T[p];
  }

  int main ( )
   {
      T[0] = 0 ;
      T[1]= 0 ;
      T[2]= 0 ;
      T[3] = 0 ;
      T[4]= 2 ;
      T[5]= 2 ;
      T[6] = 2 ;
      T[7]= 5 ;
      T[8] = 5 ;
      T[9]=6;
      T[10] = 6 ;
      T[11]=9;
      T[12]=9 ;

       N = 13 ;

     g.resize(N);

     for( int i = 1 ; i <  N ; i ++ )
       {
          cout<<T[i]<<" "<< i <<endl;
          g[ T[i] ].push_back( i ) ;

       }


       bfs(  ) ;

       PreProcess();
       cout<< query ( 7 , 8 ) << endl ;

   }

