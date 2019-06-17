int Solution::solve(vector<int> &arr) 
{
    
    int n = arr.size();
    
    int ans = 0;
    
    // Hash to store all element of array 
    unordered_set<int> s; 
    for (int i = 0; i < n; i++) 
        s.insert(arr[i]); 
  
    //bool found = false; 
    for (int i = 0; i < n; i++) { 
        for (int j = i + 1; j < n; j++) { 
            // Check sum already exists or not 
            if (s.find(arr[i] + arr[j]) != s.end()) { 
                ans++;
                //found = true; 
            } 
        } 
    } 
  
    return ans; 
    
}
