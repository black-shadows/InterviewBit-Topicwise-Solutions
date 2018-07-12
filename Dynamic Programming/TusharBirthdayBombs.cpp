vector<int> Solution::solve(int A, vector<int> &B) {
    
    vector<int> ans(0);
    if(B.size() == 0) 
        return ans;
    vector<int> mn(B.size());
    int curr_min = INT_MAX;
    
    for(int i=B.size()-1;i>=0;i--)
    {
        if(B[i]<curr_min)
            curr_min = B[i];
        mn[i] = curr_min;
    }
    
    int rem_shots = A/mn[0];
    
    if(rem_shots==0)
        return ans;
    int j=0;
    while(rem_shots)
    {
        if(A - B[j] >= (rem_shots-1)*mn[j] ) 
        {
            ans.push_back(j);
            rem_shots--;
            A -= B[j];
        }
        else
            j++;
    }
    return ans;
}