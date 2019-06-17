int Solution::solve(int A, vector<int> &B) {
    int dp[A+1];
    dp[0] = 0;
    for(int i=1;i<=A;i++)
    {
        int var = B[i-1];
        for(int j = 1;j < i;j++)
        {
            var = max(dp[i-j] + dp[j], var);
        }
        dp[i]  = var;
    }    
    return dp[A];
}