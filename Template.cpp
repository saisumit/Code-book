#include <bits/stdc++.h>
using namespace std; 

// This is the code for the order statistic tree  

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
/*
    template<
    typename Key, // Key type
    typename Mapped, // Mapped-policy
    typename Cmp_Fn = std::less<Key>, // Key comparison functor
    typename Tag = rb_tree_tag, // Specifies which underlying data structure to use
    template<
    typename Const_Node_Iterator,
    typename Node_Iterator,
    typename Cmp_Fn_,
    typename Allocator_>
    class Node_Update = null_node_update, // A policy for updating node invariants
    typename Allocator = std::allocator<char> > // An allocator type
    class Tree;

*/
typedef tree<
pair<int,int> ,
null_type,
less<pair<int,int> >,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

http://codeforces.com/blog/entry/11080


 /* 
  Mistakes -
   0) Dont rush to conclusion on seeing a question , keep yourself relaxed and go easy on ques .
   1) To see at each step if integer is not causing an error , best way is to use long long always. 
   2) To see if my solution can be verified , if yes then do that .
   3) To see if my code can be simplified , if yes make it simple.
   4) If my code is wrong , dont be in a hurry to change to the code, first think for 2 min if any modification can be done to make it 
      right. 
   5) always typecast (int) arr.size() because   size_t does not support subtraction. 
   6) Never use such expression   Int ct = max( ct ,left) ; (declartion should be done before assignment , absurd behaviour)
   7) Using long long for everything may cause Time Limit Exceeded some times , so better be sure 
   8) appending at the end of the string takes too much time 339 Div2 - B 
   9) n*n*log(n) doesnt wrk for n >1000 on codeforces 
   10) read the question carefully and before submitting soln read ques , it will hardly take 1min and save u  time cost of 15-30 min
   11) Keep calm and Code.
   
 */

/*

 
*/ 
http://stackoverflow.com/questions/7244321/how-do-i-update-a-github-forked-repository

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


Bit operations
// Setting a bit 
    number  |= 1<< x ; 

// Clearing a bit 
    number &= ~(1<<x) ;

// Toggling a bit 
    number ^= (1<<x) ;        

// Checking a bit 
    bit = ( number  >> x )&1 ; 

// changing n th bit to either 1 to 0  depending on value of x 
    number ^= (-x ^ number) & ( 1 << n ) ;         



/*
inline int inp()
{
    int noRead=0;
    char p= getchar_unlocked();
    for(;p<33;)
    {
     p=getchar_unlocked();
    };
    while(p>32)
    {
     noRead = (noRead << 3) + (noRead << 1) + (p - '0');
     p=getchar_unlocked();
    }
    return noRead;
};

*/

/*http://codeforces.com/problemset/problem/628/D
struct Point
{
    int x, y;
};

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) *1LL* (r.x - q.x) -
              (q.x - p.x) *1LL* (r.y - q.y);

    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}*/


/*

Binary Search 

while ( lo <= hi )
     { mid = lo + (hi-lo)/2;
       if ( mid*mid == target )
          return mid ;
      else if ( mid*mid < target )
         lo = mid+1 ;
      else
         hi = mid-1 ;
      }

*/

/*
int64 exp( int64 base, int64 pow)
 {
    int64 ans = 1 ;
    while( pow )
     {
        if(pow & 1)
          ans*=base;

           base*=base;
           pow >>=1 ;

     }


    return ans;

 }*/




bool isPowerof4(unsigned int n) {
    return ( n !=0U && (n & 0xAAAAAAAAU) == 0 && (n&(n-1)) == 0);
}

/*
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
*/ 


 /*
struct dim {  char c ;
               Int freq ;

         bool operator==(const dim &b) const {
        return (c == b.c) && (freq == b.freq);}

        bool operator<=(const dim &b) const {
        return (c == b.c) && (freq <= b.freq);}

        bool operator!=(const dim &b) const {
        return (c != b.c) || (freq != b.freq);}

            };

 */



/*
int gcd(int a,int b)
{
    if(b>a) return gcd(b,a);
    else if(b!=0) return (b,a%b);
    else return a;
}
*/



/* 


   lower bound  -  > returns the first value which is not less than the required value ]
                     if there is no element less than  the given value than it returns the .end() ; 

      // 10 10 10 20 20 20 30 30

    for eg:   lower_bound(  v.begin() , v.end() , 20 ) ; -> it returns the fourth element of the list (  first 20 ) ; 


    upper bount  - > returns the first element which is greater than the given number 

     // 10 10 10 20 20 20 30 30 

     for eg :  upper_bound(  v.begin() , v.end(( ) , 20 )
     it returns the first 30 in the list that it is 7  element because it is the first element which is greater than 20 
     not found pe return is v.end()


  
*/




/*
  Moving in 2 - D grid 
  
  int delta_i[8]={-1, -1, -1, 0, 1, 1, 1, 0};
  int delta_j[8]={1, 0, -1, -1, -1, 0, 1, 1};


*/ 

int main()
{
/*
  freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

  int t ;
  cin >> t ;
  for( int p = 1 ; p <= t ; p ++ )
   {


        cout<<"Case #"<<p<<": ";
   }
 */  

}

https://www.facebook.com/TheTimeliners/videos/1076283069134502/

inline void seg_fault(void)
{
    volatile int *p = reinterpret_cast<volatile int*>(0);
    *p = 0x1337D00D;
}


/*
using namespace std;
 
const int N = 1e5 + 5;
char s[N], dir[] = "UDLR";
 
int main()
{
    srand(time(0));
    
    int n = 1e5;
    for(int i = 0; i < n; ++i)
        s[i] = dir[rand() % 4];
    
    cout << s << endl;
    
    return 0;
}
 


*/

/*



      while( true )
        {
         char arr[] = {'L','D','R','U'} ;
         srand(time(0));

         for( int i = 0 ; i < ans.length() ; i ++ )
            fin[i] = ans[i] ;

          for( int i = ans.length()  ; i < MAXN - 1  ; i ++ )
                     fin[i] = arr[rand()%4] ;

         //verify(  ans );
          fin[ MAXN -1 ] = '\0' ;


          if(verify())break;
          }

            printf("%s",fin) ;

*/



/** Popcount implementation O(1)  Interview purpose

Warren has a whole chapter about counting bits, including one about Conting 1-bits.

The problem can be solved in a divide and conquer manner, i.e. summing 32bits is solved as summing up 2 16bit numbers and so on. This means we just add the number of ones in two n bit Fields together into one 2n field.

Example:
10110010
01|10|00|01
0011|0001
00000100
The code for this looks something like this:

x = (x & 0x55555555) + ((x >> 1) & 0x55555555);
x = (x & 0x33333333) + ((x >> 2`) & 0x33333333);
x = (x & 0x0f0f0f0f) + ((x >> 4) & 0x0f0f0f0f);
x = (x & 0x00ff00ff) + ((x >> 8) & 0x00ff00ff);
x = (x & 0x0000ffff) + ((x >> 16) & 0x0000ffff);
We're using ((x >> 1) & 0x55555555) rather than (x & 0xAAAAAAAA) >> 1 only because we want to avoid generating two large constants in a register. If you look at it, you can see that the last and is quite useless and other ands can be omitted as well if there's no danger that the sum will carry over. So if we simplify the code, we end up with this:

int pop(unsigned x) {
   x = x - ((x >> 1) & 0x55555555);
   x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
   x = (x + (x >> 4)) & 0x0f0f0f0f;
   x = x + (x >> 8);
   x = x + (x >> 16);
   return x & 0x0000003f;
}
That'd be 21 instructions, branch free on a usual RISC machine. Depending on how many bits are set on average it may be faster or slower than the kerrigan loop - though probably also depends on the used CPU.

*/

/*

calculating Longest Non - decreasing subsequence 

vector <int> calc_lis(vector <int> a) {
    int n = a.size();
    vector <int> res(n), dp(n + 1, 500);
    dp[0] = -1;
    for (int i = 0; i < n; ++i) {
            res[i] = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
            dp[ res[i] ] = a[i];
    }
    return res;
}


calculating Longest Increasing subsequence

int n, num;
    
    vector<int> v;
    cin >> n;
   
   while (n--){
         cin >> num;
         if (v.size() == 0 || num > v.back())
         v.push_back(num);
         else *lower_bound(v.begin(), v.end(), num) = num;
              }

   cout << v.size();

*/

  IsPowerOfTwo(ulong x)
{
    return (x != 0) && ((x & (x - 1)) == 0);
}

freopen("a.in", "r", stdin);
     freopen("a.out", "w", stdout);
     int t ;
     scanf("%d",&t) ;
     while(  t -- )
      {
         FOR( i , MAXN )FOR( j , MAXN )FOR( k , 2 )FOR( l , 2 )FOR( m , 2 )FOR( n ,2 )dp[i][j][k][l][m][n] = -1 ;
         int r , c ;
         scanf("%d%d",&r,&c) ;
         vector<int> A( 4 , 0 ) ; 
         rec( 0 ,  A ) ;  
            


      }
int dp[ MAXN ][ MAXN ][ 2 ][ 2 ][ 2 ][ 2 ] ;


int r , c ;

/**
  * //0 
  * // 1 
**
23   
**/
rec(  int idx , vector<int> A ) 
 {
    if( A[1] == 0 && A[0] == 0 ) 
      { 
         vector<int> B = A ; 
         
      }
 }

// Inorder 

 class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> vector;
        stack<TreeNode *> stack;
        TreeNode *pCurrent = root;

        while(!stack.empty() || pCurrent)
        {
            if(pCurrent)
            {
                stack.push(pCurrent);
                pCurrent = pCurrent->left;
            }
            else
            {
                TreeNode *pNode = stack.top();
                vector.push_back(pNode->val);
                stack.pop();
                pCurrent = pNode->right;
            }
        }
        return vector;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> vector;
        if(!root)
        return vector;
        stack<TreeNode *> stack;
        stack.push(root);
        while(!stack.empty())
        {
            TreeNode *pNode = stack.top();
            if(pNode->left)
            {
                stack.push(pNode->left);
                pNode->left = NULL;
            }
            else
            {
                vector.push_back(pNode->val);
                stack.pop();
                if(pNode->right)
                stack.push(pNode->right);
            }
        }
        return vector;
    }
};



// Preorder 
vector<int> Solution::preorderTraversal(TreeNode* A) {
  
  
    stack<TreeNode*>stck ; 
    stck.push(A);
    vector<int> ans(0) ; 
    
    while(!stck.empty())
     { 
        TreeNode* tp = stck.top() ; 
         if(  tp == NULL )
           { stck.pop() ;  continue ; } 
           
        
           ans.push_back( tp->val );  
           stck.pop();    
           
         if( tp -> right )stck.push( tp->right ) ;        
         if( tp -> left )stck.push( tp->left );
        
            
        
         
         
     }
    
    return ans ;
}
  

http://codeforces.com/contest/653
