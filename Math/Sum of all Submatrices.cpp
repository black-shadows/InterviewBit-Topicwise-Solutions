int Solution::solve(vector<vector<int> > &arr) 
{
    
    // Varialbe to store 
    // the required sum 
    
    int n = arr.size();
    
    int sum = 0; 
  
    // Nested loop to find the number  
    // of submatrices, each number belongs to 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) { 
  
            // Number of ways to choose 
            // from top-left elements 
            int top_left = (i + 1) * (j + 1); 
  
            // Number of ways to choose 
            // from bottom-right elements 
            int bottom_right = (n - i) * (n - j); 
            sum += (top_left * bottom_right * arr[i][j]); 
        } 
  
    return sum; 
    
}
