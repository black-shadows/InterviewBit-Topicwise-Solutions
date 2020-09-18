int Solution::solve(vector<vector<int> > &A) {
    int n=A.size();
    int dp[n+1][3];
    int i,j;
    for(i=0;i<=2;i++)
    dp[0][i]=0;
    for(i=1;i<=n;i++)
    {
        dp[i][0]=A[i-1][0]+min(dp[i-1][1],dp[i-1][2]);
        dp[i][1]=A[i-1][1]+min(dp[i-1][0],dp[i-1][2]);
        dp[i][2]=A[i-1][2]+min(dp[i-1][0],dp[i-1][1]);
    }
    
    return min(dp[n][0],min(dp[n][1],dp[n][2]));
}