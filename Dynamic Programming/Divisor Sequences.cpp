#define REP(i,n) for (int i = 0; i < n; i++)
#define remax(a,b) a = max(a,b)
#define all(v) v.begin(),v.end()
typedef map<int,int> mii;

int dp[10000005];
mii dpm;
 
int f(int x){
  if(x <= 1) return 0;
  if(x <= 10000000 and dp[x] != -1) return dp[x];
  if(x > 10000000 and dpm.find(x) != dpm.end()) return dpm[x];
  int res = 1;
  for(int d = 2; d*d <= x; d ++){
    if(x%d == 0){
      remax(res,1+f((x-d)/d));
      remax(res,1+f((x-(x/d))/(x/d)));
    }
  }
  if(x <= 10000000) return dp[x] = res;
  return dpm[x] = res;
}

int Solution::solve(int N) {
    REP(i,10000005) dp[i] = -1;
    return max(f(N),1+f(N-1));
}