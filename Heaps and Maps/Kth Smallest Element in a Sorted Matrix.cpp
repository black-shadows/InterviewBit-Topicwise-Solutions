int Solution::solve(vector<vector<int> > &A, int B) {
    int n=A.size();
    int m=A[0].size();
    priority_queue<int> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(q.size()<B)
                q.push(A[i][j]);
            else{
                if(A[i][j]<q.top()){
                    q.pop();
                    q.push(A[i][j]);
                }
            }
        }
    }
    return q.top();
}