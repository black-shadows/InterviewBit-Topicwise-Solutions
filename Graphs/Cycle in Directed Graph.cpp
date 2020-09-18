bool findCycle(int cur, vector<vector<int>>&adj, vector<bool>&visited, vector<bool>&recVisited){
    visited[cur] = true;
    recVisited[cur] = true;
    
    for(auto itr: adj[cur]){
        if(!visited[itr]){
            if(findCycle(itr, adj, visited, recVisited))return true;
        }
        // if it is visited then check in recVisited
        else if(recVisited[itr]){
            return true;
        }
    }
    recVisited[cur] = false;
    return false;
}
int Solution::solve(int v, vector<vector<int> > &B) {
    
    vector<vector<int>>adj(v+1);
    for(int i = 0; i < B.size(); ++i){
        adj[B[i][0]].push_back(B[i][1]);
    }
    vector<bool>visited(v+1);
    vector<bool>recVisited(v+1);
    
    for(int i = 1; i <= v; ++i){
        if(!visited[i]){
            if(findCycle(i, adj, visited, recVisited)){
                return true;
            }
        }
    }
    return false;
}