vector<int> Solution::solve(vector<int> &arr, int sum) 
{
    
    /* Initialize curr_sum as value of first element 
   and starting point as 0 */
   
   vector<int> ans;
   
   int n = arr.size();
   
    int curr_sum = arr[0], start = 0, i; 
  
    /* Add elements one by one to curr_sum and if the curr_sum exceeds the 
       sum, then remove starting element */
    for (i = 1; i <= n; i++) 
    { 
        // If curr_sum exceeds the sum, then remove the starting elements 
        while (curr_sum > sum && start < i-1) 
        { 
            curr_sum = curr_sum - arr[start]; 
            start++; 
        } 
  
        // If curr_sum becomes equal to sum, then return true 
        if (curr_sum == sum) 
        { 
            for(int j = start; j<=i-1; j++)
            {
                
                ans.push_back(arr[j]);
                
            }
            return ans; 
        } 
  
        // Add this element to curr_sum 
        if (i < n) 
          curr_sum = curr_sum + arr[i]; 
    } 
    
    ans.push_back(-1);
  
    return ans;
    
}
