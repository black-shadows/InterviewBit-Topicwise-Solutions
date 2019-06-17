bool check(int num)
{
    
    while(num != 0)
    {
        
        int k = num%10;
        
        if(k == 1 || k == 2 || k == 3)
        {
            
            num = num/10;
            
            continue;
            
        }
        
        else
        {
            
            return false;
            
        }
        
    }
    
    return true;
    
}

vector<int> Solution::solve(int A) 
{
    

    vector<int> ans;
    
    for(int i=1; ; i++)
    {
        
        if(check(i) == true)
        {
            
            ans.push_back(i);
            
        }
        
        if(ans.size() == A || ans.size() == 12)
        {
            
            break;
            
        }
        
    }
    
    int prev_size = 3;
    
    int key = 2;
    
    while(A > ans.size())
    {
        
        int n = ans.size();
        
        int val = pow(10, key);
        
        for(int i = prev_size; i<n; i++)
        {
            
            for(int j=1; j<=3; j++)
            {
                
                ans.push_back(ans[i]*10 + j);
                
                if(ans.size() == A)
                {
                    
                    break;
                    
                }
                
            }
            
            if(ans.size() == A)
            {
                
                break;
                
            }
            
        }
        
        if(ans.size() == A)
        {
            
            break;
            
        }

        prev_size = n;
        
        key++;
        
    }
    
    return ans;
    
}
