const int N = 100005; 
  
// Depths of Nodes 
vector<int> level(N); 
const int LG = 20; 
  
// Parent at every 2^i level 
vector<vector<int> > dp(LG, vector<int>(N)); 
  
// Maximum node at every 2^i level 
vector<vector<int> > mx(LG, vector<int>(N)); 
  
// Graph that stores destinations 
// and its weight 
vector<vector<pair<int, int> > > v(N); 
int n; 
  
// Function to traverse the nodes 
// using the Depth-First Search Traversal 
void dfs_lca(int a, int par, int lev) 
{ 
    dp[0][a] = par; 
    level[a] = lev; 
    for (auto i : v[a]) { 
  
        // Condition to check if its 
        // equal to its parent then skip 
        if (i.first == par) 
            continue; 
        mx[0][i.first] = i.second; 
  
        // DFS Recursive Call 
        dfs_lca(i.first, a, lev + 1); 
    } 
} 
  
// Function to find the ansector 
void find_ancestor() 
{ 
  
    // Loop to set every 2^i distance 
    for (int i = 1; i < LG; i++) { 
        // Loop to calculate for 
        // each node in the N-ary tree 
        for (int j = 1; j <= n; j++) { 
            dp[i][j] 
                = dp[i - 1][dp[i - 1][j]]; 
  
            // Storing maximum edge 
            mx[i][j] 
                = max(mx[i - 1][j], 
                      mx[i - 1][dp[i - 1][j]]); 
        } 
    } 
} 
  
int getMax(int a, int b) 
{ 
    // Swaping if node a is at more depth 
    // than node b because we will 
    // always take at more depth 
    if (level[b] < level[a]) 
        swap(a, b); 
  
    int ans = 0; 
  
    // Diffeence between the depth of 
    // the two given nodes 
    int diff = level[b] - level[a]; 
    while (diff > 0) { 
        int log = log2(diff); 
        ans = max(ans, mx[log][b]); 
  
        // Changing Node B to its 
        // parent at 2 ^ i distance 
        b = dp[log][b]; 
  
        // Subtracting distance by 2^i 
        diff -= (1 << log); 
    } 
  
    // Take both a, b to its 
    // lca and find maximum 
    while (a != b) { 
        int i = log2(level[a]); 
  
        // Loop to find the maximum 2^ith 
        // parent the is differnet 
        // for both a and b 
        while (i > 0 
               && dp[i][a] == dp[i][b]) 
            i--; 
  
        // Updating ans 
        ans = max(ans, mx[i][a]); 
        ans = max(ans, mx[i][b]); 
  
        // Changing value to its parent 
        a = dp[i][a]; 
        b = dp[i][b]; 
    } 
    return ans; 
} 
  
// Function to compute the Least 
// common Ansector 
void compute_lca() 
{ 
    dfs_lca(1, 0, 0); 
    find_ancestor(); 
} 
vector<int> Solution::solve(vector<vector<int> > &A, vector<vector<int> > &B) {
    int i;
    n = A.size() + 1;
    for(i=0;i<=n;i++) v[i].clear();
    for(i=0;i<A.size();i++)
    {
        v[A[i][0]].push_back(make_pair(A[i][1],A[i][2]));
        v[A[i][1]].push_back(make_pair(A[i][0],A[i][2]));
    }
    compute_lca();
    int q = B.size();
    vector<int> ans(q);
    for(i=0;i<q;i++)
    {
        ans[i] = getMax(min(B[i][0],B[i][1]),max(B[i][0],B[i][1]));
    }
    return ans;
}
