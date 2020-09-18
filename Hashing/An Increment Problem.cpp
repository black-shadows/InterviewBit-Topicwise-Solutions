vector<int> Solution::solve(vector<int> &A) {
    vector<int> res;
    for(int i=0;i<A.size();i++)
    {
        auto it=find(res.begin(),res.end(),A[i]);
        if(it!=res.end())
        {
            (*it)++;
            res.push_back(A[i]);
        }
        else
        {
            res.push_back(A[i]);
        }
    }
    return res;
}