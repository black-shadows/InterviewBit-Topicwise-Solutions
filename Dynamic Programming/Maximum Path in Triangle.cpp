int Solution::solve(vector<vector<int> > &A) {
int m=A.size();
int n=A[0].size();
    for(int i=A.size()-2;i>=0;i--)
    {
        for(int j=0;j<i+1;j++)
        {A[i][j]+=max(A[i+1][j],A[i+1][j+1]);
            
        }
    }
    return A[0][0];
}