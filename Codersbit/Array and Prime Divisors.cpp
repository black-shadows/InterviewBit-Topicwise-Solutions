bool isprime(int n){
    if(n==1){
        return false;
    }
 for(int i=2;i<=sqrt(n);i++){
     if(n%i==0){
         return false;
     }
 }
 return true;
}

int Solution::solve(vector<int> &A, int B) {
    int n = A.size(),ans=0;
    for(int i=0;i<n;i++){
        if(B%A[i]==0 && isprime(A[i])){
            ans++;
        }
    }
    return ans;
}
