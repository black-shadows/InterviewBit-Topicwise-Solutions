std::vector<int> gr[50001];
int ans[2][50001],vis[50001];

void dfs(int n,vector<int> &B)
{
    if(vis[n])
        return;
    vis[n]=1;
    ans[0][n]=B[n-1];
    for(int v:gr[n])
    {
        if(vis[v]==0)
        {
            dfs(v,B);
            ans[0][n]+=ans[1][v];
            ans[1][n]+=max(ans[0][v],ans[1][v]);
        }
    }
}

int solveit(vector<int> &A, vector<int> &B)
{
    int n=A.size();
    for(int i=0;i<=n;i++)
        gr[i].clear();
    for(int i=1;i<n;i++)
    {
        gr[A[i]].push_back(i+1);
    }
    memset(ans,0,sizeof(ans));
    memset(vis,0,sizeof(vis));
    dfs(1,B);
    return max(ans[0][1],ans[1][1]);
}

int Solution::solve(vector<int> &A, vector<int> &B) {
    return solveit(A,B);
}

