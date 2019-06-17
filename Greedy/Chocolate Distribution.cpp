int Solution::solve(vector<int> &arr, int m) 
{
    
    // if there are no chocolates or number 
    
    int n = arr.size();
    
    // of students is 0 
    if (m==0 || n==0) 
        return 0; 
  
    // Sort the given packets 
    sort(arr.begin(), arr.end()); 
  
    // Number of students cannot be more than 
    // number of packets 
    if (n < m) 
       return -1; 
  
    // Largest number of chocolates 
    int min_diff = INT_MAX; 
  
    // Find the subarray of size m such that 
    // difference between last (maximum in case 
    // of sorted) and first (minimum in case of 
    // sorted) elements of subarray is minimum. 
    int first = 0, last = 0; 
    for (int i=0; i+m-1<n; i++) 
    { 
        int diff = arr[i+m-1] - arr[i]; 
        if (diff < min_diff) 
        { 
            min_diff = diff; 
            first = i; 
            last = i + m - 1; 
        } 
    } 
    return (arr[last] - arr[first]);
    
}
