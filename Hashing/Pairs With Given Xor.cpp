int Solution::solve(vector<int> &A, int B) {
    unordered_map<int,int>m(A.size());
    int ans=0;
    for(int i=0;i<A.size();i++){
        int j=A[i];
        int k=A[i]^B;
        if(m.find(k)!=m.end()){
            ans++;
        }
        else{
            m[j]=i;
        }
    }
    return ans;
}