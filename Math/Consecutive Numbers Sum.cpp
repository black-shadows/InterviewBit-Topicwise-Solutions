int Solution::solve(int A) {
    while((A&1)==0) A >>= 1;
    int ans = 1, d = 3;
    while(d*d <= A){
        int e = 0;
        while(A%d == 0){
            A /= d;
            e++;
        }
        ans *= e + 1;
        d += 2;
    }
    if(A > 1)
        ans <<= 1;
    return ans;
}