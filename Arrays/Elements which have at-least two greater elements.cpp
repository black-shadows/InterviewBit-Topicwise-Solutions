vector<int> Solution::solve(vector<int> &arr) 
{
    
    vector<int> ans;
    
    int n = arr.size();
    
    int first = INT_MIN,  
        second = INT_MIN; 
    for (int i = 0; i < n; i++) 
    { 
        /* If current element is smaller  
        than first then update both first  
        and second */
        if (arr[i] > first) 
        { 
            second = first; 
            first = arr[i]; 
        } 
  
        /* If arr[i] is in between first  
        and second then update second */
        else if (arr[i] > second) 
            second = arr[i]; 
    } 
  
    for (int i = 0; i < n; i++) 
        if (arr[i] < second) 
            ans.push_back(arr[i]);
    
    return ans;
}
