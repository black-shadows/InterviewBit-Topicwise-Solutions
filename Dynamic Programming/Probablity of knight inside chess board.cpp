const int MOD=1e8+7;

int solve(int A,int B,int C,int D)
{
    long long dp[A+4][A+4][2];
    memset(dp,0,sizeof dp);
    dp[C+1][D+1][0]=1;int ans=0;
    for(int k=1;k<=B;k++)
    {
        for(int i=2;i<=A+1;i++)
        {
            for(int j=2;j<=A+1;j++)
            {
                dp[i][j][1]=12500001LL*(dp[i-2][j-1][0]+dp[i-1][j-2][0]+dp[i+1][j-2][0]+dp[i+2][j-1][0]+dp[i-1][j+2][0]+dp[i-2][j+1][0]+dp[i+2][j+1][0]+dp[i+1][j+2][0]);
                dp[i][j][1]%=MOD;
            }
        }
        for(int i=2;i<=A+1;i++)
        {
            for(int j=2;j<=A+1;j++)
            {
                dp[i][j][0]=dp[i][j][1];
            }
        }
    }
        for(int i=2;i<=A+1;i++)
        {
            for(int j=2;j<=A+1;j++)
            {
                ans+=dp[i][j][0];
                ans%=MOD;
            }
        }
    return ans;
}
int Solution::solve(int A, int B, int C, int D) {
    return ::solve(A,B,C,D);
}
