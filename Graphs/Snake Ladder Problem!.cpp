unordered_map<int,int> mp;

int helper()
{
    bool *visited = new bool[100];
    for(int i = 0;i<100;i++)
    {
        visited[i] = false;
    }
    
    queue<int> q;
    q.push(0);
    visited[0] = true;
    int cou = 0;
    while(!q.empty())
    {
        int x = q.size();
        while(x--)
        {
            int tt = q.front();
            q.pop();
            
            if(tt == 99)
            return cou;
            
            for(int i = 1;i<=6;i++)
            {
                if(tt + i < 100)
                {
                    if(mp.count(i + tt) == 0)
                    {
                        if(!visited[i + tt])
                        {
                            visited[i + tt] = true;
                            q.push(i + tt);
                        }
                    }
                    else
                    {
                        if(!visited[mp[i + tt]])
                        {
                            visited[mp[i + tt]] = true;
                            q.push(mp[i + tt]);
                        }
                    }
                }
            }
            
        }
        cou++;
    }
    return -1;
}

int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B) {
    mp.clear();
    for(int i = 0;i<A.size();i++)
    {
        mp[A[i][0] - 1] = A[i][1] - 1;
    }
    
    for(int i = 0;i < B.size();i++)
    {
        mp[B[i][0] - 1] = B[i][1] - 1;
    }
    return helper();
}