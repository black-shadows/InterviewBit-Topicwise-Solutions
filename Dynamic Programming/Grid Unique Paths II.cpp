long long dp[505][505];
const int MOD = 1000000007;

int uniquePathsII(vector<vector<int>>& A) {
    int n=A.size();
    if(n==0)
        return 0;
    int m=A[0].size();
    if(m==0)
        return 0;
    if(A[n-1][m-1]||A[0][0])
        return 0;
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)
            dp[i][j]=0;
    dp[0][0]=1LL;
    for(int i=1; i<n; ++i)
        if(A[i][0]==0)
            dp[i][0]=dp[i-1][0];
    for(int i=1; i<m; ++i)
        if(A[0][i]==0)
            dp[0][i]=dp[0][i-1];
    for(int i=1; i<n;++i)
        for(int j=1; j<m; ++j)
            if(A[i][j]==0)
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
    return dp[n-1][m-1];
}
int Solution::solve(vector<vector<int> > &A) {
    return uniquePathsII(A);
}