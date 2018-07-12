string Solution::solve(int x, int y, int n, int r, vector<int> &E, vector<int> &F) 
{
    int ans[x+1][y+1];
    
    for(int i=0;i<=x ;i++)
    {
        for(int j=0;j<=y ;j++)
        ans[i][j]=0;
    }
    
    for(int i=0;i<=x ; i++)
    {
        for(int j=0;j<=y ; j++)
        {
            for(int k=0;k<n ; k++)
            {
                if( sqrt( pow((E[k]-i),2) +  pow((F[k]-j),2) ) <= r )
                ans[i][j]=-1;
            }
            
        }
    }
    
    queue< pair<int,int> > q;
    
    
    pair<int,int> p;
    
    
    if(ans[0][0]==-1)
    return "NO";
    
    q.push({0,0});
    
    ans[0][0]=1;
    
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        
        int a=p.first;
        int b=p.second;
        
        if( a>0 && b>0 && ans[a-1][b-1]==0)
        {
            ans[a-1][b-1]=1;
            q.push({a-1,b-1});
        }
        
        if(a+1 <= x && b+1 <= y && ans[a+1][b+1]==0)
        {
            ans[a+1][b+1]=1;
            q.push({a+1,b+1});
        }
        
        if( a>0 && ans[a-1][b]==0)
        {
            ans[a-1][b]=1;
            
            q.push({a-1,b});
        }
        
        if(b>0 && ans[a][b-1]==0)
        {
            ans[a][b-1]=1;
            q.push({a,b-1});
        }
        
        if(a>0 && b+1<=y && ans[a-1][b+1]==0)
        {
            ans[a-1][b+1]=1;
            q.push({a-1,b+1});
        }
        
        if(b+1 <= y && ans[a][b+1]==0)
        {
            ans[a][b+1]=1;
            q.push({a,b+1});
        }
        
        if(a+1 <= x && b>0 && ans[a+1][b-1]==0)
        {
            ans[a+1][b-1]=1;
            q.push({a+1,b-1});
        }
        
        
        if(a+1<=x && ans[a+1][b]==0)
        {
            ans[a+1][b]=1;
            q.push({a+1,b});
        }
        
    }
        
        if(ans[x][y]==1)
        return "YES";
        else
        return "NO";
    
    
    
}