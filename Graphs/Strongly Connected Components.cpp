const int N =100005;
vector<int> g[N],r[N],scc[N],topsort,vis(N);
int c=0;

void clean(int n){
    for(int i=0; i<=n; ++i){
        g[i].clear();
        r[i].clear();
        scc[i].clear();
        vis[i]=0;
    }
    c=0;
    topsort.clear();
}

void make_graph(vector<vector<int> > &edges){
    for(auto &it:edges){
        int x=it[0];
        int y=it[1];
        g[x].push_back(y);
        r[y].push_back(x);
    }
}

void dfs0(int x){
    vis[x]=1;
    for(auto &it:g[x])
        if(!vis[it])
            dfs0(it);
    topsort.push_back(x);
}


void dfs1(int x){
    vis[x]=1;
    scc[c].push_back(x);
    for(auto &it:r[x])
        if(!vis[it])
            dfs1(it);
}

vector<vector<int> > StronglyConnectedComponents(int n,vector<vector<int> > &edges){
    clean(n);
    make_graph(edges);
    vector<vector<int> > stronglyConnectedComponents;

    for(int i=1; i<=n; ++i)
        if(!vis[i])
            dfs0(i);

    for(int i=0; i<=n; ++i)
        vis[i]=0;

    while(!topsort.empty()){
        int x=topsort.back();
        topsort.pop_back();
        if(!vis[x]){
            ++c;
            dfs1(x);
        }
    }

    for(int i=1; i<=c; ++i){
        sort(scc[i].begin(),scc[i].end());
        assert(scc[i].size()>0);
        stronglyConnectedComponents.push_back(scc[i]);
    }

    return stronglyConnectedComponents;
}


vector<vector<int> > Solution::solve(int A, vector<vector<int> > &B) {
    return StronglyConnectedComponents(A,B);
}