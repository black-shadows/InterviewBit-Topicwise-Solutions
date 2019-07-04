int Solution::solve(int A) {
    long long mod = 1000000007;
    long long dp[2][A+1];
    dp[0][1] = 1LL;
    dp[1][1] = 1LL;
    for(int i = 2;i <= A;i++)
    {
        dp[0][i] = dp[0][i - 1] + dp[1][i - 1];
        dp[0][i] %= mod;
        dp[1][i] = dp[0][i - 1] % mod;
        dp[1][i] %= mod;
    }
    return (dp[0][A] + dp[1][A])%mod;
}