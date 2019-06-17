const int N =200005;
vector<int> g[N];
int vis[N];

void clean(int n){
    for(int i=0; i<=n; ++i){
        g[i].clear();
        vis[i]=0;
    }
}

void make_graph(int n,vector<vector<int> > &edges){
    for(auto &it:edges){
        int x=it[0];
        int y=it[1];
        int w=it[2];
        if(w==1){
            g[x].push_back(y);
            g[y].push_back(x);
        }
        else{
            g[x].push_back(x+n);
            g[x+n].push_back(y);
            g[y].push_back(y+n);
            g[y+n].push_back(x);
        }
    }
}

int shortestDistance(int n,vector<vector<int> > &edges,int source,int destination){
    clean(n+n);
    make_graph(n,edges);
    vis[source]=1;
    queue<pair<int,int> > q;
    q.push({source,0});
    while(!q.empty()){
        int x=q.front().first;
        int w=q.front().second;
        q.pop();
        if(x==destination)
            return w;
        for(auto &it:g[x]){
            if(!vis[it]){
                vis[it]=1;
                q.push({it,w+1});
            }
        }
    }
    return -1;
}

int Solution::solve(int A, vector<vector<int> > &B, int C, int D) {
        return shortestDistance(A,B,C,D);
}