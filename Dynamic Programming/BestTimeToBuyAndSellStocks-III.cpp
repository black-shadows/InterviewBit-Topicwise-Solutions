int Solution::maxProfit(const vector<int> &A) {
	if(!A.size()) 	return 0;

	int size = A.size(), big, sml;
	vector<int> sol(size), sag(size);

	sol[0] = 0;
	sml = A[0];
	for(int i=1 ; i<size ; ++i){
		sml = min(sml, A[i]);
		sol[i] = max(sol[i-1], A[i] - sml);
	}

	sag[size-1] = 0;
	big = A[size-1];
	for(int i=size-2 ; i>-1 ; --i){
		big = max(big, A[i]);
		sag[i] = max(sag[i+1], big - A[i]);
	}
	
	int res = 0;
	for(int i=0 ; i<size ; ++i)
		res = max(res, sag[i] + sol[i]);
	return res;
}