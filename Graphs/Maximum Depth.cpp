const int N = 1e5 + 10;
int n, q, val[N], mx = 0;
vector< int > adj[N];
set < int > lvl[N];

void dfs( int u, int v, int d ) {
    mx = max(mx, d);
    lvl[d].insert(val[u]);
    for( auto i: adj[u] ) {
        if( i == v ) continue;
        dfs(i, u, d+1);
    }
}

vector<int> Solution::solve(int A, vector<int> &B, vector<int> &C, vector<int> &D, vector<int> &E, vector<int> &F) {
    n = A;
    q = F.size();
    
    for( int i = 0; i <= n; i++) {
        adj[i].clear();
        lvl[i].clear();
        val[i+1] = D[i];
    }
    
    for( int i = 0; i < n-1; i++ ) {
        adj[B[i]].push_back(C[i]);
        adj[C[i]].push_back(B[i]);
    }
    
    mx = 0;
    dfs(1, 1, 0);
    vector< int > res;
    
    for( int i = 0; i < q; i++) {
        int l = E[i], x = F[i];
        l %= (mx+1);
        set< int >::iterator it = lvl[l].lower_bound(x);
        if( it == lvl[l].end() ) res.push_back(-1);
        else res.push_back(*it);
    }
    return res;
}