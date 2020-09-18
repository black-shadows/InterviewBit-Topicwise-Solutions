const int maxn=100009;
long long sum,maxe;
vector<int> adj[maxn];
#define MOD 1000000007

int dfs(int u,int v,vector<int> &A)
{
    int s=0;
    s+=A[u-1];
    
    for(int i=0;i<adj[u].size();i++)
    {
        if(adj[u][i]==v)
            continue;
        
        s+=dfs(adj[u][i],u,A);    
    }
    long long res=((s%MOD)*((sum-s)%MOD))%MOD;
    
    maxe=max(maxe,res);
    return s;
}

int Solution::deleteEdge(vector<int> &A, vector<vector<int> > &B) {
    sum=0;
    maxe=0;
    
    for(int i=0;i<maxn;i++)
        adj[i].clear();
    for(int i=0;i<A.size();i++)
        sum+=A[i];
    for(int i=0;i<B.size();i++)
    {
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }        
    
    int ans=dfs(1,0,A);
    
    return (int)maxe;
}
