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
const Int MAXN = 1e5  ;
bool seive[ MAXN + 40 ] ;
vector<Int>prime ;

void  pre( )
 {
    seive[ 0 ] = true ;
    seive[ 1 ] = true ;
    for( Int i = 2 ; i <= MAXN ; i ++ )
      if(!seive[i] )
         for( Int j = 2 ; i*j <= MAXN ; j ++  )
              seive[i*j] = true ;

    for( Int i = 1 ; i <= MAXN ; i ++ )
      if( !seive[i] )prime.pb(i) ;

 }

pair<Int, pair<Int, Int> > extendedEuclid(Int a, Int b) {

    Int x = 1, y = 0;
    Int xLast = 0, yLast = 1;
    Int q, r, m, n;
    while(a != 0) {
        q = b / a;
        r = b % a;
        m = xLast - q * x;
        n = yLast - q * y;
        xLast = x, yLast = y;
        x = m, y = n;
        b = a, a = r;
    }
    return make_pair(b, make_pair(xLast, yLast));
}

Int modInverse(Int a, Int m) {
    return (extendedEuclid(a,m).second.first + m) % m;
}

 Int exp( Int b , Int p , Int M )
   {
      Int ans = 1 ;
      while( p )
       {
         if( p & 1 )ans =( ans * b )%M ;
         b = (b*b)%M  ;
         p = p/2 ;
       }

     return ans ;

   }

 vector<Int> Encrypt( string message , Int e, Int  n )
   {
     vector<Int>cypher_text( message.length() ) ;
     for( int i = 0 ; i < message.length() ; i ++ )
         cypher_text[i] = exp( message[i] - 'A'  ,  e , n ) ;
      return cypher_text ;

   }

void  Decrypt( vector<Int> key , Int d ,Int n )
  {
     cout<<"Decrypting the message " <<endl ;
     for( int i = 0 ; i < key.size() ; i ++ )
       {
           cout<< (char)( exp( key[i] , d , n ) + 'A' )  ;
       }
  }
 int main ( )
  {
     pre(  ) ;
     int num = prime.size() ;
     Int fp = prime[ rand( )%num ]  ;  // first random prime
     Int sp = prime[ rand( )%num ] ;  // Second random prime
     Int n = fp*sp ;
     Int phi_n =  (fp-1)*(sp-1) ; // calculating the product of euler totient function

     Int e =  -1 ;  // Selecting the value of public key e , it should be less than pih_n and coprime to phi_n ;
     for( int i = 0 ; i < num ; i ++ )
       if( prime[i] < phi_n and __gcd(prime[i],phi_n) == 1 ) {  e = prime[i] ; break ; }

     Int d = -1 ; // decryption key as private key de = 1 mod( phi_n ) ;
     d =  modInverse( e , phi_n ) ;


    /*
       Private : fp , sp, phi_n , d  // This is used to decrypt the message
       Public :  e, n // This is used to encrypt the message
    */
    string message ;
    cout<<"Enter the message to be encrypted"<<endl ;
    cin >> message ;
    vector<Int> key = Encrypt( message , e , n  ) ;
    Decrypt( key , d , n );
  }
