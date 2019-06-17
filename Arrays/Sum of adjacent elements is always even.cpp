int Solution::solve(vector<int> &arr) 
{
    
    int countOdd = 0, n = arr.size(); 
  
    // Stores the new value 
    for (int i = 0; i < n; i++) 
  
        // Count odd numbers 
        if (arr[i] % 2) 
            countOdd++; 
  
    // Return the minimum of even and 
    // odd count 
    return min(countOdd, n - countOdd);
    
}