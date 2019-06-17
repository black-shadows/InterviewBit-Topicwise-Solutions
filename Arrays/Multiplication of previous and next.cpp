vector<int> Solution::solve(vector<int> &arr) 
{
    
    // Nothing to do when array size is 1 
    
    int n = arr.size();    
    
    if (n <= 1) 
      return arr; 
  
    // store current value of arr[0] and update it 
    int prev = arr[0]; 
    arr[0] = arr[0] * arr[1]; 
  
    // Update rest of the array elements 
    for (int i=1; i<n-1; i++) 
    { 
        // Store current value of next interation 
        int curr = arr[i]; 
  
        // Update current value using previos value 
        arr[i] = prev * arr[i+1]; 
  
        // Update previous value 
        prev = curr; 
    } 
  
    // Update last array element 
    arr[n-1] = prev * arr[n-1]; 
    
    return arr;
}
