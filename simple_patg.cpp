
// looking for a value using ternary search   


int ternary_search(int l,int r, int x)
{   
   int l =  0 ; 
   int r = n - 1 ; 

   while(r>=l)
    {
        int mid1 = l + (r-l)/3;
        int mid2 = r -  (r-l)/3;

        if(  A[ mid1 ] == x )
             return mid1 ; 

        if(  A[ mid2 ] == x ) 
             return mid2 ; 

        if(  x < A[mid1] ) 
          {  r = mid1 - 1 ; continue ; }  
        
        if(  x > A[mid2] ) 
          {  l = mid2 + 1 ; continue ; }
        
        l = mid1 + 1 ; 
        r = mid2 - 1 ;      

    }


    return -1;
}

// finding the maximum of unimodal functions using ternary search 


double func(double x)
{ 
   return  2*x*x - 12*x + 7 ;   // ax^2 + bx + c 
}


double ts(double start, double end)
{   
    start = -1e6 ; 
    end   =  1e6 ;

    double l = start, r = end;

    for(int i=0; i<200; i++) {
      
      double l1 = (l*2+r)/3;
      double l2 = (l+2*r)/3;
      //cout<<l1<<" "<<l2<<endl;
       if(func(l1) > func(l2)) r = l2;
        else l = l1;
      }

     double x = l;
    return func(x);
}