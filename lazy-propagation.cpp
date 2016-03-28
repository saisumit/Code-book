/* Lazy-Propagation */ 
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
