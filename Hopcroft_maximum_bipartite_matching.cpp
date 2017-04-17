                                                      /** IMPLEMENTING HOPCROFT ALGORTIHM **/

#include <bits/stdc++.h>
#define FOR( i , n ) for( int i = 0 ; i < n ; i ++ )
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
using namespace std  ;

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
const int MAXN = 1e5 ;
int N , M  ; // N = Number of Nodes on the Left side and M = Number of Edges in the bipartite graph
vector<int> g [ MAXN ] ; // Declaration of our bipartite graph
int Distance[ MAXN ] ; // This will store the Length of augmenting path we have made till this node
int matched[ MAXN ] ; // matched[u] = v , if there is an edge between u and v in final matched graph.
const int INF = 1e9 ;

bool bfs( )
 {
    /**
       Construction of Layered graph with alternating matched and unmatched edges using bfs.
    **/
    queue<int> q ;
    for( int i = 1 ; i <= N ; i ++ )  // Looping through all Left Side vertices
        if( matched[i] == 0 ) // If this vertex is not matched then insert it into queue to make layered graph
          {  q.push(i) ;
             Distance[i] = 0 ;
          }
        else Distance[i] = INF ; // it is matched we dont have to consider it now

     Distance[0] = INF ; // This is the dummy vertex created to check existence of a augmenting path if this remains INF  after bfs then it would mean that there are
                   // no more augmenting paths and we need to stop now
     while( !q.empty() )
      {
          int Left = q.front( ); // unmatched vertex
          q.pop() ;
          for( int Right : g[Left] )  // Looking for all right side vertices
            {
               if( Distance[ matched[Right] ] == INF ) // This means that the edge between ch and matched[ch]  is a matched edge and hence fulfils our condition of alterating vertices
                 {
                      Distance[ matched[Right] ] = Distance[Left] + 1 ; // We made  it an unmatched edge and pushed into the queue
                      q.push( matched[Right] ) ;
                 }

            }

      }

     return ( Distance[ 0  ] != INF )  ; // if Distance is not equal to infinity then we have find an augmenting path and it will increasing matching by atleast one.

 }

/* Construction of new matching using dfs */
bool dfs(  int Left )
 {
    if( Left == 0 )return true ;

    for( int Right : g[Left] )
      {
         if(  Distance[matched[Right]] == Distance[Left] + 1  )
               if( dfs( matched[Right] ) )
                 {
                    matched[Left] = Right ;
                    matched[Right] = Left ;
                    return true ;
                 }

      }

      Distance[ Left ] = INF ;
      return false ;

 }

void Hopcroft( )
 {
     int matching = 0 ;

     while( bfs( ) )
      {
         for(  int i = 1 ; i <= N ; i ++ )
              if( matched[i] == 0 and dfs(  i ) ) // updating the matched and unmatched vertices
                       matching++ ;  // Since every augmenting path increases matching by 1
      }

      cout<<matching<<endl;

 }
int main( )
 {
    int B ;
    scanf("%d%d%d",&N,&B,&M) ;
    FOR( i , M )
      {
          int u , v ;
          scanf("%d%d",&u,&v) ;
          v =  v + N  ;
          g[u].pb( v ) ;
          g[v].pb( u ) ;

      }

    Hopcroft( ) ;



 }
