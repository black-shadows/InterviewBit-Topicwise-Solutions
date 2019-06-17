int Solution::solve(int n) 
{

    if(n&(n-1)==0){
        return n;
    }else{
        int ans = 1;
        while(n!=1){
            ans <<= 1;
            n >>= 1;
        }
        return ans;
    }
}
