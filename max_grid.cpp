
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
#define MAXN 100005 
#define UL   pair<int,int>  
#define LR   pair<int,int> 

vector<vector<pair< int,int > > > X(MAXN) ; 
vector<vector<pair< int,int > > > Y(MAXN) ;   
set<pair<LR,UR> > visit ; 


int main ( ) 
{
   ios::sync_with_studio(0);
   cin.tie(0); 

   int N , L ; 
   cin >> N >> L  ; 

   
   FOR( i , N )
    {
      int x , y ,  c ; 
      cin >> x >> y >>  c ; 
      X[x].pb(mp(y,c)) ;  
      Y[y].pb(mp(x,c)) ; 
    }

   FOR(i,N + 1 ) 
    {
        sort( X[i].begin() , X[i].end() ) ; 
        sort( Y[i].begin() , Y[i].end() ) ; 

        for( int j = 1 ; j < X[i].size()  ; j ++ )
         X[i][j].ss = X[i][j-1].ss + X[i][j].ss ; 

        for(  int j = 1 ; j < Y[i].size() ; j ++ )
          Y[i][j].ss = Y[i][j-1].ss + Y[i][j].ss ; 
    }
      

}   