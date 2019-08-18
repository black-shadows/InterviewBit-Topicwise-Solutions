vector<int> Solution::solve(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    int n = A.size();
    int mx = INT_MIN;
    int el = 0;
    int req = 0;
    int i=0,j=0;
    while(j<n){
        if(req<=B){
            if(mx<j-i+1){
                mx = j-i+1;
                el = A[j];
            }
        }
        if(req<=B){
            j++;
            req+=(A[j]-A[j-1])*(j-i);
        }
        else{
            i++;
            req-=(A[j]-A[i-1]);
        }
    }
    vector<int> ans;
    ans.push_back(mx);
    ans.push_back(el);
    return ans;
}
