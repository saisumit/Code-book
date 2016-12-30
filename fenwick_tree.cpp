// Fenwick tree and its uses 

// 1 Point update and range queries 


/*
   Memory Complexity = O(N) ; 
   Time Complexity : Update O(log(N))  Query  O( 2*log(N) )  
   indexing is 1 based Remember that 

   Concept : Every tree idx stores the sum from idx to ( idx - 2^r + 1 )  where r is the position of first  1 Lsb Ex 10001 --> r = 0 ; 1010 ---> r = 1
*/

int tree[ MAXN ] ; // size of BIT O(n)  

int read(  int idx ) 
 {
    int sum = 0 ; 
    while(  idx )
    	 {
    	 	sum =  sum +  tree[idx] ;  
            idx -= (idx & -idx) ; 
              
    	 }
    
     return sum ;

 }

 void update(  int idx , int val ) 
  {
     while(  idx <= N )
     	 {
            tree[idx] += val  ;  
            idx += ( idx & -idx ) ; 
     	 } 
      return  ;  
  }


int query( int L , int R ) 
 { 
    return read( R ) - read(L-1)  ;
 }



/*************************************************************************************************************************************************/
   
// 2 Range update and point Queries 
/*
  Note: 1 ) Remember all the values in the tree be initalised as zero. That is there would be no initial  tree building like above case  . 
        2)  Ans would be equal = Read( idx ) 
        3)  What we are doing here is storing  sum from ( idx to (idx-2^r+ 1 ) 
            in the tree idx therefore when we get update which is in this range its sum gets updated 
        4)  And answer is equal to query(idx) which will add all updates made till now    
        5)  Read and update remains same and ans  = arr[idx] + query(idx)
*/
int tree [ MAXN ] ; 

int read(  int i ) 
 {
    int sum = 0 ; 
    while(  idx )
    	 {
    	 	sum =  sum +  tree[idx] ;  
            idx -= (idx & -idx) ; 
              
    	 }
    
     return sum ;

 }

 void update(  int idx , int val ) 
  {
     while(  idx <= N )
     	 {
            tree[idx] += val  ;  
            idx += ( idx & -idx ) ; 
     	 } 
      return  ;  
  }

// Range update: Adds v to each element in [i...j] in the array
void range_update(int i, int j, int v)	{
	update(i, v);
	update(j + 1, -v);
}


int query( int idx ) 
  {
     return read(idx)  ;

  }




/*************************************************************************************************************************************************/

// Range update and range query 

/*

Suppose you had an empty array:

0  0  0  0  0  0  0  0  0  0  (array)
0  0  0  0  0  0  0  0  0  0  (cumulative sums)
And you wanted to make a range update of +5 to [3..7]:

0  0  0  5  5  5  5  5  0  0  (array)
0  0  0  5 10 15 20 25 25 25  (desired cumulative sums)
How could you store the desired cumulative sums using 2 binary indexed trees?

The trick is to use two binary indexed trees, BIT1 and BIT2, where the cumulative sum is calculated from their contents. In this example, here's what we'd store in the the two trees:

0   0   0   5   5   5   5   5   0   0  (BIT1)
0   0   0  10  10  10  10  10 -25 -25  (BIT2)
To find sum[i], you compute this:

sum[i] = BIT1[i] * i - BIT2[i]
For example:

sum[2] = 0*2 - 0 = 0
sum[3] = 5*3 - 10 = 5
sum[4] = 5*4 - 10 = 10
...
sum[7] = 5*7 - 10 = 25
sum[8] = 0*8 - (-25) = 25
sum[9] = 0*9 - (-25) = 25
To achieve the desired BIT1 and BIT2 values for the previous range update, we do 3 range updates:

We need to do a range update of +5 to indices 3..7 for BIT1.
We need to do a range update of +10 to indices 3..7 for BIT2.
We need to do a range update of -25 to indices 8..9 for BIT2.
Now let's do one more transformation. Instead of storing the values shown above for BIT1 and BIT2, we actually store their cumulative sums. This lets us do the 3 range updates above by making 4 updates to the cumulative sums:

BIT1sum[3] += 5
BIT1sum[8] -= 5
BIT2sum[3] += 10
BIT2sum[8] -= 35
In general, the algorithm to add a value v to a range[i..j] would be:

BIT1sum[i]   += v
BIT1sum[j+1] -= v
BIT2sum[i]   += v * (i-1)
BIT2sum[j+1] -= v * j
where the += and -= syntax simply means to update the BIT cumulative sum data structure with a positive or negative value at that index. Note that when you update the BIT cumulative sum at an index, it implicitly affects all indices to the right of that index. For example:

0 0 0 0 0 0 0 0 0 0 (original)

BITsum[3] += 5

0 0 0 5 5 5 5 5 5 5 (after updating [3])

BITsum[8] -= 5

0 0 0 5 5 5 5 5 0 0 (after updating [8])
Fenwick trees store sums in a binary tree. It is easy to do the updates shown above to a Fenwick tree, in O(logn)O(log⁡n) time.
*/

  #include <cstdio>
#include <cstring>
#define LSOne(S) (S & (-S))
using namespace std;

typedef long long ll;

// B1 and B2 are two fenwick trees
// Original array entries are assumed to be 0
// and only updates are stored.
ll B1[100005], B2[100005];

// Array size
int N;

// Point query
// Returns value at position b in the array for ft = B1
// Returns value to be subtracted from query(B1, b) * b for ft = B2
ll query(ll* ft, int b)	{
	ll sum = 0;
	for (; b; b -= LSOne(b)) sum += ft[b];
	return sum;
}

// Range query: Returns the sum of all elements in [1...b]
ll query(int b) {
    return query(B1, b) * b - query(B2, b);
}

// Range query: Returns the sum of all elements in [i...j]
ll range_query(int i, int j)    {
    return query(j) - query(i - 1);
}

// Point update: Adds v to the value at position k in the array
// ft is the fenwick tree which represents that array
void update(ll* ft, int k, ll v) {
	for (; k <= N; k += LSOne(k)) ft[k] += v;
}

// Range update: Adds v to each element in [i...j]
void range_update(int i, int j, ll v)	{
	update(B1, i, v);
	update(B1, j + 1, -v);
	update(B2, i, v * (i - 1));
	update(B2, j + 1, -v * j);
}

int main()  {
	int T, C, p, q, cmd;
	ll v;

	scanf("%d", &T);
	while (T--)	{
		// C -> No. of operations
		scanf("%d %d", &N, &C);
		memset(B1, 0, (N+1) * sizeof(ll));
		memset(B2, 0, (N+1) * sizeof(ll));
		while (C--)	{
			scanf("%d %d %d", &cmd, &p, &q);
			// cmd is 0 for a range update and 1 for a range query
			if (cmd == 0)   {
                		scanf("%lld", &v);
                		range_update(p, q, v);
			} else
                		printf("%lld\n", range_query(p, q));
		}
	}

    return 0;
}