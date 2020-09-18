int Solution::solve(vector<vector<int> > &a) {
    
    int n=a.size();
    int dp[n];
    dp[0]=1;
    for(int i=1;i<n;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(a[i][0] > a[j][1] && dp[i]<=dp[j]){
                dp[i]=1+dp[j];
            }
        }
    }
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        if(dp[i]>ans){
            ans=dp[i];
        }
    }
    return ans;
}
