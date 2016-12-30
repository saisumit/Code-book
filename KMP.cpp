// KMP String matching ALGO 
// prefix[i]  represents length of longest proper prefix  which is equal to proper suffix in the range (0,i) ;  
//Referencr codeforces - Messenger, 344- div - 2  , handle - alpha go
std::vector<Int> Build( string  s )
  {
     int n = s.length();
     vector<Int>pref(n);
     pref[0] = 0 ;
     for ( int i = 1 ; i < n ; i ++ )
        {
          int j =  pref[i-1];
          while ( j > 0 && !(s[i] == s[j]))
                     j = pref[j-1];
          if( s[i] == s[j])   ++j ;
          pref[i]  =  j ;
        }
 
      return pref ;


  }

Int KMP ( string  text ,  string pat)
  {

       int n =  text.length();
       int m =  pat.length();

       if ( m >  n ) return  0 ;  // Corner Case
       Int ans = 0 ;

        if (m == 1) {   // if m == 1 brute force 
        for (int i = 0; i < n; i++)
            if( pat[0] == text[i] )
                 ans ++;
                
                return ans;
              }

        if (m == 2) {  // brute force again 
            for (int i = 0; i < n - 1; i++)
             if (pat[0] == text[i] && pat[1] == text[i + 1])
                                ans++;
                  return ans;
                    }


      vector<Int>Prefix = Build( pat );

       int q = 0 ; // number of characters matched

       for ( int i = 0 ; i < n  ; i ++ )
         {  while( q > 0 && pat[q] != text[i] ) // If next character does not matches
                   { q = Prefix[q] ; }

             if( patex[q] ==  text[i] )
                 q = q + 1 ;

             if( q == m )
              { ans += 1 ;
                q = Prefix[q-1] ;
               }

                   return ans; }
  }
