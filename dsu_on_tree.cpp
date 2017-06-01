



/* Complexity : Nlognlogn*/
map<int, int> *cnt[maxn]; // map to store the number of vertices of m[ color ]  

void dfs(int v, int p){

    int mx = -1, bigChild = -1;

    for(auto u : g[v]) // Loop through all children 
       if(u != p){     // if child is not equal to parent 
           dfs(u, v);  
           if(sz[u] > mx) // if size of this subtree is greater than maximum  than interchange 
               mx = sz[u], bigChild = u; 
       }
    if(bigChild != -1) // if there is a big child that is v is not a leaf node 
        cnt[v] = cnt[bigChild];  // Assign the pointer to the map of the  big child to this vertex
    else
        cnt[v] = new map<int, int> (); // if its a leaf node
    (*cnt[v])[ col[v] ] ++; // add the current vertex to the map 
    for(auto u : g[v]) 
       if(u != p && u != bigChild){ // Adding nodes of all the vertex
           for(auto x : *cnt[u])
               (*cnt[v])[x.first] += x.second;
       }


/* Complexity O( N LOGN ) */
 
vector<int> *vec[maxn]; // This stores all the children of the subtree of that node. 
int cnt[maxn]; // Count[c] is the number of vertices in subtree of vertex that has color c . 
void dfs(int v, int p, bool keep){
  
    int mx = -1, bigChild = -1; // Initialising the maximum and the biggest child   
  
    for(auto u : g[v]) 
       if(u != p && sz[u] > mx) // Finding the biggest subtree 
           mx = sz[u], bigChild = u; 
  
    for(auto u : g[v])
       if(u != p && u != bigChild) // If not the biggest tree 
           dfs(u, v, 0);
  
    if(bigChild != -1)
        dfs(bigChild, v, 1), vec[v] = vec[bigChild]; // Run the dfs on biggest subtree and pass the pointer of this tree to parent
    else
        vec[v] = new vector<int> (); // For leaf node 
    vec[v]->push_back(v) ;  // Add this vertex to vector of this tree 
    cnt[ col[v] ]++ ;       // Updating the frequency of that color 
    for(auto u : g[v])      // Loop through all childrens        
       if(u != p && u != bigChild)  // if u not ==  parent and u not the biggest child 
           for(auto x : *vec[u]){ 
               cnt[ col[x] ]++;  // Update the color frequency 
               vec[v] -> push_back(x); // push the vertex to vector
           }

    if(keep == 0)
        for(auto u : *vec[v])
            cnt[ col[u] ]--; // if it is not biggesst child then we have to subtract one because it will be calculated again and if
          // we don't remove it,  it may lead to error of double counting . 
}  
