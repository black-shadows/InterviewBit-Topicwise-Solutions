#define pb emplace_back

vector<int> Solution::solve(vector<int> &A) {
    int n = A.size();
    stack<int> st;
    vector<int> ans;
    for (int i=0;i<n-1;i++){
        int f=0;
        if (A[i]>A[i+1]) {st.push(A[i]);}
        else{
            while (!st.empty()){
                if (A[i+1]>st.top()) {st.pop(); f=1;}
                else {break;}
            }
            if (f==1) {ans.pb(A[i]);}
        }
    }
    ans.pb(A[n-1]);
    return ans;
}