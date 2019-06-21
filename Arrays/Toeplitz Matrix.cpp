bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    int n=matrix.size();
    int m=matrix[0].size();
    if(n<=1||m<=1)
        return true;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(i+1<n&&j+1<m){
                if(matrix[i+1][j+1]!=matrix[i][j])
                    return false;
            }
        }
    }
    return true;
}

int Solution::solve(vector<vector<int> > &A) {
    if(isToeplitzMatrix(A))
        return 1;
    return 0;
}