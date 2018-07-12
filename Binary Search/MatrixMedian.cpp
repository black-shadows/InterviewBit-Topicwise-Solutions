int Solution::findMedian(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    int k = n * m / 2;
    
    vector<int> A_copy;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            A_copy.push_back(A[i][j]);
    A.clear();
    
    std::nth_element(A_copy.begin(), A_copy.begin() + k, A_copy.end());
    return A_copy[k];
}