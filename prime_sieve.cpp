
/* Sieve - Prime- Numbers  */ 


bool sieve [MAXN];
long long  lg[ MAXN];
 
void func( )
 {
   memset( sieve , true , sizeof(sieve));
   sieve[0] =  false;
   sieve[1] =  false;
 
   for( int i = 2 ; i*i <= MAXN ; i++ )
      {
        if( sieve[i] ==  true )
           for( int j = 2 ; i*j <= MAXN ; j ++ )
             { sieve[i*j] = false; }
 
 
      }
 }