int Solution::solve(vector<vector<int> > &A) {
    int n=A.size(),m=A[0].size();
    int count[n][m];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(j==0)
             count[j][i]=A[j][i];
            else if(A[j][i]==1)
             count[j][i]=count[j-1][i]+1;
            else
             count[j][i]=0;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        sort(count[i],count[i]+m);
        int maxrow=count[i][0]*m;
        for(int j=1;j<m;j++){
            maxrow=max(maxrow,count[i][j]*(m-j));
        }
        ans=max(ans,maxrow);
    }
    return ans;
}