int Solution::solve(vector<int> &A, vector<int> &B) {
    vector<pair<int,int> >ans;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    for(int i=0;i<A.size();i++)
        q.push(make_pair(B[i],A[i]));
    auto it = q.top();
    int start = it.second;
    int end = it.first;
    q.pop();
    ans.push_back(make_pair(start,end));
    while(!q.empty()){
        auto itr = q.top();
        q.pop();
        if(itr.second >= end){
            start = itr.second;
            end = itr.first;
            ans.push_back(make_pair(start,end));
        }
    }
    return (int)(ans.size());
}