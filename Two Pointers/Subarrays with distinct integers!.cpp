int Solution::solve(vector<int> &A, int B) {
    
     int res = 0;
    int K = B;
    vector<int> m(A.size() + 1);
  for(auto i = 0, j = 0, prefix = 0, cnt = 0; i < A.size(); ++i) {
    if (m[A[i]]++ == 0) ++cnt;
    if (cnt > K) --m[A[j++]], --cnt, prefix = 0;
    while (m[A[j]] > 1) ++prefix, --m[A[j++]];
    if (cnt == K) res += prefix + 1;
  }
  return res;
}