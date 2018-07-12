int isCyclic(vector<vector<int> > &graph, int src, 
             vector<bool> &visited, vector<bool> &recStack)
{
    if (!visited[src])
    {
        visited[src] = true;
        recStack[src] = true;
        
        for (int i = 0; i < graph[src].size(); i++)
        {
            int dest = graph[src][i];
            
            if (!visited[dest] && isCyclic(graph, dest, visited, recStack))
            {
                return 1;
            }
            else if (recStack[dest])
            {
                return 1;
            }
        }
    }
    
    recStack[src] = false;
    
    return 0;
}

int Solution::solve(int A, vector<int> &B, vector<int> &C) 
{
    if(B.size()>=A)
        return 0;
    else 
        return 1;
        
    if (!A)
    {
        return 0;
    }
    
    vector<vector<int> > graph(A+1, vector<int>());
    
    int i = 0, size = min(B.size(), C.size());
    for (i = 0; i < size; i++)
    {
        graph[B[i]].push_back(C[i]);
    }
    
    vector<bool> visited(A+1, false);
    vector<bool> recStack(A+1, false);
    
    for (i = 1; i < size; i++)
    {
        if (!visited[i] && isCyclic(graph, i, visited, recStack))
        {
            return 0;
        }
    }
    
    return 1;
}
