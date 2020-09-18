int Solution::solve(vector<vector<int> > &A) {
    
    int i,j,k,n;
    n = A.size();
    
    pair <int,int> p[n];
    
    int ans=1;
    
    for(i=0;i<n;i++){
        
        pair<int,int> pp;
        pp.first=A[i][1];
        pp.second=A[i][0];
        p[i]=pp;
        
    }
    
    sort(p,p+n);
    int last=p[0].first;
    
    
    for(i=1;i<n;i++)
    {
        
        if(p[i].second>last){
            ans++;
            last=p[i].first;
        }
    }
    return ans;
}
