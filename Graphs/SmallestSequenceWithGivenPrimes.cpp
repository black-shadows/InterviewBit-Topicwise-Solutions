#define pb push_back
vector<int> Solution::solve(int A, int B, int C, int D) 
{
    vector<int> dp;
    dp.pb(1);
    int i1 = 0,i2 = 0, i3 = 0;
    for(int i = 1; i <= D; i++)
    {
        
        dp.pb(min(dp[i1]*A,min(dp[i2]*B,dp[i3]*C)));
        
        if(dp[i] == dp[i1]*A)
            i1++;
    
        if(dp[i] == dp[i2]*B)
            i2++;
            
        if(dp[i] == dp[i3]*C)
            i3++;
    }
    vector<int>ans;
    for(int i = 1; i < dp.size(); i++)
        ans.pb(dp[i]);
        
    return ans;
    
}