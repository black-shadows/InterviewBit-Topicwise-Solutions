int Solution::solve(vector<vector<int> > &A) {
    
    int n=A.size();
    int m=A[0].size();
    int ans=1;
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(A[i][j])
            A[i][j] = min(A[i-1][j], min(A[i][j-1],A[i-1][j-1]) )+1;
            ans=max(ans,A[i][j]);
        }
    }
    return ans*ans;
}
