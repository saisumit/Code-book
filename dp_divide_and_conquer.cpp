/*                                           When Panda is Life !

                              _,add8ba,
                            ,d888888888b,
                           d8888888888888b                        _,ad8ba,_
                          d888888888888888)                     ,d888888888b,
                          I8888888888888888 _________          ,8888888888888b
                __________`Y88888888888888P"""""""""""baaa,__ ,888888888888888,
            ,adP"""""""""""9888888888P""^                 ^""Y8888888888888888I
         ,a8"^           ,d888P"888P^                           ^"Y8888888888P'
       ,a8^            ,d8888'                                     ^Y8888888P'
      a88'           ,d8888P'                                        I88P"^
    ,d88'           d88888P'                                          "b,
   ,d88'           d888888'                                            `b,
  ,d88'           d888888I                                              `b,
  d88I           ,8888888'            ___                                `b,
 ,888'           d8888888          ,d88888b,              ____            `b,
 d888           ,8888888I         d88888888b,           ,d8888b,           `b
,8888           I8888888I        d8888888888I          ,88888888b           8,
I8888           88888888b       d88888888888'          8888888888b          8I
d8886           888888888       Y888888888P'           Y8888888888,        ,8b
88888b          I88888888b      `Y8888888^             `Y888888888I        d88,
Y88888b         `888888888b,      `""""^                `Y8888888P'       d888I
`888888b         88888888888b,                           `Y8888P^        d88888
 Y888888b       ,8888888888888ba,_          _______        `""^        ,d888888
 I8888888b,    ,888888888888888888ba,_     d88888888b               ,ad8888888I
 `888888888b,  I8888888888888888888888b,    ^"Y888P"^      ____.,ad88888888888I
  88888888888b,`888888888888888888888888b,     ""      ad888888888888888888888'
  8888888888888698888888888888888888888888b_,ad88ba,_,d88888888888888888888888
  88888888888888888888888888888888888888888b,`"""^ d8888888888888888888888888I
  8888888888888888888888888888888888888888888baaad888888888888888888888888888'
  Y8888888888888888888888888888888888888888888888888888888888888888888888888P
  I888888888888888888888888888888888888888888888P^  ^Y8888888888888888888888'
  `Y88888888888888888P88888888888888888888888888'     ^88888888888888888888I
   `Y8888888888888888 `8888888888888888888888888       8888888888888888888P'
    `Y888888888888888  `888888888888888888888888,     ,888888888888888888P'
     `Y88888888888888b  `88888888888888888888888I     I888888888888888888'
       "Y8888888888888b  `8888888888888888888888I     I88888888888888888'
         "Y88888888888P   `888888888888888888888b     d8888888888888888'
            ^""""""""^     `Y88888888888888888888,    888888888888888P'
                             "8888888888888888888b,   Y888888888888P^
                              `Y888888888888888888b   `Y8888888P"^
                                "Y8888888888888888P     `""""^
                                  `"YY88888888888P'
                                       ^""""""""'



*/

#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )

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

#define mp make_pair
using namespace std ;
Int N , K  ;
const int  MAXN = 5e3 + 5 ;
Int dp[ MAXN ][ MAXN ] ;
pair<Int,Int> A[ MAXN ] ;
Int W[ MAXN ] ;
Int WX[ MAXN ] ;
const  Int INF = 1e15 ;
void  ComputeDP( int i, int jleft, int jright, int kleft, int kright)
 {  // Select the middle point
  int jmid = (jleft + jright) / 2;
  // # Compute the value of dp[i][jmid] by definition of DP
  dp[i][jmid] = INF;
  int bestk = -1;
  for( int k = kleft ; k < jmid ; k ++ )
    {
       if ( dp[i - 1][k] - WX[k] + W[k]*A[jmid].ff < dp[i][jmid] )
         {  dp[i][jmid] =  dp[i - 1][k] - WX[k] + W[k]*A[jmid].ff ;
            bestk = k ;
         }

    }
   dp[i][jmid] += WX[jmid]  - W[jmid]*A[jmid].ff ;


  if ( jleft <= jmid  )
    ComputeDP(i, jleft, jmid-1, kleft, bestk) ;
  if ( jleft  <= jright )
    ComputeDP(i, jmid+1 , jright, bestk, kright);

 }

int main()
{
   scanf("%lld%lld",&N,&K) ;
   FOR( i , N + 1 )FOR( j , K + 1  )dp[i][j] = 1e15 ;
   for( int i = N  ; i >= 1 ; i -- )
     {
        Int x , w ;
        scanf("%lld%lld",&x,&w) ;
        A[i].ff = x ;
        A[i].ss = w ;
     }
   for( int i = 1 ; i <= N ; i ++ )
     {  W[i] = W[i-1] + A[i].ss ;
        WX[i] = WX[i-1] + (A[i].ss)*(A[i].ff) ;
     }

    dp[ 0 ][ 0 ]  = 0 ;
    for( Int i = 1 ; i <= N ; i ++ )
       {  dp[1][i] = WX[i] - W[i]*A[i].ff   ;
         // cout<<i<<" "<<dp[i][1]<<endl ;
       }

    for( Int j = 2 ; j <= K ; j ++ )
         ComputeDP( j , 1 , N , 1 , N ) ;



       cout<<dp[K][N]<<endl;

}
