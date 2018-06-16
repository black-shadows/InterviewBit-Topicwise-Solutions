#define MOD 1000000007

using ulli = unsigned long long int;

vector< vector<int> > table;

// leading zeros leading technology
int leading_zeros(int N, int S){
	if(!N) 	return !S;
	if(table[N][S] != -1) 	return table[N][S];

	ulli res = 0;
	for(int i=0 ; i<10 ; ++i){
		if(S-i >= 0) 	res = (res + leading_zeros(N-1, S-i))%MOD;
	}
	return table[N][S] = res;
}

// we have to call this since numbers don't have leading zeros
int el_jevab(int N, int S) {
	ulli res=0;
	for(int i=1 ; i<10 ; ++i){
		if(S-i >= 0) 	res = (res + leading_zeros(N-1, S-i))%MOD;
	}
	return res;
}

int Solution::solve(int N, int S) {
	table = vector< vector<int> >(N+1, vector<int>(S+1, -1));
	return el_jevab(N, S);
}