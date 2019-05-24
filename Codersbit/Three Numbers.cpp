long long gcd(long long u,long long v){
    if(v==0) return u;
    return gcd(v,u%v);
}
long long lcm(long long x,long long y){
    return x*y/gcd(x,y);
}
long long lcm(long long x,long long y,long long z){
    return lcm(lcm(x,y),z);
}

int Solution::solve(int A, int B, int C, int D) {
    D--;
    long a1=D/A;
    long a2=D/B;
    long a3=D/C;
    long b1=D/lcm(A,B);
    long b2=D/lcm(B,C);
    long b3=D/lcm(C,A);
    long c;
    if(!b1&&!b2&&!b3) c=0;
    else c=D/lcm(A,B,C);
    
    return (a1+a2+a3-b1-b2-b3+c)%1000000007;
}
