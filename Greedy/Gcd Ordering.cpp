vector<int> Solution::solve(vector<int> &A) 
{
    
    sort(A.begin(), A.end());
    
    if(A.size() > 2)
    {
        
        for(int i=2; i<A.size(); i++)
        {
            
            if(A[i] != A[i-1] + __gcd(A[i-1], A[i-2]))
            {
                
                vector<int> ans;
                
                ans.push_back(-1);
                
                return ans;
                
            }
            
        }
        
        return A;  
            
    }
    
    else
    {
        
       if(A.size() == 2)
       {
           
           if(A[0] > A[1])
           {
               
               return A;
               
           }
           
           else
           {
               
               swap(A[0], A[1]);
               
               return A;
               
           }
           
       }
       
       else
       {
           
           return A;
           
       }
        
    }
    
}
