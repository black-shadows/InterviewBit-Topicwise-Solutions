int psum[1001][1001];
int range_sum(int xi, int xj, int yi, int yj)
{
    int ans = psum[yi][yj];
    if (xi > 0)
        ans -= psum[xi - 1][yj];
    if (xj > 0)
        ans -= psum[yi][xj - 1];
    if (xi > 0 and xj > 0)
        ans += psum[xi - 1][xj - 1];
    return ans;
}


int Solution::solve(vector<vector<int> > &matrix, int B) {
    int n = matrix.size(), m = matrix[0].size();
    if(n==1 and B==1) return matrix[0][0];
    
    // prefix sum
    psum[0][0] = matrix[0][0];
    for (int i = 1; i < n; i++)
        psum[i][0] = psum[i - 1][0] + matrix[i][0];
    for (int i = 1; i < m; i++)
        psum[0][i] = psum[0][i - 1] + matrix[0][i];
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + matrix[i][j];

    int ans = INT_MIN;
    for (int i = B-1; i < n; i++)
    {
        for (int j = B-1; j < m; j++)
        {
            int x=i-(B-1),y=j-(B-1);
            if(x>=0 and y>=0){
                int s=range_sum(x,y,i,j);
                ans=std::max(ans,s);
            }
        }
    }
    return ans;
}