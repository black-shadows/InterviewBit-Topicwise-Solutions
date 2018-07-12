int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    
    vector<vector<int>> dp(A.size(), vector<int>(A[0].size(), 0));
    dp[0][0] = A[0][0] ^ 1;
    for(int i = 1; i < A.size(); ++i) {
        if(!A[i][0]) dp[i][0] += dp[i-1][0];
        else dp[i][0] = 0;
    }
    for(int i = 1; i < A[0].size(); ++i) {
        if(!A[0][i]) dp[0][i] += dp[0][i-1];
        else dp[0][i] = 0;
    }
    for(int i = 1; i < A.size(); ++i)
        for(int j = 1; j < A[0].size(); ++j) {
            if(A[i][j]) continue;
            dp[i][j] += dp[i-1][j] + dp[i][j-1];
        }
    return dp[(int)A.size() - 1][(int)A[0].size() - 1];
}
