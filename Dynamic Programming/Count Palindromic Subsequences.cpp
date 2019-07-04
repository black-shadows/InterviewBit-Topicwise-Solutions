int Solution::solve(string A) {
    long long mod = 1000000007;
    int n;
    n = A.length();
    if(n==1)
    {
        return 1;
    }
    long long dp[n+1][n+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            dp[i][j] = 0;
        }
    }
    for(int i = 0; i<n;i++)
    {
        dp[i][i] = 1;
    }
    for(int i=0;i<n-1;i++)
    {
        if(A[i] == A[i+1])
        {
            dp[i][i+1] = 3;
        }
        else
        {
            dp[i][i+1] = 2;
        }
    }
    for(int i=3;i<=n;i++)
    {
        for(int j=0;i+j-1<n;j++)
        {
            long long a = 0;
            if(A[j] == A[i+j-1])
            {
                a = 1;
            }
            dp[j][i+j-1] = (((dp[j + 1][i + j - 1]%mod) + (dp[j][i + j - 2] - dp[j + 1][i + j - 2])%mod)%mod + ((a) * (dp[j + 1][i + j - 2]+1))%mod)%mod;
        }
    }
    return dp[0][n-1]%mod;
}
