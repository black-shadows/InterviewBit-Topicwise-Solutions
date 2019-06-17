const int N =100005;


vector<pair<int,int> > g[N];
vector<int> vis(N);

void clean(int n){
    for(int i=0; i<=n; ++i){
            g[i].clear();
            vis[i]=0;
    }
}

void make_graph(vector<vector<int> > &edges){
    for(auto &it:edges){
        int x=it[0];
        int y=it[1];
        int w=it[2];
        g[x].push_back({w,y});
        g[y].push_back({w,x});
    }
}


int MinimumCostToConnectCities(int n,vector<vector<int> > &edges){
    clean(n);
    make_graph(edges);
    priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> > > q;
    q.push({0,1});
    int mincost=0;
    while(!q.empty()){
        int x=q.top().second;
        int w=q.top().first;
        q.pop();
        if(vis[x]) continue;
        mincost+=w;
        vis[x]=1;
        for(int i=0; i<g[x].size(); ++i){
            int y=g[x][i].second;
            if(!vis[y])
                q.push(g[x][i]);
        }
    }
    return mincost;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    return MinimumCostToConnectCities(A,B);
}