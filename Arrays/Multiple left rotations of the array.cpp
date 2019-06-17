vector<int> leftRotate(vector<int> arr, int n, int k) 
{ 
    
    vector<int> result;
    // Print array after k rotations 
    for (int i = k; i < k + n; i++)
        result.push_back(arr[i%n]);
        
    return result;
}

vector<vector<int> > Solution::solve(vector<int> &A, vector<int> &B) 
{
    
    vector<vector<int> > ans;
    
    for(int i=0; i<B.size(); i++)
    {
        
        ans.push_back(leftRotate(A, A.size(), B[i]));
        
    }
    
    return ans;
    
}
