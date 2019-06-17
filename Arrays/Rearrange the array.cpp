void rearrangeUtil(vector<int> &arr, int n, int i) 
{ 
    // 'val' is the value to be stored at 'arr[i]' 
    int val = -(i+1);  // The next value is determined 
                       // using current index 
    i = arr[i] - 1;  // The next index is determined 
                     // using current value 
  
    // While all elements in cycle are not processed 
    while (arr[i] > 0) 
    { 
        // Store value at index as it is going to be 
        // used as next index 
        int new_i = arr[i] - 1; 
  
        // Update arr[] 
        arr[i] = val; 
  
        // Update value and index for next iteration 
        val = -(i + 1); 
        i = new_i; 
    } 
} 

vector<int> Solution::solve(vector<int> &arr) 
{
    
    int n = arr.size();
    
    int i; 
    for (i=0; i<n; i++) 
        arr[i]++; 
  
    // Process all cycles 
    for (i=0; i<n; i++) 
    { 
       // Process cycle starting at arr[i] if this cycle is 
       // not already processed 
       if (arr[i] > 0) 
          rearrangeUtil(arr, n, i); 
    } 
  
    // Change sign and values of arr[] to get the original 
    //  values back, i.e., values in range from 0 to n-1 
    for (i=0; i<n; i++) 
          arr[i] = (-arr[i]) - 1; 
    
    return arr;
}
