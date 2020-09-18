vector<int> Solution::solve(vector<vector<int> > &A) {
    int k=A.size(),n=A[0].size();
    vector<int> ans;
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<n;j++)
        {
            
            ans.push_back(A[i][j]);
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}