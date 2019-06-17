int Solution::solve(vector<int> &A, vector<int> &B) 
{
    
    unordered_map<int, int> hash;
    
    int count = 0, cnt = 0;
    
    for(int i=0; i<B.size(); i++)
    {
        
        if(B[i] != 0)
        {
            
            hash[i+1] = hash[i+1] - B[i];
            
            cnt = cnt + B[i];
            
        }
        
    }
    
    int l = 0, r = 0;
    
    int ans = -1;
    
    for(; r<A.size(); r++)
    {
        
        if(hash[A[r]]++ < 0)
        {
            
            count++;
            
        }
        
        while(count == cnt)
        {
            
            if(ans == -1 || ans > r - l + 1)
            {
                
                ans = r - l + 1;
                
            }
            
            if(!hash[A[l++]]--)
            {
                
                count--;
                
            }
            
        }
        
    }
    
    return (ans - cnt) > 0 ? (ans - cnt) : -1;
    
}
