vector<unsigned int> memo;

unsigned int solve(int N){
	if(memo[N]) 	return memo[N];
	unsigned int res = 0;
	for(int i=0 ; i<N ; ++i){
		res += solve(i)*solve(N-i-1);
	}
	return memo[N] = res;
}

int Solution::numTrees(int A) {
    memo = vector<unsigned int>(A+1);
    memo[0] = memo[1] = 1;
    return solve(A);
}