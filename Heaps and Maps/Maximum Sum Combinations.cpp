vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    sort(A.rbegin(),A.rend());
    sort(B.rbegin(),B.rend());
    vector<int> ans;
    priority_queue<pair<int,pair<int,int> > > q;
    q.push({A[0]+B[0],{0,0}});
    while(C-->0){
        pair<int,pair<int,int> > p=q.top();q.pop();
        ans.push_back(p.first);
        if(p.second.first+1<A.size())
        q.push({A[p.second.first+1]+B[p.second.second],{p.second.first+1,p.second.second}});
        if(p.second.first==0&&p.second.second+1<B.size()){
            q.push({A[p.second.first]+B[p.second.second+1],{p.second.first,p.second.second+1}});
        }
    }
    return ans;
}
