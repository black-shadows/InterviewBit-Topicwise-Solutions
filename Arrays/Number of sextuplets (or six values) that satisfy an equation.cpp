// Returns count of 6 values from arr[] 
// that satisfy an equation with 6 variables 
int findSextuplets(vector<int> arr, int n) 
{ 
    // Generating possible values of RHS of the equation 
    int index = 0; 
    vector<int> RHS; 
    for (int i = 0; i < n; i++) 
      if (arr[i])  // Checking d should be non-zero. 
        for (int j = 0; j < n; j++) 
          for (int k = 0; k < n; k++) 
            RHS.push_back(arr[i] * (arr[j] + arr[k])); 
  
    // Sort RHS[] so that we can do binary search in it. 
    sort(RHS.begin(), RHS.end()); 
  
    // Generating all possible values of LHS of the equation 
    // and finding the number of occurances of the value in RHS. 
    int result = 0; 
    for (int i = 0; i < n; i++) 
    { 
        for (int j = 0; j < n; j++) 
        { 
            for(int k = 0; k < n; k++) 
            { 
                int val = arr[i] * arr[j] + arr[k]; 
                result += (upper_bound(RHS.begin(), RHS.end(), val) - lower_bound(RHS.begin(), RHS.end(), val)); 
            } 
        } 
    } 
  
    return result; 
}


int Solution::solve(vector<int> &A) 
{
    
    return findSextuplets(A, A.size());
    
}
