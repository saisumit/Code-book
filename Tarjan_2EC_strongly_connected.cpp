// 2 -Edge-connectivity , Tarjan , Articulation-Point

vector<int>arr;
vector<bool>visit;
int arpt = - 1 ;

bool strongly_connected  = true ;
bool  SC( v )
  {

        arr[v] = tm++;
        visited [v] = true;
        int noot = arr[v] ;

    for ( int i = 0 ; i < g[v].size() ; i ++  )
    	  { int w = g[v][i];

            if( !visited[w])
                 noot = min( noot, SC(w)  );
            else noot = min ( noot, arr[w] ) //Back-Edge or Cross Edge

           if( noot = arr[v] )
            { arpt = v;  strongly_connected = false ; break ; }

    	  }


  }
