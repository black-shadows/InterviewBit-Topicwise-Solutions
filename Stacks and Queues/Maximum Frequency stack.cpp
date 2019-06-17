unordered_map<int, int> freq;
unordered_map<int, stack<int>> m;

void push(int x, int &maxfreq) {
    maxfreq = max(maxfreq, ++freq[x]);
    m[freq[x]].push(x);
}

int pop(int &maxfreq) {
    int x = m[maxfreq].top();
    m[maxfreq].pop();
    if (!m[freq[x]--].size()) maxfreq--;
    return x;
}

vector<int> Solution::solve(vector<vector<int> > &A) 
{
    
    vector<int> ans;
    
    freq.clear();
    
    m.clear();
    
    int maxfreq = 0;
    
    for(int i=0; i<A.size(); i++)
    {
        
        if(A[i][0] == 1)
        {
            
            ans.push_back(-1);
            
            push(A[i][1], maxfreq);
            
        }
        
        else
        {
            
            ans.push_back(pop(maxfreq));
            
        }
        
    }
    
    return ans;
    
}
