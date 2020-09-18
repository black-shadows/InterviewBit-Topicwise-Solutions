int N,b;
string sol,ans;
 
void recur(int indx, int left, string &A){
    if(left==0 || indx==N){
        sol = (A>sol ? A : sol);
        return;
    }
    
    for(int i=indx+1; i<N; i++){
        if(A[i]>A[indx]){
            swap(A[indx],A[i]);
            recur(indx+1,left-1,A);
            swap(A[indx],A[i]);
        }
    }
    recur(indx+1,left,A);
}
 
string Solution::solve(string A, int B) {
    sol.clear(); ans.clear();
    N=A.size(), b=B;
    if(N<=1 || B==0) return A;
    
    recur(0,B,A);
    return sol;
}