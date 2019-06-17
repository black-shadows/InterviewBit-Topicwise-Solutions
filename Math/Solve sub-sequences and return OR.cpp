int Solution::solve(vector<int> &arr) 
{
    
    int result = arr[0]; 
    for (int i = 1; i < arr.size(); i++) 
        result = __gcd(arr[i], result); 
    
    return result == 1 ? 1 : 0;    
}
