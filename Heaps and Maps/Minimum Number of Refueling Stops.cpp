int Solution::solve(int target, int startFuel, vector<int> &C, vector<int> &D) 
{
    int n = C.size();
    
    vector<vector<int>> stations(n, vector<int>(2));
    
    for(int i=0; i<C.size(); i++)
    {
        
        stations[i][0] = C[i];
        
        stations[i][1] = D[i];
        
    }

    int nowpos=startFuel;
    int counter=0,p=0;
    priority_queue<int>pq;
    while(1){
        while(p<(int)stations.size()&&stations[p][0]<=nowpos){
            pq.push(stations[p][1]);
            p++;
        }
        if(nowpos>=target)return counter;
        if(pq.empty())return -1;
        nowpos+=pq.top();pq.pop();
        counter++;
    }
    
}
