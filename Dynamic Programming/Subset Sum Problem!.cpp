int Solution::solve(vector<int> &A, int B) {
    int sum=0;
    int n=A.size();
    for(int i=0;i<n;i++){
        sum=sum+A[i];
    }
    if(B>sum)   return 0;
    vector<int> dp(sum+1,0);
    dp[0] = 1;
    for(int i=0; i<n; i++){
        for(int j=A[i]; j<=sum; j++){
            dp[j] = dp[j] || dp[j-A[i]];
        }
    }
    return dp[B];
}
