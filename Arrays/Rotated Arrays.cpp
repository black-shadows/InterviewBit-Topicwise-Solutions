bool isRotated(vector<int> A, vector<int> B)
{
    
    int index = 0, count = 0, point = 0, n = B.size(), track = 0, flag = 0;
    
    for(int i=0; i<n; i++)
    {
        
        if(B[i] == A[0])
        {
            
            flag = 1;
            
            while(count != A.size())
            {
                
                if(B[i] == A[point])
                {
                    
                    i = (i + 1)%n;
                    
                    point++;
                    
                    track++;
                    
                }
                
                count++;
                
            }
            
        }
        
        if(flag)
        {
            
            break;
            
        }
        
    }
    
    if(track == B.size())
    {
        
        return true;
        
    }
    
    else
    {
        
        return false;
        
    }
    
}


int Solution::solve(vector<int> &A, vector<int> &B) 
{
    
    return isRotated(A, B);
    
}
