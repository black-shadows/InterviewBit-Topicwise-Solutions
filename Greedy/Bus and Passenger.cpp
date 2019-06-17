vector<int> Solution::solve(vector<int> &A, string B) 
{
    
    unordered_map<int, int> hash;
    
    for(int i=0; i<A.size(); i++)
    {
        
        hash[A[i]] = i+1;
        
    }
    
    sort(A.begin(), A.end());
    
    stack<int> s;
    
    vector<int> ans, result;
    
    int j = 0;
    
    for(int i=0; i<B.length(); i++)
    {
        
        if(B[i] == '0')
        {
            
            ans.push_back(A[j]);
            
            s.push(A[j]);
            
            j++;
            
        }
        
        else
        {
            
            ans.push_back(s.top());
            
            s.pop();
            
        }
        
    }
    
    for(int i=0; i<ans.size(); i++)
    {
        
        result.push_back(hash[ans[i]]);
        
    }
    
    return result;
    
}
