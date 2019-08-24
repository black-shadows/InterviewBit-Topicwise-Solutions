unordered_map<int,int> mp;

void add(int x){
    ++mp[x];
}

void removee(int x){
    --mp[x];
    if(mp[x]==0)
        mp.erase(x);
}

int solveit(vector<int>& A, int K) {
    mp.clear();
    int n=A.size();
    if(n<K)
        return 0;
    int l = 0, r = 0, d = 0, ans = 0;
    while (r <= n) {
        if (r < n && mp.size() < K)
            add(A[r++]);
        else if(mp.size()==K) {
            if(d<=r){
                d = r;
                while(d < n && mp.find(A[d]) != mp.end())
                    d++;
            }
            while(mp.size()==K){
                ans+=(d+1-r);
                removee(A[l++]);
            }
        }
        else
            r++;
    }
    return ans;
}


int Solution::solve(vector<int> &A, int B) {
    return solveit(A,B);
}