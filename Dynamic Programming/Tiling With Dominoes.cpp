int Solution::solve(int n) {
    
    if(n%2 == 1) return 0;
    long long int A[n+1]={0},B[n+1]={0};
    A[0]=1, B[1]=1;
    
    for(int i=2;i<=n;i++){
        A[i]=(2*B[i-1]+A[i-2])%1000000007;
        B[i]=(A[i-1]+B[i-2])%1000000007;
    }
    return A[n];
}