int Solution::solve(vector<vector<int> > &A) {
   int n=A.size();
   int m=A[0].size();
   vector<vector<int>>dp(n,vector<int>(m,-1));
   dp[0][0]=1;
   for(int i=1;i<m;i++)
   {
      if(A[0][i]>A[0][i-1])
      dp[0][i]=1+dp[0][i-1];
   }
   for(int i=1;i<n;i++)
   {
      if(A[i][0]>A[i-1][0])
      dp[i][0]=1+dp[i-1][0];
   }
   for(int i=1;i<n;i++)
   {
       for(int j=1;j<m;j++)
       {
           if(dp[i-1][j]==-1 && dp[i][j-1]==-1)
           return -1;
           if(A[i][j]>A[i-1][j]||A[i][j]>A[i][j-1])
           dp[i][j]=1+max(dp[i-1][j],dp[i][j-1]);
        }
    }
    if(dp[n-1][m-1]==0)
    return -1;
    return dp[n-1][m-1];
}