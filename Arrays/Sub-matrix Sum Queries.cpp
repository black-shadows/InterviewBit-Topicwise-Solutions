vector<int> Solution::solve(vector<vector<int> > &A, vector<int> &B, vector<int> &C, vector<int> &D, vector<int> &E) 
{
    
    int n = A.size(), m = A[0].size();
    
    long long int mod = 1000000007;
    
    long long int dp[n+1][m+1];
    
    for(int i=0; i<=n; i++)
    {
        
        dp[i][0] = 0;
        
    }
    
    for(int i=0; i<=m; i++)
    {
        
        dp[0][i] = 0;
        
    }
    
    for(int i=1; i<=n; i++)
    {
        
        for(int j=1; j<=m; j++)
        {
            
            dp[i][j] = (mod + dp[i-1][j]%mod + dp[i][j-1]%mod + A[i-1][j-1]%mod - dp[i-1][j-1]%mod)%mod;
            
        }
        
    }
    
    vector<int> ans;
    
    for(int i=0; i<B.size(); i++)
    {
        
        int row1 = B[i];
        
        int col1 = C[i];
        
        int row2 = D[i];
        
        int col2 = E[i];
        
        int sum = (mod + dp[row2][col2]%mod - dp[row1 - 1][col2]%mod - dp[row2][col1 - 1]%mod + dp[row1 - 1][col1 - 1]%mod)%mod;
        
        if(sum < 0)
        {
            
            sum = sum + mod;
            
        }
        
        ans.push_back(sum%mod);
        
    }
    
    return ans;
    
}
