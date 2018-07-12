int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    vector<int> dp(1001,INT_MAX);
    dp[0]=0;
    for(int i =0; i<B.size();i++){
        if(B[i]==1){
            for(int x = 1; x<1001; x++) dp[x] = C[i]+dp[x-1];
            break;
        }
    }
    for(int i =0 ; i<B.size();i++){
        for(int x=B[i];x<1001;x++){
            dp[x] = min(dp[x],dp[x-B[i]] + C[i]);
        }
    }
    long long int ans=0;
    for(int i : A) ans += dp[i];
    return ans;
}