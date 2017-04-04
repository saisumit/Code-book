
/** Code For Edmond Karp Flow Problem **/
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
#define INF INT_MAX
#define mp make_pair
using namespace  std ;
const int MAXN  = 5e3 + 50  ;
// vector<vector<pair<int,int> > > G ( MAXN ) ;  // This is used to store the Edges of the Graph and capacity of the edges .
Int  E[ MAXN ][ MAXN ] ;
Int  C[ MAXN ][ MAXN ] ;
Int  F[ MAXN ][ MAXN ] ;
Int  N , Edges ;


Int   Edmond_Karp(  Int  s , Int  t )
  {
     while( true )
       {
          bool Flg =  false ; // Flag to see if We have found A path to the destination.
          vector<Int >Parent( N , -1 ) ; // Storing parents used for backtracking.
          Parent[ s ] = s ; // Initialisation.
          vector<Int >M( N ) ; // Capacity of the path to the node
          M[s] = 1e15  ;   // Initialisation
          queue<Int >Q ;      // Queue to Run a BFS
          Q.push( s ) ;
          while( !Q.empty() )
            {
               Int  u = Q.front() ;
               Q.pop() ;
               for( Int  v = 0 ; v < N ; v ++ )
                 {
                    if( !E[u][v] )continue ;  // If this edge doesn't exists the continue.
                   // There is available capacity and the node is not seen before essential condition for sp via bfs.
                    if( C[u][v] - F[u][v]  > 0 and Parent[v] == -1 )
                      {
                         Parent[v] = u ;
                         M[ v ] = min( M[u] , C[u][v] - F[u][v] ) ; // C[u][v] - F[u][v] maximum Flow we can send through this Edge .
                         if( v!= t )Q.push(v) ; // If its not the destination , then push it into the queue.
                         else
                          {
                             while( Parent[v] != v )  // Backtrack and update the values.
                               {
                                  u = Parent[v] ;
                                  F[u][v] += M[t] ;
                                  F[v][u] -= M[t] ;
                                  v = u ;

                               }

                             Flg = true ; // Found the path therefore break
                             break ;

                          }

                      }


                 }
                if( Flg )break ; // Found the path therfore break

            }

          if( !Flg ) // Path Not Found Time to Exit.
            {
              Int  sum = 0 ;
              for( Int  i = 0 ; i < N ; i ++ )
                sum =  sum + F[s][i] ;

              return sum ;
            }
       }

  }
int  main ( )
 {
    scanf("%lld%lld",&N,&Edges) ;  // v is the number of vertices and e is number of edges .
    FOR( i , Edges )
      {
         Int  u , v ,c  ;
         scanf("%lld%lld%lld",&u,&v,&c) ;
         u-- ; v-- ;
       if( v!= u )
        { E[u][v]   = 1 ;  // IF graph is undirected. 
          E[v][u]  =  1 ;
          C[u][v]  += c ;
          C[v][u]  += c ;
        }
      }

     Int  s ,  t ;

     //scanf("%d%d",&s,&t) ;
     s = 0;
     t = N-1;
     cout<<Edmond_Karp( s, t ) ;


 }
