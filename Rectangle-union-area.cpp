/** Union Of rectangle Area */ 

struct Edge {
    bool open;
    int x, yMin, yMax;
    Edge(int x, int y1, int y2, bool op) {
        this->x = x;
        yMin = y1, yMax = y2;
        open = op;
    }
    bool operator < (const Edge &e) const {
        return (x < e.x);
    }
};


int n, m, h[maxN << 1];
int sum[maxN << 5], counter[maxN << 5];
vector<Edge> edges;



void print ( )
{   int maxsize=ceil(log2(num));
     maxsize=2*pow(2,maxsize)-1;

   for(int i= 1 ; i<=maxsize ; i++ )
          cout<<sum[i]<<" ";
    
    cout<<endl;

}

void update(int p, int l, int r, int yMin, int yMax, bool open) {

  if (h[r] < yMin || yMax < h[l]) return;

  // if ymin is greater than h[r] which is array of sorted y coordinates or
  // ymax is less than h[l] then l - r is not the required range

 /*

suppose our figure is like this ::

          _(2,5)
        _|_|_ (3,4)
(0,3)  |_|_|_|
  (1,2) _|_|_ (3,2)
(0,1)  |_|_|_|

  Three rectangles are there
    1) 0,1 -> 3,2
    2) 0,3 -> 3,4
    3) 1,2 -> 2,5

  h   -> [ 1 , 2 , 3,  4, 5 ]
edges -> [ (0,1,2) (0,3,4) (1,2,5) (2,2,5) (3,1,2) (3,3,4) ]



       Segment Tree using updation


            (1,5)                        0         1          2          4          2         1         0
     (1,3)        (3,5)                 0 0       1 0        1 1        2 2        1 1       0 1       0 0
  (1,2) (2,3)  (3,4) (4,5)            0 0 0 0   1 0 0 0    1 0 1 0    1 1 1 0    1 0 1 0   0 0 1 0   0 0 0 0






Question is what is actually done over here ?

   1 ) Firstly we sorted the edges according to the x coordinate and h[] according to y coordinates.

   2 ) then we started moving horizontal using a vertical sweep line to encounter 2  types of events : Left Edge,  Right Edge

     i) Left Edge: on encountering a left edge, we move it into the active sets and update the total length
                   of vertical sweep line that is cut by the rectangualar boxes , this is done by update function
                   here we have two variable ymin (lower left y coordinate), ymax (upper left y coordinate) .
                   using which we update the total length of sweep line intersected at that event, and after updating
                   sum[1] gives the length of intersected sweep line at that x coordinate.

     ii) Right Edge : On encountering a right edge, we again update the segment tree.

   3) Function of segment tree is to store the intesected length at various x positions namely the events, whenever
      we reach an edge we update the intersected length  , whenever we are at left edge we know that we have added an edge between
      ymin and ymax therefore we need to add this to the sum at this position, if we are at right edge we know that we need to remove
      an edge between ymin and ymax, we do so by reducing counter ,if counter is still not zero means there were overlapping rectss
      and we sum[p] = h[r]- h[l] .

     NOTE : at any time there will be only two types of rectangles in active sets we need to worry abt
        ____                      __
       |____|        OR          |__|
           _____               __|__|__
          |_____|             |__|__|__|

  (One below or abv otr)     (overlapping once)

 */


    int c = p << 1, mid = (l + r) >> 1;

    if (yMin <= h[l] && h[r] <= yMax) {         // ymin --- h[l] --- h[r] --- ymax
        counter[p] += open ? 1 : -1;
        if (counter[p]) sum[p] = h[r] - h[l];  //if there is a rectangle at that posn that is bw h[l] and h[r] we will add that to length
        else sum[p] = sum[c] + sum[c + 1];    // else we will just sumup of lengths above and beloew this region
        return;
    }

    if (l + 1 >= r) return;

    update(c, l, mid, yMin, yMax, open);
    update(c + 1, mid, r, yMin, yMax, open);

    if (counter[p]) sum[p] = h[r] - h[l];
    else sum[p] = sum[c] + sum[c + 1];



}

int64 solve() {
                                // process height for horzntl. sweep line
    sort(h + 1, h + m + 1);    //  Sorting the hieght according to the y coordinates
    int k = 1;

    FOR (i, 2, m) if (h[i] != h[k])  //  Deleting the same horizontal sweeplines
       h[++k] = h[i];                //     as they are redundant
           m = k;
         num  = m;


    for (int i = 0, lm = maxN << 4; i < lm; i++) // This is the initialization step of segment tree
        sum[i] = 0, counter[i] = 0;



    int64 area = 0LL;  //  Initializing the Area

    sort(all(edges));  // Sorting according to x coordinates for ver. swp line

    update(1, 1, m, edges[0].yMin, edges[0].yMax, edges[0].open);
   // print();

    for (int i = 1; i < edges.size(); i++) {
        area += sum[1] * (int64)(edges[i].x - edges[i - 1].x);
        update(1, 1, m, edges[i].yMin, edges[i].yMax, edges[i].open);
      //  print();
            }
    return area;



}

int main() {
      int n;
      cin>>n;
      int  x1, y1, x2, y2;

        edges.clear();
        m = 0;
        FOR (i, 1, n) {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);


            if(x1==x2 && y1>y2)swap(y1,y2);
            else if(y1==y2   && x1>x2)swap(x1,x2);

            x2+=1;    // x1 and y1 are bottom left coordinates
            y2+=1;    // x2 and y2 are top right coordinates


            edges.pb(Edge(x1, y1, y2, true));   // Inserting the Left edge
            edges.pb(Edge(x2, y1, y2, false));  // Inserting the Right Edge

            /*

            (x1,y2)     (x2,y2)
                _________
               |         |
   LeftEdge <- |         |-> Right Edge
               |_________|

            (x1,y1)     (x2,y1)

            */


            h[++m] = y1; // Inserting the Lower y Coordinate 1 based inddexiing
            h[++m] = y2; // Inserting the Upper y Coordinate

        }
        printf("%lld\n", solve());

    return 0;
}