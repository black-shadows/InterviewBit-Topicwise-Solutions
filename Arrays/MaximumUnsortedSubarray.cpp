vector<int> Solution::subUnsort(vector<int> &A){
 vector<int> ans;
 int n = A.size();
 int i = 0, j = n-1;
 while(i< n - 1 and A[i] <= A[i + 1]){
  i++;
 }
 while(j > 0 and A[j] >= A[j - 1]){
  j--;
 }
 if(i == n - 1){ // if array is already sorted, output -1
  ans.push_back(-1);
  return ans;
 }
 int mn = A[i + 1], mx = A[i + 1];
 for(int k = i; k <= j; k++){
  mx = max(mx, A[k]);
  mn = min(mn, A[k]);
 }
 int l = 0, r = n - 1;
 while(A[l] <= mn and l <= i){
     l++;
 }
 while(A[r] >= mx and r >= j){
  r--;
 }
 ans.push_back(l);
 ans.push_back(r);
 return ans;
}