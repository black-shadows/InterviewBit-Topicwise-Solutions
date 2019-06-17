int findPeakUtil(vector<int> arr, int low, int high, int n) 
{ 
    // Find index of middle element 
    int mid = low + (high - low)/2;  /* (low + high)/2 */
  
    // Compare middle element with its neighbours (if neighbours exist) 
    if ((mid == 0 || arr[mid-1] <= arr[mid]) && 
            (mid == n-1 || arr[mid+1] <= arr[mid])) 
        return mid; 
  
    // If middle element is not peak and its left neighbour is greater  
    // than it, then left half must have a peak element 
    else if (mid > 0 && arr[mid-1] > arr[mid]) 
        return findPeakUtil(arr, low, (mid -1), n); 
  
    // If middle element is not peak and its right neighbour is greater 
    // than it, then right half must have a peak element 
    else return findPeakUtil(arr, (mid + 1), high, n); 
} 

int Solution::solve(vector<int> &A) 
{
    
     return A[findPeakUtil(A, 0, A.size()-1, A.size())]; 
    
}
