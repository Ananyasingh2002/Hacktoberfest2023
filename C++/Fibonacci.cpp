//Recursive Approach
    int fib(int N) {
        if(N == 0)  return 0;
        if(N == 1)  return 1;
        return fib(N-1) + fib(N-2);
    }

//Dynamic Programming Approach
int fib(int n) {
      vector<int> f(n+2,0);
        f[0]=0; f[1]=1;
        for(int i=2; i<=n; i++)
        {
            f[i]=f[i-1]+f[i-2];
        }
        return f[n];
    }

//Imperative Approach (Bottom Up DP)
    int fib(int N) {
        if(N < 2) 
            return N;
    	int a = 0, b = 1, c = 0;
        for(int i = 1; i < N; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
