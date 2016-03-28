// Matrix - Expoenentiation ,  Matrix - Multiplication Code
//class for matrix spoj  - SUMSUMS , saisumit

struct TMatr{

    int n;//length and width of matrix. cause the matrix is quadratic it's the same
    ll A[N][N];
    TMatr operator * (TMatr b);
};
 
TMatr res; // A temperory matrix used for multiplication 
 
TMatr TMatr::operator * (TMatr b)//operator of multiplying matrixes
{
    res.n = n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            res.A[i][j] = 0;
            for (int k = 0; k < n; k++)
                res.A[i][j] = (res.A[i][j] + (this->A[i][k] * b.A[k][j]) % Mi) % Mi; //res[i][j] = sum(a[i][k]*b[k][j]), k = 0..n-1
        }
    return res;
}
 
 
 TMatr exp( TMatr base , int po )
   {
   	 TMatr Ans;
   	 Ans.n = .... // what is the order of the matrix  
     while( po )
     	 {
            if( po & 1) Ans = Ans * base ;
            base =  base * base ;
            po >>=1 ;
     	 }

      return Ans ;
   }