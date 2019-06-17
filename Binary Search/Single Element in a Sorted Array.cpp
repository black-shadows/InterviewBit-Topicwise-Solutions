void search(vector<int> arr, int low, int high, int &ans) 
{ 
     // Base cases 
    if (low > high) 
       return; 
  
    if (low==high) 
    { 
        ans = arr[low];
        
        return;
    } 
  
    // Find the middle point 
    int mid = (low + high) / 2; 
  
    // If mid is even and element next to mid is 
    // same as mid, then output element lies on 
    // right side, else on left side 
    if (mid%2 == 0) 
    { 
        if (arr[mid] == arr[mid+1]) 
            search(arr, mid+2, high, ans); 
        else
            search(arr, low, mid, ans); 
    } 
    else  // If mid is odd 
    { 
        if (arr[mid] == arr[mid-1]) 
            search(arr, mid+1, high, ans); 
        else
            search(arr, low, mid-1, ans); 
    } 
} 

int Solution::solve(vector<int> &A) 
{
    
    int ans = 0;
    
    search(A, 0, A.size()-1, ans);
    
    return ans;
    
}
