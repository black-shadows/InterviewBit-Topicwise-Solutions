int Solution::solve(vector<int> &A) 
{
    
    stack<int> C;
    
    vector<int> B;
    
    for(int i=0; i<A.size(); i++)
    {
        
        if(B.empty())
        {
            
            B.push_back(A[0]);
            
        }
        
        else
        {
            
            if(A[i] > B[B.size() - 1])
            {
                
                C.push(A[i]);
                
            }
            
            else
            {
                
                B.push_back(A[i]);
                
            }
            
        }
        
    }
    
    while(!C.empty())
    {
        
        B.push_back(C.top());
        
        C.pop();
        
    }
    
    bool b = true;
    
    for(int i=0; i<B.size() - 1; i++)
    {
        
        if(B[i+1] < B[i])
        {
            
            b = false;
            
        }
        
    }
    
    return b;
    
}
