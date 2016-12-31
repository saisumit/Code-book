/*
Binary Lifting is a technique used to answer queries on the tree that is whenever we need  binary 
search on the tree , this can be used  for example if some value increases or decreases monotonically along the path of the tree 
this can be used for example the path length. 
This has been effectivly used for calculating the LCA and also used in the problem 
http://codeforces.com/contest/740/problem/D " Aloyna and tree "
*/

/*
 bfs for calculating the levels of the nodes so that it can be used in the preprocess function 
*/
  void  bfs ( )
   {

       queue<Int> q;
       while( !q.empty())q.pop();

       q.push( 0 ) ;
       L[0] = 0 ;
       dist[0] = 0  ;

      while ( !q.empty() )
       {

          Int v = q.front() ;
          q.pop() ;
          for( Int i = 0 ; i < g[v].size() ; i ++ )
          	     {
          	     	 Int ch =  g[v][i].ff ;
                  L[ch] = L[v] + 1  ;
                  dist[ch] = dist[v] + g[v][i].ss ;
                  q.push(ch);
          	     }


       }

     return ;

   }


/*
This step is performed to calculate parents at 2^i 
*/
 void PreProcess()
  {
      Int i, j;

     //we initialize every element in P with -1
      for (i = 0; i < N; i++)
          for (j = 0; 1 << j < N; j++)
              P[i][j] = -1e8;

     //the first ancestor of every node i is T[i]
      for (i = 0; i < N; i++)
          P[i][0] = T[i];

     //bottom up dynamic programing
      for (j = 1; 1 << j < N; j++)
         for (i = 0; i < N; i++)
             if (P[i][j - 1] != -1)
                 P[i][j] = P[P[i][j - 1]][j - 1];  // 2^(j-1) * 2^(j-1) = 2^j

  }




  Int query( Int v )
  {
     // cout<<v<<" " ;
      Int vertex = v ;
      Int Const = dist[v] - a[v] ; // number of p  for which this is less than dist[p]
      Int log ,i;
      // dist[p] >= Const

      for (log = 1; 1 << log <= L[v]; log++);  // gives us the upper boundary for appling the binary search just as hi in normal binary seach
                     log--;

    //  cout<<log<<" ";
      Int num = 0 ;
      for ( i = log ; i >= 0 ; i -- ) // meta binary search is used 
           if( dist[P[v][i]] >= Const && !( v == 0 && i >= 0) ) // any constraint is checked here if it is satisfied  we move up else we  move down 
              { v = P[v][i] ;
                num = num + (1<<i) ;
              }


     //  cout<<vertex<<" "<<v<<endl;
       cnt[T[vertex]] += 1;
       cnt[T[v]]  += -1 ;
       //cout<<num<<" ";
  }