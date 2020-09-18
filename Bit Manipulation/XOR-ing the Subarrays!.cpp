int Solution::solve(vector<int> &A) {
    int res=0;
    for(int i=0;i<A.size();i++){
         int freq = (i + 1) * (A.size() - i); 
         if(freq%2!=0){
             res=res^A[i];
         }
    }
return res; 
}