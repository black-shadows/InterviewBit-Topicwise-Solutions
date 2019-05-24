#define ll long long int
const int mn = 1e6 + 5;

bool p[mn];

void sieve() {
    if(p[0]) return;
    p[0] = p[1] = 1;
    for(ll i = 2; i < mn; i += 1) {
        if(!p[i])
            for(ll j = i*i; j < mn; j += i)
                p[j] = 1;
    }
}

int Solution::solve(vector<int> &A) {
    sieve();
    ll sum = 0, ans = 0;
    int n = (int)A.size();
    for(int i = 0; i < n; i += 1) {
        sum = 0;
        for(int j = i; j < n; j += 1) {
            sum += A[j];
            ans += !p[sum];
        }
    }
    return ans;
}