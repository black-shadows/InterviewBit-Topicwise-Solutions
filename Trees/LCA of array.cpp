pair<int,int> segtree[800008];
int in[100001],out[100001],vis[100001];
vector<int> gr[100001];
vector<pair<int,int> > euler;
void dfs(int i=0,int depth=0)
{
    if(vis[i])
        return;
    vis[i]=1;
    in[i]=euler.size();
    euler.push_back({depth,i});
    for(int j:gr[i])
    {
        if(vis[j]==0)
        {
            dfs(j,depth+1);
            euler.push_back({depth,i});
        }
    }
    out[i]=euler.size()-1;
}

void build(int node,int tl,int tr)
{
    if(tl==tr)
    {
        segtree[node]=euler[tl];
        return;
    }
    int tm=(tl+tr)/2;
    build(2*node,tl,tm);
    build(2*node+1,tm+1,tr);
    segtree[node]=min(segtree[2*node],segtree[2*node+1]);
}

pair<int,int> query(int node,int tl,int tr,int l,int r)
{
    if(l==tl and r==tr)
        return segtree[node];
    int tm=(tl+tr)/2;
    if(tm>=r)
        return query(2*node,tl,tm,l,r);
    if(tm<l)
        return query(2*node+1,tm+1,tr,l,r);
    return min(query(2*node,tl,tm,l,tm),query(2*node+1,tm+1,tr,tm+1,r));
}

int solveit(vector<int> &A, vector<int> &B)
{
    int n=A.size();
    for(int i=0;i<=n;i++)
        gr[i].clear();
    euler.clear();
    memset(vis,0,sizeof vis);
    for(int i=0;i<n;i++)
    {
        gr[A[i]].push_back(i+1);
        gr[i+1].push_back(A[i]);
    }
    dfs();
    build(1,0,euler.size()-1);
    int ans=B[0];
    for(int i=1;i<B.size();i++)
    {
        auto x = query(1,0,euler.size()-1,min(in[ans],in[B[i]]),max(out[ans],out[B[i]]));
        ans=x.second;
    }
    return ans;
}
int Solution::solve(vector<int> &A, vector<int> &B) {
    return solveit(A,B);
}
