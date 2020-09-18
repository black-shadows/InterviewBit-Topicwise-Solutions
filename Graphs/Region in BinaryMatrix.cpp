int res;
void dfs(int i,int j,vector<vector<int>>&mat ,vector<vector<bool>>&dp,int N,int M)
{
    if(dp[i][j]==true)
      return;
    
    if(mat[i][j]==0)
      return;
    dp[i][j]=true;
    res++;
    if((i-1)>=0 && !dp[i-1][j])
      dfs(i-1,j,mat,dp,N,M);
    if((i+1)<N && !dp[i+1][j])
      dfs(i+1,j,mat,dp,N,M);
    if((j-1)>=0 && !dp[i][j-1])
      dfs(i,j-1,mat,dp,N,M); 
    if((j+1)<M && !dp[i][j+1])
      dfs(i,j+1,mat,dp,N,M);
    if((i-1)>=0 && (j-1)>=0 && !dp[i-1][j-1])
      dfs(i-1,j-1,mat,dp,N,M);
    if((i-1)>=0 && (j+1)<M && !dp[i-1][j+1])
      dfs(i-1,j+1,mat,dp,N,M);  
     if((i+1)<N && (j-1)>=0 && !dp[i+1][j-1])
      dfs(i+1,j-1,mat,dp,N,M); 
      if((i+1)<N && (j+1)<M && !dp[i+1][j+1])
      dfs(i+1,j+1,mat,dp,N,M); 
}

int findMaxArea(int N, int M, vector<vector<int> >&A )
{
   vector<vector<bool>>vis(N,vector<bool>(M,false));
    int ans=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(!vis[i][j] && A[i][j]==1)
            {
                dfs(i,j,A,vis,N,M);
                ans=max(ans,res);
                res=0;
            }
        }
    }
    return ans;
}

int Solution::solve(vector<vector<int> > &A) {
    return findMaxArea(A.size(),A[0].size(),A);
}
