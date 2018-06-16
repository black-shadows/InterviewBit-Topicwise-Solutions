inline int getmax(int q, int w, int e){
    return max(max(q, w), e);
}

inline int getmin(int q, int w, int e){
    return min(min(q, w), e);
}

inline int eval(int q, int w, int e){
    return abs (getmax(q, w, e) - getmin(q, w, e)); 
}

int Solution::solve(vector<int> &Q, vector<int> &W, vector<int> &E) {
    int q,w,e;  q=w=e=0;
    int qs=Q.size(), ws=W.size(), es=E.size();
    int res = eval(Q[0], W[0], E[0]);
    while(q<qs and w<ws and e<es){
        res = min(res, eval(Q[q], W[w], E[e]));
        /* */if(Q[q] == getmin(Q[q], W[w], E[e]))    ++q;
        else if(W[w] == getmin(Q[q], W[w], E[e]))    ++w;
        else/*if(E[e] == getmin(Q[q], W[w], E[e]))*/ ++e;
    }
    return res;
}
