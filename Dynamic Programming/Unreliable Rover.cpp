const long long mod = 1000000007;

int getArea(string &direction, vector <int> &minSteps, vector <int> &maxSteps) {
  int n = (int) direction.size();
  vector<int> unknown;
  int sx = 1, sy = 1;
  for (int i = 0; i < n; i++) {
    if (direction[i] == '?') {
      unknown.push_back(maxSteps[i]);
    } else {
      if (direction[i] == 'N' || direction[i] == 'S') {
        sy += maxSteps[i] - minSteps[i];
      } else {
        sx += maxSteps[i] - minSteps[i];
      }
    }
  }
  vector<int> sums;
  int sz = (int) unknown.size();
  for (int t = 0; t < (1 << sz); t++) {
    int sum = 0;
    for (int i = 0; i < sz; i++) {
      if (t & (1 << i)) {
        sum += unknown[i];
      }
    }
    sums.push_back(sum);
  }
  sort(sums.begin(), sums.end());
  int total = sums.back();
  long long ans = (long long) sx * sy + (long long) sx * total * 2 + (long long) sy * total * 2;
  ans += (long long) 2 * total * (total - 1);
  for (int i = 0; i < (int) sums.size() - 1; i++) {
    int cur = sums[i + 1] - sums[i];
    ans -= (long long) 2 * cur * (cur - 1);
  }
  return (ans%mod);
}


int Solution::solve(string A, vector<int> &B, vector<int> &C) {
    return getArea(A,B,C);
}