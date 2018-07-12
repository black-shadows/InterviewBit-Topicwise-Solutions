vector<vector<string> > ans;
int min_dist;
string dest;
bool isAdjacent(string A,string B)
{
    int count=0;
    for(int i=0;i<A.length();i++)
    {
        if(A[i]!=B[i])
            count++;
        if(count>1)
            return false;
    }
    return ((count==1)?true:false);
}
void dfs(vector<string> path,string vertex,int dist,unordered_set<string> dict)
{
    if(dist>min_dist)
        return;
    if(vertex==dest)
    {
        if(dist==min_dist)
            ans.push_back(path);
        return;
    }
    dict.erase(vertex);
    for(auto it=dict.begin();it!=dict.end();++it)
        if(isAdjacent(vertex,*it))
        {
            path.push_back(*it);
            dfs(path,*it,dist+1,dict);
            path.pop_back();
        }
    dict.insert(vertex);
}
vector<vector<string> > Solution::findLadders(string start, string end, vector<string> &dict) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    min_dist=INT_MAX;dest=end;ans.clear();
    unordered_set<string> dictMap(dict.begin(),dict.end());
    dictMap.insert(end);
    queue<pair<string,int> > bfs_queue;
    unordered_map<string,bool> visited;
    visited[start]=true;
    bfs_queue.push(make_pair(start,0));
    while(!bfs_queue.empty())
    {
        pair<string,int> vertex=bfs_queue.front();
        bfs_queue.pop();
        if(vertex.first==end)
        {
            min_dist=vertex.second;
            break;
        }
        dictMap.erase(vertex.first);
        for(auto it=dictMap.begin();it!=dictMap.end();++it)
            if(isAdjacent(vertex.first,*it))
                bfs_queue.push(make_pair(*it,vertex.second+1));
    }
    if(min_dist==INT_MAX)
        return ans;
    vector<string> path;
    path.push_back(start);
    dictMap.clear();
    dictMap.insert(dict.begin(),dict.end());
    dictMap.insert(end);
    dfs(path,start,0,dictMap);
    return ans;
}
