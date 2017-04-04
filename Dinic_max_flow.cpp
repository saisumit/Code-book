
/** Code For Dinic Maximum Flow Problem **/
#include <bits/stdc++.h>
#define Int long long
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )

#define PI 3.1415926535897932385
#define uint64 unsigned long long

#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define ff first
#define ss second
#define bit(n) (1<<(n))
#define Last(i) ( (i) & (-i) )
#define sq(x) ((x) * (x))
#define mp make_pair
using namespace  std ;

// vertex[a] is the adjacency list of A
// cap[a][b]  is the capacity from a to b
// flow[a][b]  is the occupied flow from a to b.
// level[a] is the level in level graph of a
// path[a] is the previous of a
const int  INF = INT_MAX - 10   ;
const int  MAXN = 5e3 + 50 ;
int  Level[MAXN] ;
vector<int> g[ MAXN ] ;
int  cap[MAXN][MAXN] ;
int  flow[MAXN][MAXN] ;
bool buildLevelGraph( int  source ,int  sink ) // Its a simple bfs used to build the Layer graph
  {
     queue<int>Q ;
     memset( Level  , 0 , sizeof ( Level ) ) ;
     Q.push( source ) ;
     Level[source] = 1 ;
     while( !Q.empty() )
      {
         int  now = Q.front() ;
         Q.pop();
         FOR( i , g[now].size() )
          {
             int  next =  g[now][i] ;
             if( cap[now][next] - flow[now][next] > 0 and Level[next] == 0 ) // *missed a statement Int entionally
               {
                  Q.push(next) ;
                  Level[next] = Level[now] + 1 ;
               }
          }
      }

      return (Level[sink]!= 0) ;
  }

int  constructBlockingFlow(  int  now ,  int  sink , int  FLOW )
  {
      if( !FLOW )return 0 ; // if there is no flow or flow == 0 return 0
      if( now == sink )return FLOW ; // if we reached the sink then return the saturation flow or maximum flow that can be augmented
      for( int i = 0 ; i < g[now].size() ; i ++ )
        {
           int  next = g[now][i] ;
           if( Level[next] != Level[now] + 1 )continue  ; // Working only on layer graph
           int  pushed = constructBlockingFlow( next , sink , min(FLOW , cap[now][next] - flow[now][next] ) ); // finding augmenting path and updating critical edge
           if( pushed ) // if we can push anything
             {
                 flow[now][next] += pushed  ; // update the flow
                 flow[next][now] -= pushed  ; // update the reverse edge
                 return pushed ;
             }
        }
      return 0 ;
  }

Int  Dinic( int  source , int  sink )
 {
    Int  Flow = 0 ;
    while( buildLevelGraph(source,sink) )
          Flow += constructBlockingFlow( source , sink , INF ) ;

    return Flow ;
 }

int main (  )
 {
    Int  N , M ;     // number of nodes and edges
    scanf("%d%d",&N,&M) ;
    FOR( i , M )
     {
        int  u ,  v ,c ;
        scanf("%d%d%d",&u,&v,&c)  ;
        if( u!= v )
          {
             g[u].pb(v) ;
             g[v].pb(u)  ;
             cap[u][v] += c ;
             cap[v][u] += c ;
          }

     }

     cout<<Dinic(1,N) ;
 }
