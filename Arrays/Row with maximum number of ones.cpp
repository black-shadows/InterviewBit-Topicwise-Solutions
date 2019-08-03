int solveit(vector<vector<int> > &a){
    int n=a.size();
    int ans=0;
    int row =0,i,j;
    for (i=0,j=n-1; i<n&&j>0;i++){
        while (a[i][j]==1&&j>=0){
            row = i;
            j--;
        }
    }
    return row;
}

int Solution::solve(vector<vector<int> > &A) {
    return solveit(A);
    
}