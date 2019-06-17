int mod = 1000000007;

vector<int> Solution::solve(int A, vector<int> &B) 
{
    
    vector<int> ans;
    
    map<int, pair<int, int>> hash;
    
    hash[B[0]] = make_pair(1, A);
    
    ans.push_back(1 + A);
    
    int count = 1 + A;
    
    for(int i=1; i<B.size(); i++)
    {
        
        auto ite = hash.find(B[i]);
        
        if(hash.find(B[i]) != hash.end())
        {
            
            //count = count + (ite->second).first + (ite->second).second;
            
            ans.push_back(count);
            
            continue;
            
        }
        
        hash[B[i]] = make_pair(1, A);
        
        auto it = hash.find(B[i]);
        
        auto itp = prev(it);
        
        auto itn = next(it);
        
        if(itp != hash.end())
        {
            
            count = count - (itp->second).second;
            
            (itp->second).second = B[i] - 1;
            
            (it->second).first = itp->first + 1;
            
            count = (count%mod + itp->first + B[i])%mod;
            
        }
        
        else
        {
            
            count = (count%mod + 1)%mod;
            
        }
        
        if(itn != hash.end())
        {
            
            count = count - (itn->second).first;
            
            (itn->second).first = B[i] + 1;
            
            (it->second).second = itn->first - 1;
            
            count = (count%mod + itn->first + B[i])%mod;
            
        }
        
        else
        {
            
            count = (count%mod + A)%mod;
            
        }
        
        ans.push_back(count%mod);
        
    }
    
    return ans;
    
}
