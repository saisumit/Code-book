
int f[MAXN],g[MAXN],diameter;


void dfs(int v int pv ){
   
    int ma1 = -1 ; 
    int ma2 = -1 ; 
    
    for( int i = 0 ; i <  g[v].size() ; i ++ )
     {
        int ch =  g[v][i] ;
        if(  ch == pv )continue ; 
        dfs( ch , v ) ; 
        if(  f[ch] > ma1 ){  ma2 = ma1 ; ma1 = f[ch]; }
        else if(  f[ch] > ma2 ){  ma2 = f[ch] ; }
     } 
  
  
    f[v] = 1;

    if(ma1!=-1) f[v] += ma1 ;

    if(ma1!=-1 && ma2!=-1)
         g[v] = 1 + ma1 + ma2 ;

    diameter = max(diameter, max(f[v], g[v]));
}
