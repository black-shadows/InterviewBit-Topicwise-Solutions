int Solution::solve(vector<int> &A) 
{
    
    unordered_map<long long int, int> hash;
    
    long long int sum = 0;
    
    bool b = false;
    
    for(int i=0; i<A.size(); i++)
    {
        
        sum = sum + A[i];
        
        if(hash.find(sum) == hash.end())
        {
            
            hash[sum] = 1;
            
        }
        
        else
        {
            
            b = true;
            
            break;
            
        }
        
    }
    
    return b ? 1 : 0;
    
}
