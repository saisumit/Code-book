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
#define VI  vector<int>
#define mp make_pair
using namespace std ;
const int  N = 1e5 + 50 ;
const int  M = 1e5 + 50 ;

VI tree[N]; // The bridge edge tree formed from the given graph
VI graph[N];int U[M],V[M];  //edge list representation of the graph.
bool isbridge[M]; // if i'th edge is a bridge edge or not
int visited[N];int arr[N],T; //supporting arrays
int cmpno = 0 ;
queue<int> Q[N];
int f[N],g[N],diameter;


int dfs(int v ,int pv ){

    int ma1 = -1 ;
    int ma2 = -1 ;

    for( int i = 0 ; i <  tree[v].size() ; i ++ )
     {
        int ch =  tree[v][i] ;
        if(  ch == pv )continue ;
        dfs( ch , v ) ;
        if(  f[ch] > ma1 ){  ma2 = ma1 ; ma1 = f[ch]; }
        else if(  f[ch] > ma2 ){  ma2 = f[ch] ; }
     }


    f[v] = 1;

    if(ma1!=-1) f[v] += ma1 ;

    if(ma1!=-1 && ma2!=-1)
         g[v] = 1 + ma1 + ma2 ;

    diameter = max(diameter, max(f[v], g[v]));
    return diameter;
}
int adj(int u,int e){
    return U[e]==u?V[e]:U[e];
}
int dfs0(int u,int edge)    //marks all the bridges
{
    visited[u]=1;
    arr[u]=T++;
    int dbe = arr[u];
    for(int i=0;i<(int)graph[u].size();i++)
    {
        int e = graph[u][i];
        int w = adj(u,e);
        if(!visited[w])
            dbe = min(dbe,dfs0(w,e));
        else if(e!=edge)
            dbe = min(dbe,arr[w]);
    }
    if(dbe == arr[u] && edge!=-1)
        isbridge[edge]=true;
    return dbe;
}

void dfs1(int v) //Builds the tree with each edge a bridge from original graph
{
    int currcmp = cmpno;    // current component no.
    Q[currcmp].push(v);    // A different queue for each component, coz   during bfs we shall go to another component (step of dfs) and then come   back to this one and continue our bfs
    visited[v]=1;
    while(!Q[currcmp].empty())    //bfs. Exploring all nodes of this  component
    {
        int u = Q[currcmp].front();
        Q[currcmp].pop();
        for(int i=0;i<(int)graph[u].size();i++)
        {
            int e = graph[u][i];
            int w = adj(u,e);
            if(visited[w])continue;
            //if the edge under consideration is bridge and
            //other side is not yet explored, go there (step of dfs)
            if(isbridge[e])
            {
                cmpno++;
                tree[currcmp].push_back(cmpno);
                tree[cmpno].push_back(currcmp);
                dfs1(w);
            }
            else     //else continue with our bfs
            {
                Q[currcmp].push(w);
                visited[w]=1;
            }
        }
    }
}
int main (  )
 {
    int n , m ;
    scanf("%d%d",&n,&m) ;
    FOR( i , m )
      {
         int u , v ;
         scanf("%d%d",&u,&v) ;
         graph[u].pb( i ) ;
         graph[v].pb( i ) ;
         U[i] = v  ;
         V[i] = u  ;
      }

   dfs0( 1 , -1 ) ;
   memset(visited,0,sizeof(visited));
   dfs1(1) ;
   cout<<cmpno-dfs(0,-1)+1<<endl;

 }
