vector<int> Solution::solve(vector<int> &A) {
    vector<int> ans;
    int soldier=A[A.size()-1];
    ans.push_back(soldier);
    for(int i=A.size()-2;i>=0;i--){
        if(A[i]>soldier){
            ans.push_back(A[i]);
        }
        soldier=max(soldier,A[i]);
    }
    return ans;
}