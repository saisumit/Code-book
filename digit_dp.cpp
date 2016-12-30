
#include<bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for (int i = a; i <= b; i++)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define Int long long
#define mp make_pair

Int na , nb ; // na number of digits in a and b 
Int dp[ 10 ][ 3 ][ 100 ] ; 

// dp[i][j][k] stores the sum 
// i - > length of the number formed 
// j - > "small" discussed later 
// k - >  required to store presum 

void  calc( Int a , Int b )
 {
    while( a ) {  a= a/10 ; na++  ; }
    while( b ) {  b= b/10 ; nb++  ; }

 }

Int compute ( Int presum  , Int digit  )
 {
    return presum + digit ;  // function to compute sub-result 

 }
int cnt = 0 ;
Int solve(  string& a , Int idx , Int limit , Int small , Int presum  )
{  
    // limit is the number of digits in number in decimal format 
    // idx ->  denotes that we are building the ith digit,  it can go from 0 ( Most Significant digit ) to limit - 1 ( Least significant digit )  
    // small is the constraint 
    // small = 0 indicates that we can take any value from 0 to 9 as we have taken a smaller digit below 
    // small = 1 indicates that we can only take value from 0 to a[idx] 
    // small = 2 indicates that we cannot form a n digit smaller than right limit so we are going to make only numbers that have less than n digits

   if(  idx   == limit-1 && small == 2 ) // since if small == 2 we have to stop at n - 1 can't go forward
              return 0 ;

   if(  idx   >=  limit  ) // base condition if idx > number of digits 
        return 0 ;

   if(  dp[idx][small][presum] != -1 )return dp[idx][small][presum] ; 
   // memo table to store the result of computations so that if we encounter a same state again we can just return this 


   Int loop = 9  ; // setting the upper limit of loop to 9 
   Int num = a[idx] - '0' ; // digit at ith index

   Int sum = 0 ;

   Int i = 0 ; // start of loop 
   if(  idx == 0 )i = 1 ; // first digit of number cannot be zero 
   
   // just checking the conditions in the loop 

   for( ; i <=  loop ; i ++ )
     {
      if( small == 0 ) { sum =  sum +  compute( presum ,  i )  +  solve(  a , idx + 1 , limit , 0 , presum + i ) ; }
      if( small == 2 ) { sum =  sum +  compute( presum ,  i ) + solve(  a , idx + 1 , limit , 2 , presum + i ) ; }
      if( small == 1 ) { if(  i > num && idx != limit-1 ) sum =  sum +  compute( presum ,  i )  + solve(  a , idx + 1 , limit , 2 , presum + i ) ;
                         if(  i < num  ) sum =  sum +  compute( presum ,  i )  + solve(  a , idx + 1 , limit , 0 , presum + i ) ;
                         if(  i == num ) sum =  sum +  compute( presum ,  i )  + solve(  a , idx + 1 , limit , 1 , presum + i ) ;
                        }

     }

   dp[ idx ][ small ][presum] =  sum ; // storing the value in table 
   return dp[ idx ][ small ][presum] ;

}


int main ( )
{

 

        na = nb = 0  ;
        Int a , b ;
        cin >>  a >> b ;
        if(  a == -1 && b == -1 ) break  ;
        calc( a - 1, b );

       string bs =  to_string( b ) ;
       string as =  to_string( a -1 ) ;
       Int g ,s ;

        memset(dp,-1,sizeof(dp)) ;
        g = solve( bs , 0 , nb ,1, 0  )  ;

       memset(dp,-1,sizeof(dp)) ;
        s = solve (  as  , 0, na,1 , 0  );

        cout<<g-s<<endl;


}
