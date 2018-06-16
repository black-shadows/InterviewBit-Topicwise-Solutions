int Solution::calculateMinimumHP(vector<vector<int> > &A) {
	// init dimensions
	const int I = A.size(); 	const int J = A[0].size();
	vector< vector<int> > sol(I, vector<int>(J, 0));


	// init last row & column
	sol[I-1][J-1] = max(1, -A[I-1][J-1]+1);
	for(int j=J-2 ; j>-1 ; --j) 	sol[I-1][j] = max(1, sol[I-1][j+1] - A[I-1][j]);
	for(int i=I-2 ; i>-1 ; --i) 	sol[i][J-1] = max(1, sol[i+1][J-1] - A[i][J-1]);

	for(int i=I-2 ; i>-1 ; --i){
		for(int j=J-2 ; j>-1 ; --j){
			int rite = max(1, sol[i][j+1] - A[i][j]);
			int down = max(1, sol[i+1][j] - A[i][j]);
			sol[i][j] = min(rite, down);
		}
	}
	return sol[0][0];
}