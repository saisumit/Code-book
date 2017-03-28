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
#define INF INT_MAX
#define mp make_pair
using namespace std ;
Int N  ;
const int MAXN = 50005 ;
bool ir[ MAXN ] ;
vector<pair<Int,Int> >rect ;
Int  dp[ MAXN ] ;
struct cht{
    struct Line{
     Int a;
     long long b;
     long long val;
     double xLeft;
     bool type;
     Line(long long _a = 0 , long long _b = 0){ // Line is stored in the form of y =  m*x + c
      a = _a; // Slope
      b = _b;  // y intercept
      xLeft = -1e18;  // first x for which it assumes the minimum value
      type = 0;  // Start or end_point
      val = 0;
     }
     long long valueAt(Int x) const{
      return 1LL * a * x + b;
     }
     friend bool areParallel(const Line &l1, const Line &l2){
      return l1.a == l2.a;
     }
     friend double intersectX(const Line &l1 , const Line &l2){
      return areParallel(l1 , l2) ? 1e18 : 1.0 * (l2.b - l1.b) / (l1.a - l2.a);
     }
     bool operator < (const Line &l2) const{
      if(!l2.type)
       return a < l2.a; // sorted according to the slope , Less Slope comes first
      return xLeft > l2.val;
     }
    };
    set < Line >  hull;
    bool hasPrev(set < Line > :: iterator it){
     return it != hull.begin();
    }
    bool hasNext(set < Line > :: iterator it){
     return it != hull.end() && next(it) != hull.end();
    }
    bool irrelevant(const Line &l1 , const Line &l2 , const Line &l3){
     return intersectX(l1,l3) <= intersectX(l1,l2);
    }
    bool irrelevant(set < Line > :: iterator it){
     return hasPrev(it) && hasNext(it) && (irrelevant(*next(it) , *it , *prev(it)));
    }
    set < Line > :: iterator updateLeftBorder(set < Line > :: iterator it){
     if(!hasNext(it)){
      return it;
     }
     double val = intersectX(*it , *next(it)); // Calculation of intersection point
     Line buf(*it); // Create a new line with same values as it
     it = hull.erase(it); // Erase the Old Line
     buf.xLeft = val; // Update its x value
     it = hull.insert(it, buf); // Insert it into the set
 
     return it;
 
    }
    void addLine(Int a , long long b){
     Line l3 = Line(a, b); // Constructing the line
     auto it = hull.lower_bound(l3); // Finding the appropriate position according to slope of the line
     if(it != hull.end() && areParallel(*it , l3)){ // if this line is parallel to *it
      if(it -> b > b){ // if new line intercept is less than old line intercept then erase the old line ( Case 1 - > refer Notebook )
       it = hull.erase(it);
      }
      else{
       return;
      }
     }
     it = hull.insert(it, l3); // Insert the new line
     if(irrelevant(it)){    // Case 2 - > refer notebook
      hull.erase(it);  // Erase this Line and return
      return;
     }
     while(hasPrev(it) && irrelevant(prev(it))){ // Case 3
      hull.erase(prev(it)); // Erase the previous line
     }
     while(hasNext(it) && irrelevant(next(it))){ // Case 4
      hull.erase(next(it));
     }
     it = updateLeftBorder(it); // Update the intersection Point
     if(hasPrev(it)){
      updateLeftBorder(prev(it)); // Update the intersection Point with the previous
     }
   //  if(hasNext(it)){
   //   updateLeftBorder(next(it));
   //  }
    }
    long long getBest(Int x){
     Line q;
     q.val = x;
     q.type = 1;
     auto bestLine = hull.lower_bound(q);
     if(bestLine == hull.end()){
      return 1e18;
     }
     return bestLine -> valueAt(x);
    }
} dch;
 
int main()
{
 
    scanf("%lld",&N)  ;
    vector<pair<Int,Int> >A( N ) ;
    FOR( i , N )scanf("%lld%lld",&A[i].ff,&A[i].ss ) ;
    sort( A.begin() , A.end() )  ;
    FOR( i , MAXN )dp[i] = 1e18 ;
    pair<Int,Int> prev = A[ N - 1 ] ;
 
    for( Int i = N - 2 ; i >= 0 ; i -- ) // Height is decreasing and Width is increasing
      {
         if( prev.ss >= A[i].ss )
              ir[ i ] = true  ;
         else
              prev = A[i] ;
 
      }
 
    for( int i = 0 ; i  < N ; i ++ )
      if(!ir[i])rect.pb( A[i] )  ;
 
     N =  rect.size( ) ;
 
   dp[0] = rect[0].ff*rect[0].ss ;
 
   for( Int  i = 0 ; i < N ; i ++  ) // Calculating dp[i] , minimum cost to group till ith rect
    {
       if( i != 0 )    dp[i] = dch.getBest(rect[i].ff) ;
       dp[i] = min( dp[i] , rect[i].ff*rect[0].ss) ;
       if( i != N - 1 )dch.addLine(rect[i+1].ss,dp[i] );
 
    }
 
   /* for( int j = i - 1 ;  j >= 0 ; j -- )
      {
            dp[i] = min( dp[i] , dp[j] + rect[i].ff*rect[j+1].ss ) ;
 
      }
    */
    cout<<dp[N-1]<<endl ;
 
}
 
