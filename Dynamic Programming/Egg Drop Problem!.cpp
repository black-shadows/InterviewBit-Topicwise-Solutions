int Solution::solve(int A, int B) {
    vector<int>dp(A+1, 0);
    int m;
    for(m = 0; dp[A] < B; m++)
    {
        for(int k = A; k>0; k--)
        {
            dp[k] += dp[k-1] + 1;
        }
    }
    return m;
}