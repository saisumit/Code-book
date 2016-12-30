
// SPARSE TABLE
// M[i][j] = index of the minimum value in subarray starting at i having length 2^j 

void process2(int M[MAXN][LOGMAXN], int A[MAXN], int N)
  {
      int i, j;
   
  //initialize M for the intervals with length 1
      for (i = 0; i < N; i++)
          M[i][0] = i;
  //compute values from smaller to bigger intervals
      for (j = 1; 1 << j <= N; j++)
          for (i = 0; i + (1 << j) - 1 < N; i++)
              if (A[M[i][j - 1]] < A[M[i + (1 << (j - 1))][j - 1]])
                  M[i][j] = M[i][j - 1];
              else
                  M[i][j] = M[i + (1 << (j - 1))][j - 1];
  }  

  /*
  we have these values preprocessed, let’s show how we can use them to calculate RMQA(i, j).
  The idea is to select two blocks that entirely cover the interval [i..j] and 
  find the minimum between them. Let k = [log(j - i + 1)]. 
  For computing RMQA(i, j) we can use the following formula:
  So, the overall complexity of the algorithm is <O(N logN), O(1)

  RMQ( i ,j )= min ( M[i][k] , M[ j - 2^k + 1 ][k]) ; 

  */