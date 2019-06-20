int MatrixMultiplicationCost(vector<int> &A) {
    int n=A.size();
    int m[n][n];
    int i, j, k, L, q;
    for (i=1; i<n; i++)
        m[i][i] = 0;
    for (L=2; L<n; L++) {
        for (i=1; i<n-L+1; i++) {
            j = i+L-1;
            m[i][j] = INT_MAX;
            for (k=i; k<=j-1; k++){
                q = m[i][k] + m[k+1][j] + A[i-1]*A[k]*A[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
    assert(m[1][n-1]<=INT_MAX&&m[1][n-1]>=0);
    return m[1][n-1];
}

int Solution::solve(vector<int> &A) {
    return MatrixMultiplicationCost(A);
}