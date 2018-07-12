int lcs(string A, string B)
{
    
    int n=A.length();
    int dp[n+1][n+1];
    
    
    int i,j;
    
    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
            dp[i][j]=0;
            
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            if(A[i-1]==B[j-1] && i!=j)
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        
            //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        }
    
    return dp[n][n];
    
}




int Solution::anytwo(string A) {
    
    int l=lcs(A,A);
    
    if(l>=2)
        return 1;
    else
        return 0;
    
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}