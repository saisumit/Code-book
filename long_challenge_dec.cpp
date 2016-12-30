#include <bits/stdc++.h>
using namespace std;

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

int main ( )
 {
    int t ;
    scanf("%d",&t) ;
    while( t-- )
       {
          Int N, K  ;
          scanf("%lld%lld",&N,&K) ; // number of flower and number of bankquets
          vector<Int>a( N ) ;
          FOR( i , N )scanf("%lld",&a[i]) ;

          sort(a.begin() ,  a.end()) ;
          set< pair<Int,Int> > s,rs ;
          set< pair<Int,Int> >::iterator qt ;
          set< pair<Int,Int> >::reverse_iterator it ;



          Int ctr = 1 ;
          for( int i = 1 ; i < N ; i ++ )
             {
                 if( a[i] != a[i-1] && ctr%K != 0 ){ s.insert( mp(ctr%K , a[i-1]) ) ; ctr = 1 ;  }
                 else ctr ++ ;

             }

          if( ctr%K != 0 ) {  s.insert( mp(ctr%K , a[N-1]) ); }
          int presum = 0 ;

          rs = s ;

          it =  rs.rbegin() ;
          Int ans = 0;


          while(  it!= rs.rend() )
             {
                 pair<Int,Int> tp = *(it) ;
                 Int freq = tp.ff ;
                 Int num  = tp.ss ;
               //  cout<<freq<<" " <<num <<endl;
                 Int req  = K - freq ;
                 qt =  s.begin() ;
                 while( req > 0 &&  qt != s.end() )
                  {
                       if(  qt->ss  > num )
                      req -= min( req ,qt->ff ) ;

                       qt++;

                  }

                  if(  req == 0 )
                   {
                      s.erase( mp(freq,num) ) ;
                      ans+= K  - freq ;
                      qt =  s.begin() ;
                      req = K - freq  ;
                      while( qt != s.end() && req > 0 )
                       {
                           if( (qt->ss) > num )
                             {
                                Int tp = min(req , qt->ff) ;
                                req -= tp ;
                                Int f = qt->ff ;
                               // cout<<f<<" "<<qt->ss<<endl;
                                s.erase( mp( f,qt->ss ) ) ;
                                f   -= tp ;
                                if(  f > 0 )s.insert(mp(f,qt->ss)) ;
                             }
                             qt++;
                       }



                   }

                   it++;





             }

             cout<<ans<<endl ;



       }








 }
