int solveit(vector<int> &a,int fee){
    int n=a.size();
    int dp[n];
    memset(dp,0,sizeof dp);
    int max_prof = dp[0] - a[0] - fee;
    for(int i = 1; i<n; i++){
        dp[i] = max(dp[i-1], max_prof + a[i]);
        max_prof = max(max_prof, dp[i] - a[i] - fee);
    }
    return dp[n-1];
}

int Solution::solve(vector<int> &A, int B) {
    return solveit(A,B);
}