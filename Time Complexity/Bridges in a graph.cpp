const int N =100005;
vector<int> g[N],disc(N),low(N),par(N),vis(N),ap(N);
map<pair<int,int>,int> mp;
int t=0;


void clean(int n){
    for(int i=0; i<=n; ++i){
        g[i].clear();
        vis[i]=0;
        low[i]=1000000000;
        par[i]=0;
        ap[i]=0;
    }
    mp.clear();
    t=0;
}

void make_graph(vector<vector<int> > &edges){
    for(auto &it:edges){
        int x=it[0];
        int y=it[1];
        g[x].push_back(y);
        g[y].push_back(x);
    }
}

void dfs(int x){
    vis[x]=1;
    low[x]=disc[x]=++t;
    int child=0;
    for(int j:g[x]){
        if(!vis[j]){
            ++child;
            par[j]=x;
            dfs(j);
            low[x]=min(low[x],low[j]);
            if(par[x]==0&&child>1)
                ap[x]=1;
            if(par[x]&&disc[x]<=low[j])
                ap[x]=1;
        if(disc[x]<low[j])
            mp[{min(x,j),max(j,x)}]=1;
    }
    else{
        if(par[x]!=j)
            low[x]=min(low[x],disc[j]);
    }
}
}

vector<vector<int> > bridges(int n,vector<vector<int> > &edges){
    clean(n);
    make_graph(edges);
    for(int i=1; i<=n; ++i)
        if(!vis[i])
            dfs(i);
    vector<vector<int> > bridges;
    for(auto &it:edges){
        int x=it[0];
        int y=it[1];
        if(x>y)swap(x,y);
        if(mp.find({x,y})!=mp.end()){
            vector<int> v;
            v.push_back(x);
            v.push_back(y);
            bridges.push_back(v);
        }
    }
    return bridges;
}


vector<vector<int> > Solution::solve(int A, vector<vector<int> > &B) {
        return bridges(A,B);
}