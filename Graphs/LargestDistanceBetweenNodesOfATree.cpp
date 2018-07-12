int Solution::solve(vector<int> &A) {
        vector<int> res1;
    vector<int> res2;
    res1.resize(A.size());
    res2.resize(A.size());
    for(int i=A.size()-1;i>0;i--){
        if(res1[A[i]]<max(res1[i],res2[i])+1){
            res2[A[i]]=max(res2[A[i]],res1[A[i]]);
            res1[A[i]]=max(res1[i],res2[i])+1;
        }
        else if(res2[A[i]]<max(res1[i],res2[i])+1)
            res2[A[i]]=max(res1[i],res2[i])+1;
    }
    int r=0;
    for(int i=0;i<A.size();i++){
        r=max(r,res1[i]+res2[i]);
    }
    return r;

}