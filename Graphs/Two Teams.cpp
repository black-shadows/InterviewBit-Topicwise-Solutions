typedef vector<int> vi;
const int mxSize=1e5+1;
vi adj[mxSize];
bool dfs(int src,vector<bool>& vis,vi& grpId,int grpVal)
{
    grpId[src]=grpVal;
    vis[src]=true;
    int  n=adj[src].size();
    for(int i=0;i<n;i++)
    {
        if(!vis[adj[src][i]])
        {
            if(!dfs(adj[src][i],vis,grpId,1-grpVal))
                return false;
        }
        else if(grpId[adj[src][i]]!=1-grpVal)
            return false;
    }
    return true;
}
int Solution::solve(int A, vector<vi> &B) {
    int m=B.size();
    vi grpId(A,-1);
    vector<bool> vis(A,false);
    for(int i=0;i<A;i++)
        adj[i].clear();
    for(int i=0;i<m;i++)
    {
        adj[B[i][0]-1].push_back(B[i][1]-1);
        adj[B[i][1]-1].push_back(B[i][0]-1);
    }
    for(int i=0;i<A;i++)
    {
        if(!vis[i]){
            if(!dfs(i,vis,grpId,0))return false;
        }
    }
    return true;
}