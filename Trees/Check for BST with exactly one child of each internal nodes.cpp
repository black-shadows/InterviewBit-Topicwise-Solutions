string Solution::solve(vector<int> &pre) 
{
    
    // Initialize min and max using last two elements 
    int min, max, size = pre.size(); 
    if (pre[size-1] > pre[size-2]) 
    { 
        max = pre[size-1]; 
        min = pre[size-2];
    }
    else
    { 
        max = pre[size-2]; 
        min = pre[size-1]; 
    } 
  
  
    // Every element must be either smaller than min or 
    // greater than max 
    for (int i=size-3; i>=0; i--) 
    { 
        if (pre[i] < min) 
            min = pre[i]; 
        else if (pre[i] > max) 
            max = pre[i]; 
        else
            return "NO"; 
    } 
    return "YES"; 
    
}
