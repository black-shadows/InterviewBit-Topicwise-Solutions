int Solution::solve(const vector<int> &A)
{
    int sum=0;
    for(int i=0;i<A.size();i++)
    sum+=A[i];
    int temp=sum/2;
    vector<int>dp(temp+1,INT_MAX);
    dp[0]=0;
    for(int i=0;i<A.size();i++)
    {
        for(int j=temp;j>=A[i];j--)
        {
            if(dp[j-A[i]]!=INT_MAX)
            {
                dp[j]=min(dp[j],dp[j-A[i]]+1);
            }
        }
    }
    for(int j=temp;j>=0;j++)
    {
        if(dp[j]!=INT_MAX)
        return dp[j];
    }
    
    
    
}