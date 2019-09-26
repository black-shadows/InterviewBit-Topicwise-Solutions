int dp[1000][1000],vis[1000][1000];
string str;
int mark[1000];
void markfun(int i,int j)
{
    if(i>j or vis[i][j])
        return;
    if(i==j)
    {
        mark[i]=1;
        return;
    }
    vis[i][j]=1;
    if(str[i]==str[j])
    {
        markfun(i+1,j-1);
        return;
    }
    if(dp[i][j]==dp[i][j-1])
    {
        markfun(i,j-1);
    }
    if(dp[i][j]==dp[i+1][j])
    {
        markfun(i+1,j);
    }
}
int fun(int i,int j)
{
    if(i>j)
        return 0;
    if(dp[i][j]>=0)
        return dp[i][j];
    if(i==j)
        return dp[i][j]=1;
    if(str[i]==str[j])
        dp[i][j]=2+fun(1+i,j-1);
    else
        dp[i][j]=max(fun(i+1,j),fun(i,j-1));
    return dp[i][j];
}

int solveit(string A,string B)
{
    int ans1,ans2;
    int charac1[26],charac2[26];
    memset(charac1,0,sizeof charac1);
    memset(charac2,0,sizeof charac2);
    str=A;
    memset(dp,-1,sizeof dp);
    memset(mark,0,sizeof mark);
    memset(vis,0,sizeof vis);
    ans1=fun(0,str.length()-1);
    markfun(0,str.length()-1);
    for(int i=0;i<str.length();i++)
        if(mark[i])
            charac1[str[i]-'a']=1;
        
       str=B;
    memset(dp,-1,sizeof dp);
    memset(mark,0,sizeof mark);
    memset(vis,0,sizeof vis);
    ans2=fun(0,str.length()-1);
    markfun(0,str.length()-1);
    for(int i=0;i<str.length();i++)
        if(mark[i])
            charac2[str[i]-'a']=1;
        
    if(ans1%2==1 and ans2%2==1)
    {
        bool flag=true;
        for(int i=0;i<26;i++)
        {
                if(charac1[i]==1 and charac2[i]==1)
                {
                    return ans1+ans2;
                }
            }
            return ans1+ans2-1;
    }
    return ans1+ans2;
}
int Solution::solve(string A, string B) {
    return solveit(A,B);
}