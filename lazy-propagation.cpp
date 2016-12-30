/* Lazy-Propagation */ 

/* 
  Few points to get your lazy correct everytime 
  1) Don't change the positon of the push it has been correctly placed. It may look that changing the position of push in update may correct your solution
     but it doesn't happen that way 

  2) Remember R[x] stores the update for the children and not for the node,  if we are within the range that is ( ll <= l && r <= rr ) then 
     i)  Perform Immidiate update on the current node
     ii) accumulate the update for the children in R[x]  
 
  3) In the push function updates on the children of the node are made based on values stored in R[x] and not ( R[2*x+1] or R[2*x+2])  
     but R[x+x+1] and R[x+x+2] have to be changed according to question to accumulate updates 

  4) I have added an image of lazy tree if it work for this case then it works for all case 
       3 Updates
                  i)  ( 4 - 13 )
                  ii) ( 0 - 14 )
                  ii) ( 1 - 7  )
     https://drive.google.com/open?id=0B_PEq7-Njt2AYzY4Y09SOGZST1U'

  5) In the push function always reset R[x] = 0 ;
     
           
*/ 
long long a[4 * N];  // normal segment tree 
bool put[4 * N];     // Lazy tree 


inline void push(int x) {  
  if (put[x]) {   // if lazy is turned on , then pass lazy to children , set its value and make its lazy false and return 
    a[x + x] = a[x + x + 1] = a[x];
    put[x + x] = put[x + x + 1] = true;
    put[x] = false;
  }
}

inline void gather(int x) {
  a[x] = a[x + x] + a[x + x + 1];  // this can be any thing like summing up children or anything else 
}

void build(int x, int l, int r) {
  if (l < r) {
    int y = (l + r) >> 1;
    build(x + x, l, y);
    build(x + x + 1, y + 1, r);
    a[x] = a[x + x] | a[x + x + 1];
    put[x] = false;  // initializing lazy tree 
  } else {
    a[x] = val // putting values in the leaf node , and setting their lazy to be true
    put[x] = true;  
  }
}

void update(int x, int l, int r, int ll, int rr, long long v) {

  if (r < ll || rr < l) {  // checking for range , not going out of bounds , nothing specia over here 
    return;
  }
  if (ll <= l && r <= rr) {
    a[x] = v;              //  if the current range is completely within the range in which update needs to be done then  
    put[x] = true;         // we set that node to its value and make its lazy true and return 
    return;
  }
  push(x);                // else if the range is not completely within the given range  , then we first remove its lazy and then 
  int y = (l + r) >> 1;   // go forward till we reach  we reach a condition which satisfies complete enclosure
  update(x + x, l, y, ll, rr, v);   // modyfying children 
  update(x + x + 1, y + 1, r, ll, rr, v);
  gather(x);               //  setting the value of the node 
}



long long query(int x, int l, int r, int ll, int rr) {  // This function is generally same as our update function 
  if (r < ll || rr < l) {
    return 0;
  }
  if (ll <= l && r <= rr) {
    return a[x];
  }
  push(x);
  int y = (l + r) >> 1;
   query(x + x, l, y, ll, rr);
   query(x + x + 1, y + 1, r, ll, rr);
   gather(x);
  return a[x];
}


/********************************************************************************************************************************************************/


vector< vector<Int> > a( 4*N ) ;
bool put[4 * N];     // Lazy tree
Int  R[ 4*N ] ;
vector<Int>Nu(26,0) ;
int rot  ;

inline void push(int x) {
  if (put[x]) {   // if lazy is turned on , then pass lazy to children , set its value and make its lazy false and return

    Int tp[26]  ;

    FOR( i , 26 )tp[i] = 0 ;
    FOR( i , 26 )tp[(i+R[x])%26] = a[x + x + 1][ i ] ;
    FOR( i , 26 )a[ x + x + 1][i] = tp[i] ;

    FOR( i , 26 )tp[i] = 0 ;
    FOR( i , 26 )tp[(i+R[x])%26] = a[x + x + 2][ i ] ;
    FOR( i , 26 )a[ x + x + 2][i] = tp[i] ;

    put[x + x + 1 ] = put[x + x + 2] = true ;
    R[ x + x +  1 ] = R[x + x + 1] + R[x]  ;
    R [x  + x + 2] =  R[x + x + 2] + R[x]  ;
    R[x] = 0 ;
    put[x] = false;

  }
}

inline void gather(int x) {
  FOR(i,26)
    {  a[x][i] = 0 ;
       a[x][i] = a[x + x + 1][i] + a[x + x + 2][i];
    }
}

inline void change( int x)
 {

    Int tp[26] = {0} ;
    FOR( i , 26 )tp[(i+rot)%26] = a[x][ i ] ;
    FOR( i , 26 )a[x][i] = tp[i] ;

 }
void build(int x, int l, int r) {
  if (l < r) {
    int y = (l + r) >> 1;
    build(x + x + 1, l, y);
    build(x + x + 2, y + 1, r);
    gather(x) ;
    put[x] = false;  // initializing lazy tree
  } else {
    a[x][ s[l] - 'a'] = 1 ;  // putting values in the leaf node , and setting their lazy to be true
    put[x] = true;
  }
}

void update( int x, int l, int r, int ll, int rr  ) {

  if (r < ll || rr < l) {  // checking for range , not going out of bounds , nothing specia over here
    return;
  }

  if (ll <= l && r <= rr) {


    change(x) ;

   // cout<<x << " " << R[x]<<endl;
   // FOR( i , 26 )cout<<a[x][i]<<" ";
   // cout<<endl;                 //  if the current range is completely within the range in which update needs to be done then
    R[x] += rot ;
    put[x] = true;// we set that node to its value and make its lazy true and return
    return;
  }
  push(x);                // else if the range is not completely within the given range  , then we first remove its lazy and then
  int y = (l + r) >> 1;   // go forward till we reach  we reach a condition which satisfies complete enclosure
  update(x + x + 1, l, y, ll, rr);   // modyfying children
  update(x + x + 2, y + 1, r, ll, rr);
  gather(x);               //  setting the value of the node
}


vector<Int> query(int x, int l, int r, int ll, int rr) {  // This function is generally same as our update function

  if (r < ll || rr < l) {
    return Nu ;
  }
  if (ll <= l && r <= rr) {
    return a[x];
  }
  push(x);
  int y = (l + r) >> 1;


   vector<Int> A = query(x + x + 1 , l, y, ll, rr);
   vector<Int> B = query(x + x + 2 , y + 1, r, ll, rr);

   gather(x);

   FOR( i , 26 )A[i] = A[i]  + B[i] ;
   return A ;
}

