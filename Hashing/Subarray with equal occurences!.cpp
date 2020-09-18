#define ll long long
int Solution::solve(vector<int> &A, int B, int C) {
    map<ll int,ll int> mp;
    ll int b_count=0;
    ll int c_count=0;
    ll int n=A.size();
    ll int ans=0;
    for(ll int i=0;i<n;i++){
        if(A[i]==B){
            b_count++;
        }
        else if(A[i]==C){
            c_count++;
        }
        mp[b_count-c_count]++;
    }
    ans=mp[0];
    auto it=mp.begin();
    for(it;it!=mp.end();it++){
        ans+=(it->second-1)*it->second/2;
    }
    return ans;
}