int Solution::solve(int a) {
    for(int i=0; i<31; i++){
        if((a>>i) & 1){
            return i;
        }
    }
    return 31;
}