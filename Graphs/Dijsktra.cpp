#define pi pair<int,int>
const int N =100005;
vector<pi> g[N];
int vis[N];

const int inf=1000000000;

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
        g[x].push_back(make_pair(w,y));
        g[y].push_back(make_pair(w,x));
    }
}

vector<int> dijsktra(int n,vector<vector<int> > &edges,int source){
    clean(n);
    make_graph(edges);
    vector<int> distance(n,inf);
    priority_queue<pi,vector<pi>, greater<pi> > q;
    distance[source]=0;
    q.push(make_pair(0,source));
    while(!q.empty()){
        pi p=q.top();
        int x=p.second;
        q.pop();
        if(vis[x])
            continue;
        vis[x]=1;
        for(int i=0; i<g[x].size(); ++i){
            int y=g[x][i].second;
            int w=g[x][i].first;
            if(distance[x]+w<distance[y]){
                distance[y]=distance[x]+w;
                q.push(make_pair(distance[y],y));
            }
        }
    }
    for(int i=0; i<n; ++i){
        if(distance[i]==inf)
            distance[i]=-1;
    }
    return distance;
}

vector<int> Solution::solve(int A, vector<vector<int> > &B, int C) {
    return dijsktra(A,B,C);
}