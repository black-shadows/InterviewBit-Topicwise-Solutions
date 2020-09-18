int dp[100001];

int root(int x)
{
    while(x!=dp[x])
    {
        dp[x]=dp[dp[x]];
        x=dp[x];
    }
    return x;
}
void unio(int x,int y)
{
dp[root(x)]=dp[root(y)];
}
int Solution::solve(vector<int> &a, vector<int> &b, vector<vector<int> > &c) {
    int i;
    for(i=0;i<100001;i++)
    dp[i]=i;
    int n=a.size();
    int m=c.size();
    for(i=0;i<m;i++)
    {int x=a[c[i][0]-1];
    int y=a[c[i][1]-1];
    unio(x,y);
    }
    for(i=0;i<n;i++)
    {
        if(root(a[i])!=root(b[i]))
        return 0;
    }
    
    return 1;
}