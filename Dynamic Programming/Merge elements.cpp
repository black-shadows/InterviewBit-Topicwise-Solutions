int Solution::solve(vector<int> &A) {
    int n = A.size();
    if(n==0) 
        return 0;
    
    vector<vector<int>> dp(n,vector<int>(n,0));
    vector<int> sum(n,0);
    sum[0] = A[0];
    
    for(int i=1;i<n;i++)
        sum[i] = sum[i-1] + A[i];
    
    for(int len=1;len<n;len++){
        for(int i=0;i<n-len;i++){
            int j = i+len;
            int add = INT_MAX;
            for(int k=i;k<j;k++)
                add = min(add,dp[i][k] + dp[k+1][j]);
            dp[i][j] = (sum[j]-((i==0)? 0 : sum[i-1])) + add;
        }
    }
    return dp[0][n-1];
}
