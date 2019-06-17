vector<int> Solution::solve(vector<int> &arr) 
{
    
    int n = arr.size();
    
    vector<int> ans;
    
      /* Allocate memory for temporary arrays left[] and right[] */
    int *left = new int[sizeof(int)*n];  
    int *right = new int[sizeof(int)*n]; 
      
    /* Allocate memory for the product array */
    int *prod = new int[sizeof(int)*n]; 
      
    int i, j;  
      
    /* Left most element of left array is always 1 */
    left[0] = 1;  
      
    /* Rightmost most element of right array is always 1 */
    right[n - 1] = 1;  
      
    /* Construct the left array */
    for(i = 1; i < n; i++)  
        left[i] = arr[i - 1] * left[i - 1];  
      
    /* Construct the right array */
    for(j = n - 2; j >= 0; j--)  
        right[j] = arr[j + 1] * right[j + 1];  
      
    /* Construct the product array using  
        left[] and right[] */
    for (i = 0; i < n; i++)  
        prod[i] = left[i] * right[i];  
      
    /* print the constructed prod array */
    for (i = 0; i < n; i++)  
        ans.push_back(prod[i]);  
      
    return ans;  
    
}
