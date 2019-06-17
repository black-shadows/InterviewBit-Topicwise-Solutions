int Solution::solve(vector<vector<int> > &matrix) 
{
    
    int m = matrix.size();
    if (m == 0) return 0;
    int n = matrix[0].size();
    
    vector<int> height (n, 0);
    vector<int> left (n, 0);
    vector<int> right (n, n - 1);
    
    int maxA = INT_MIN;
    for (int i = 0 ; i < m; ++i){
        int current_left = 0;
        int current_right = n - 1;
        for (int j = 0; j < n; ++j){
            if (matrix[i][j] == 0){
                height[j] = 0;
            }else{
                height[j]++;
            }
        }
        for (int j = 0; j < n; ++j){
            if (matrix[i][j] == 0){
                left[j] = 0; 
                current_left = j + 1;
            }else{
                left[j] = max(left[j], current_left);
            }
        } 
        for (int j = n - 1; j >= 0; --j){
            if (matrix[i][j] == 0){
                right[j] = n - 1; 
                current_right = j - 1;
            }else{
                right[j] = min(right[j], current_right);
            }
        }
        for (int j = 0; j < n; ++j){
            if (maxA < (right[j] - left[j] + 1) * height[j]){
                maxA = (right[j] - left[j] + 1) * height[j];
            }
        }
    }
    return maxA;
    
}
