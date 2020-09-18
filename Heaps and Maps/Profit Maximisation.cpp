int Solution::solve(vector<int> &A, int B) {
    priority_queue<int> p;
    for(int i:A){
        p.push(i);   
    }
    int ans=0;
    for(int i=0;i<B;i++){
        ans+= p.top();
        int x= p.top();
        p.pop();
        p.push(x-1);
    }
    return ans;
}