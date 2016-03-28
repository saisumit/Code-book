// Fast input - Output 


inline void scanint(long long int &x)
 {     register long long int c = getchar();
     x = 0;
     long long int neg = 0;
     for(;((c<48 || c>57) && c != '-');c = getchar());
     if(c=='-') {neg=1;c=getchar();}
     for(;c>47 && c<58;c = getchar()) {x = (x<<1) + (x<<3) + c - 48;}
     if(neg) x=-x;
 }

 inline int inp()
{
    int noRead=0;
    char p= getchar_unlocked();
    for(;p<33;)
    {
     p=getchar_unlocked();
    };
    while(p>32)
    {
     noRead = (noRead << 3) + (noRead << 1) + (p - '0');
     p=getchar_unlocked();
    }
    return noRead;
};


// In general scanf is faster than cin even with cin.tie(0) && ios::sync_with_stdio(0) , and printf is faster than cout 
// Code-forces   304 Div  2 -  problem D 


/** For codeforces this works the fastest  **/

int readInt ()
{
    bool minus = false;
    int result = 0;
    char ch;
    ch = getchar();
    while (true)
    {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') minus = true;
    else result = ch-'0';
    while (true)
    {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}


inline void writeInt (int n)
{
    int NN = n, rev, count = 0;
    rev = NN;
    if (NN == 0) { putchar('0');  return ;}
    while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
    rev = 0;
    while (NN != 0) { rev = (rev<<3) + (rev<<1) + NN % 10; NN /= 10;}  //store reverse of N in rev
    while (rev != 0) { putchar(rev % 10 + '0'); rev /= 10;}
    while (count--) putchar('0');
}
