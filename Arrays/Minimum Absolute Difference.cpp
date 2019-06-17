int Solution::solve(vector<int> &arr) 
{
    
    int n = arr.size();
    
    sort(arr.begin(), arr.end());
   // Initialize difference as infinite 
   int diff = INT_MAX; 
  
   // Find the min diff by comparing adjacent 
   // pairs in sorted array 
   for (int i=0; i<n-1; i++) 
      if (arr[i+1] - arr[i] < diff) 
          diff = arr[i+1] - arr[i]; 
  
   // Return min diff 
   return diff; 
    
}
