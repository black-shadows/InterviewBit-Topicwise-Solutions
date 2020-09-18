vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    vector<bool> a(100001,false) , b(100001,false) , c(100001,false);
    
    for(auto i:A)
        a[i]=true;
    for(auto i:B)
        b[i]=true;
    for(auto i:C)
        c[i]=true;
    
    vector<int> res;
    for(int i=1;i<100001;i++)
    {
        if((a[i]+b[i]+c[i]) > 1)
            res.push_back(i);
    }
    return res;
}