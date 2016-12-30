// MAximum lenggth cycle 
 // this code is for checking the longest cycle     , O(n*n) 

    	for (int i = 0; i < n; i++) // starting node of cycle 
    	{
    		int cur = i;
    		int rep = -1;
    		for (int j = 1; j <= n; j++)  // length of the cycle , can be atmost  1 ;
    		{
    			cur = t[cur];
    			if (cur == i)
    			{
    				rep = j;
    				break;
    			}
    		}
    		if (rep + 1)
    			result = max(result, rep);
    	}
