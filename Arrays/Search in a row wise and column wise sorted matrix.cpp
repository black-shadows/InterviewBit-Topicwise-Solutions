int Solution::solve(vector<vector<int> > &matrix, int target) 
{
    
 int i = 0;
 int j = matrix[0].size() - 1;
 
 while(i < matrix.size() && j >= 0) {
     if(matrix[i][j] == target)
         return ((i+1) * 1009 + j + 1);
     
     if(matrix[i][j] < target)
         i++;
     else
         j--;
 }
 
 return -1;
    
}
