int Solution::solve(vector<vector<int> > &A) {
     if(A.size()==0 || A[0].size()==0) return 0;
    int dp[A.size()+1][A[0].size()+1];
    int n=A.size()+1,m=A[0].size()+1;
    for(int i=0;i<n;i++) 
        for(int j=0;j<m;j++) 
            dp[i][j]=0;
    for(int i=1;i<n;i++) 
        for(int j=1;j<m;j++) {
            dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            dp[i][j]+=A[i-1][j-1];
            //cout<<i<<' '<<j<<' '<<dp[i][j]<<"  ";
        }
    int ans=0;
    for(int i=0;i<n;i++)
     for(int j=i+1;j<n;j++) {
         int a[m];
         for(int k=0;k<m;k++) 
          {a[k] = dp[j][k]-dp[i][k];
           //cout<<a[k]<<' ';
          }
          //cout<<' ';
         sort(a,a+m);
         int c=1;
         for(int k=1;k<m;k++)
          if(a[k]==a[k-1])
           c++;
          else {
              ans+=(c*(c-1))/2;
              c=1;
          }
          ans+=(c*(c-1))/2;
          //cout<<ans<<' ';
     }
     return ans;
}