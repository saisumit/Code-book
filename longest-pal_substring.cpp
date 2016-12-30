// Counting the longest palindrome   subsequence 
#define MAXN 1000
int dp[ MAXN ][ MAXN ] ; 

for( int i = 1 ;  i < n  ; i ++ ) 
    dp[i][i] = 1  ;

for(  int  len  =  2 ; len <=  n ; len ++ ) // looping over the lengths 
{  
	 for( int i  = 0 ; i <= n-len ;  i++ )  // looping over the starting index  
	 	 {
              int j  = i + len - 1 ;
               
              if(  a[i] == a[j] && len == 2 )
              	    dp[i][j] = 2  ;
               
              else if(  a[i] == a[j] )
                 dp[i][j] =  dp[i+1][j-1] + 2 ; 

              else   dp[i][j] = max ( dp[ i +1 ][j] , dp[ i ][j-1]) ; 




	 	 }


}