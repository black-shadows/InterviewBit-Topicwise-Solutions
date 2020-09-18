vector<int>adjList[100005];
bool visit[100005];
int count = 0;

int dfs(int u, int& res) 
{ 
    visit[u] = true; 
    int currComponentNode = 0; 
   
    for (int i = 0; i < adjList[u].size(); i++) 
    { 
        int v = adjList[u][i]; 
         
            int subtreeNodeCount = dfs(v, res); 
            if (subtreeNodeCount % 2 == 0) 
                res++;  
            else
                currComponentNode += subtreeNodeCount; 
         
    } 
  
    return (currComponentNode + 1); 
} 
  
int Solution::solve(int A, vector<vector<int> > &B) {
    
    for(int i = 0; i <= A; i++)
        adjList[i].clear();
        
    for(int i = 0; i < B.size(); i++)
        adjList[B[i][0]].push_back(B[i][1]);
        
    for (int i = 0; i <= A; i++) 
        visit[i] = false; 
  
    int res = 0;
    dfs(1, res); 
    return res; 
}