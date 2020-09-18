int Solution::solve(vector<int> &A) {
int n=A.size();
int s=0;
for(int i=0; i<n ; i++)
    s=s+A[i];
int dp[n+1][s+1];


for(int i=0; i<=n ; i++)
    dp[i][0]=1;
    
for(int j=1; j<=s; j++)
    dp[0][j]=0;
    
for(int i=1; i<=n ; i++)
{
    for(int j=1; j<=s; j++)
    {
        if(A[i-1]<= j )
            dp[i][j]=dp[i-1][j] || dp[i-1][j-A[i-1]];
        else
            dp[i][j]=dp[i-1][j];
    }
}
for(int i=s/2;i>=0; i--)
{
    if(dp[n][i])
      return( abs(s-2*i)  )  ;
}
}
