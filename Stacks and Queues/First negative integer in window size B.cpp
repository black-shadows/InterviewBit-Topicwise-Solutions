vector<int> printFirstNegativeInteger(vector<int> arr, int n, int k) 
{ 
    // A Double Ended Queue, Di that will store indexes of  
    // useful array elements for the current window of size k. 
    // The useful elements are all negative integers. 
    deque<int>  Di; 
    
    vector<int> ans;
   
    /* Process first k (or first window) elements of array */
    int i; 
    for (i = 0; i < k; i++) 
        // Add current element at the rear of Di 
        // if it is a negative integer 
        if (arr[i] < 0) 
            Di.push_back(i); 
      
    // Process rest of the elements, i.e., from arr[k] to arr[n-1] 
    for ( ; i < n; i++) 
    { 
        // if Di is not empty then the element at the 
        // front of the queue is the first negative integer 
        // of the previous window 
        if (!Di.empty()) 
            ans.push_back(arr[Di.front()]); 
          
        // else the window does not have a 
        // negative integer 
        else
            ans.push_back(0); 
   
        // Remove the elements which are out of this window 
        while ( (!Di.empty()) && Di.front() < (i - k + 1)) 
            Di.pop_front();  // Remove from front of queue 
   
        // Add current element at the rear of Di 
        // if it is a negative integer 
        if (arr[i] < 0) 
            Di.push_back(i); 
    } 
   
    // Print the first negative  
    // integer of last window 
    if (!Di.empty()) 
           ans.push_back(arr[Di.front()]);  
    else
        ans.push_back(0);
        
    return ans;
      
} 


vector<int> Solution::solve(vector<int> &A, int B) 
{
    
    return printFirstNegativeInteger(A, A.size(), B);
    
}
