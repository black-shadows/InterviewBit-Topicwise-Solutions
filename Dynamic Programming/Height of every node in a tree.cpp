int in[100001],out[100001];
void dfs1(vector<int> adj[],int u,int p){
    in[u]=0;
    for(int child : adj[u]){
        if(child==p)continue;
        dfs1(adj,child,u);
        in[u]=max(in[u],1+in[child]);
    }
}
void dfs2(vector<int> adj[],int u,int p){
    int mx1=-1,mx2=-1;
    for(int child : adj[u]){
        if(child==p)continue;
        if(in[child]>=mx1){
            mx2=mx1;
            mx1=in[child];
        }
        else if(in[child]>mx2){
            mx2=in[child];
        }
    }
    for(int child : adj[u]){
        if(child==p)continue;
        int l=mx1;
        if(mx1==in[child]){
            l=mx2;
        }
        out[child]=1+max(out[u],1+l);
        dfs2(adj,child,u);
    }
}
vector<int> Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> adj[A+1];
    for(int i=0;i<B.size();i++){
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }
    dfs1(adj,1,0);
    dfs2(adj,1,0);
    vector<int> ans(A);
    for(int i=0;i<A;i++){
        ans[i]=max(in[i+1],out[i+1]);
    }
    return ans;
}
