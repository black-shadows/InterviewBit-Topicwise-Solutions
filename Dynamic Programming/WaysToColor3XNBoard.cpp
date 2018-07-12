int Solution::solve(int A) {
    long int color2=12;
    long int color3=24;
    for(int i=2;i<=A;++i){
        long int temp = color3;
        color3 = (11 * color3 + 10*color2 ) % 1000000007;
               
        color2 = ( 5 * temp + 7*color2 ) % 1000000007;
    }
    long num = (color3 + color2)% 1000000007;
    return (int)num;
}
