#define DIST 100

struct node
{
   node * ar[ DIST ]  ;
   int  cnt = 0 ;
   bool End = false ;
   node() { FOR( i , DIST ) ar[i] = NULL ;  }
};

void trie_insert( node* root , string& s )
 {
    node* hd  =  root ;
    for( int i  = 0 ; i < s.length() ; i ++ )
      {
      	  int idx = s[i] - 'A' ;
          node** ar = hd->ar ;
          if( ar[idx] == NULL )
           {
              node* tp = new node() ;
              ar[idx] = tp ;
              ar[idx]->cnt = 1 ;
              hd = tp ;
           }
          else
           {
           	    (ar[idx]->cnt ) ++ ;
           	     hd  =  ar[idx] ;
           }

      }

     hd->End = true ;

 }

void Print_Trie( node* hd ,  string pr )
 {
   if( hd->End )cout<<pr<<endl;
   node** ar = hd->ar  ;

   FOR( i , DIST )
      if( ar[i] != NULL )
        {
          char u = i + 'A' ;
          Print_Trie( ar[i] , pr + u ) ;
        }
 }


node* Trie_Match( node* root ,  string& s  , int L , int R )
 {
    node* hd = root ;

    for( int i = L ; i <= R ; i ++ )
     {
        int idx = s[i] - 'A' ;
        node** ar = hd->ar ;
        if( ar[idx] == NULL ){ return false ; }
        else hd = ar[idx] ;
     }

   return  hd ;

 }


void trie_remove( node& root , string& s )
 {
     node* hd = root ; 
     for( int i = 0 ; i < s.length() ; i ++ )
     	{
          int idx = s[i] - 'A' ; 
          node** ar = hd->ar ;
          if( ar[idx] != NULL )
          	 {
          	 	ar[idx]->cnt -- ; 
          	 	hd = ar[idx] ; 
          	 	if( ar[idx]-> cnt == 0 )
          	      {
          	      	ar[idx] = NULL ;
          	      	break ;
          	      }		
          	 }

     	}

 }
