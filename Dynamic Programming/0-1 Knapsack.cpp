int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int n = A.size();
    
    int dp[n+1][C+1];
    
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int j=0;j<=C;j++){
        dp[0][j] = 0;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=0;j<=C;j++){
            if(B[i-1] <= j){
                dp[i][j] = max(A[i-1] + dp[i-1][j-B[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    return dp[n][C];
}