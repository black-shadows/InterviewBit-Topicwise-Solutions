int Solution::solve(vector<int> &A, int B) 
{
    
    int total = 0;
    
    for(int i=0; i<A.size(); i++)
    {
        
        total = total + A[i];
        
    }
    
    sort(A.begin(), A.end());
    
    int first = 0;
    
    for(int i=0; i<B; i++)
    {
        
        first = first + A[i];
        
    }
    
    int last = 0;
    
    reverse(A.begin(), A.end());
    
    for(int i=0; i<B; i++)
    {
        
        last = last + A[i];
        
    }
    
    int tf = abs(total - 2*first);
    
    int tl = abs(total - 2*last);
    
    return max(tf, tl);
    
}
