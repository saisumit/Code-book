// Rabin Karp 



#define MO 1000000007 // needs to be a prime number to get good hash values



Int exp( Int base, Int pow)
 {
    Int ans = 1 ;
    while( pow )
     {
        if(pow & 1)
          ans = (ans * base)%MO;

           base =( base * base)% MO;
           pow >>=1 ;

     }


    return ans%MO;

 }


Int MOD (  Int a , Int b )
 {  return ( a%b  + b)%b  ; }


Int check ( string text ,  string pat , Int st ) // if hash values equal verification is done 
  {
  bool flag  = true;

    Int m = pat.length();

    for( Int i = 0 ; i < m ; ++i , ++st )
        if(text[st] != pat[i])
             return  0 ;

   return 1;

  }



Int rabin_karp ( string  text ,  string  pat )
 {
   Int n =  text.length();
   Int m =  pat.length();
   Int b = 26 ;  // can be any number greater than number of characters 
   if ( n < m ) return  0 ; // corner case

   Int hp = 0 ,ht = 0  ;
   Int ct = 0 ;
   for ( Int i = 0 ; i < m ;  i ++ ) // calculating the hash value of patterb 
      hp = MOD( hp*b + pat[i], MO);

   for( Int i = 0 ; i < m ; i  ++ )  // calculating the hash value of the text 
       ht = MOD( ht*b + text[i], MO);

   if( ht == hp ) ct += check ( text , pat , 0 ); // if hash values equal checking the cases

   Int E = exp(b, m-1); 

   for ( Int i= m ; i < n ; i ++ )  // just looping through entire text and repeating the above procedure
        {
          ht =  MOD( ht - MOD( text[i-m] * E , MO) , MO );
          ht =  MOD( ht*b  , MO );
          ht =  MOD( ht + text[i], MO );

          if( ht == hp ) ct += check( text , pat , i -m +1 );
        }
      return ct ;
 }