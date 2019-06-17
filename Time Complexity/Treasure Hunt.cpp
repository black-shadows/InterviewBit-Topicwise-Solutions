const int id[8]={-1,0,1,0,0,-1,0,1};
int search(vector< string > & grid , vector < vector < vector<int> > >& dp, int si, int sj, int s, int S)
{ 
    if (dp[si][sj][s]!=-2) 
    return dp[si][sj][s]; 
    if (s==S) return dp[si][sj][s]=0; 
    int m=grid.size(), n=grid[0].size(); 
    vector < vector < bool > > v(m, vector<bool>(n, false)); 
    v[si][sj]=true; 
    queue < pair < int, int > > q; 
    q.push({si*n+sj, 0}); 
    int ans=100000000; 
    while (!q.empty())
    { 
        int i=q.front().first/n, j=q.front().first%n, d=q.front().second; 
        q.pop(); 
        for (int k=0;k<8;k+=2)
        { 
            int ni=id[k]+i, nj=id[k+1]+j; 
            if (ni>=0&&ni<m&&nj>=0&&nj<n&&!v[ni][nj]&&grid[ni][nj]!='#')
            { 
                v[ni][nj]=true; 
                if (grid[ni][nj]>='A'&&grid[ni][nj]<='F')
                { 
                    if (!(s&(1<<(grid[ni][nj]-'A')))) continue; 
                }
                else if(grid[ni][nj]>='a'&&grid[ni][nj]<='f')
                { 
                    if (!(s&(1<<(grid[ni][nj]-'a'))))
                    { 
                        int next=search(grid, dp, ni, nj, s|(1<<(grid[ni][nj]-'a')), S); 
                        if (next!=-1)
                        { 
                            ans=min(ans, next+d+1); 
                        } 
                        continue; 
                    } 
                } 
                q.push({ni*n+nj, d+1}); 
                
            } 
            
        } 
        
    } 
    
    return dp[si][sj][s]=ans==100000000?-1:ans; 
}

int shortestPathAllKeys(vector<string>& grid) {
    int m=grid.size(), n=grid[0].size(), s=0, si, sj;
    for (int i=0;i<m;++i)
        for (int j=0;j<n;++j) {
            s+=grid[i][j]>='a'&&grid[i][j]<='f';
            if (grid[i][j]=='@') si=i, sj=j;
        }
    vector < vector < vector <int > > > dp(m, vector<vector<int > >(n, vector<int>(1<<s, -2)));
    return search(grid,dp,si,sj,0,(1<<s)-1);
}

int Solution::solve(vector<string> &A) 
{
    
    return shortestPathAllKeys(A);
    
}
