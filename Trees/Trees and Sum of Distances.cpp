const int MAXN = 1e4 + 10;
vector<int> graph[MAXN], res, cnt;
int n;

void reset(){
    for(int i = 0; i < MAXN; i++)
        graph[i].clear();
    res.resize(n);
    cnt.resize(n);
    for(int i = 0; i < n; i++){
        res[i] = 0;
        cnt[i] = 1;
    }
}

void dfs(int node, int par){
    for(int u : graph[node]){
        if(u != par){
            dfs(u, node);
            cnt[node] += cnt[u];
            res[node] += res[u] + cnt[u];
        }
    }
}

void dfs2(int node, int par){
    for(int u : graph[node]){
        if(u != par){
            res[u] = res[node] - cnt[u] + n - cnt[u];
            dfs2(u, node);
        }
    }
}

vector<int> solveit(vector<vector<int> > &A){
    n = A.size()+1;
    reset();
    for(int i = 0; i < A.size(); i++){
        graph[A[i][0]].push_back(A[i][1]);
        graph[A[i][1]].push_back(A[i][0]);
    }
    dfs(0, -1);
    dfs2(0, -1);
    return res;
}
vector<int> Solution::solve(vector<vector<int> > &A) {
    return solveit(A);
}

