const int N =100005;
vector<int> graph[N];


void clean(int n){
    for(int i=0; i<=n; ++i)
        graph[i].clear();
}

void make_graph(int n,vector<vector<int> > &edges){
    clean(n);
    for(int i=0; i<edges.size();++i){
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }
}

bool isBipartite(int n) {
    if(!n)
        return true;
    int color[n];
    memset(color,-1,sizeof color);
    queue<int> q;
    for(int i=0; i<n; ++i){
        if(color[i]!=-1)
            continue;
        color[i]=1;
        q.push(i);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(auto &it:graph[x]){
                if(color[it]==-1){
                    color[it]=color[x]^1;
                    q.push(it);
                }
                else if(color[it]==color[x])
                    return false;
                }
        }
    }
    return true;
}


int Solution::solve(int A, vector<vector<int> > &B) {
    make_graph(A,B);
    if(isBipartite(A))
        return 1;
    return 0;
}