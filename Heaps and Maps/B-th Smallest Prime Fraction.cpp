#define y second.second
#define x second.first

vector<int> Solution::solve(vector<int> &A, int B) {
    int K = B;
    priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>,greater<pair<double,pair<int,int>>>> q;
    unordered_map<int,int> nxt;
    for(int i = A.size()-1;i > 0;i--)
        nxt[A[i]] = A[i-1];

    double last = A[A.size()-1],d;
    nxt[1] = 0;

    for(int i = 0;i < A.size();i++){
        d = (double)A[i]/last;
        q.push(make_pair(d,make_pair(A[i],last)));
    }
    
    while(q.size() && K){
        K--;
        if(K == 0) break;

        pair<double,pair<int,int>> p = q.top();q.pop();
        if(nxt[p.y] != 0){
            p.y = nxt[p.y];
            d = (double)p.x/(double)p.y;
            q.push(make_pair(d,p.second));
        }
    }
    
    vector<int> ret(2);
    ret[0] = q.top().second.first;
    ret[1] = q.top().second.second;
    
    return ret;
}