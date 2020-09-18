vector<int> Solution::solve(vector<int> &C, int B) {
    vector<int> index(C);
    for(int i=0;i<index.size();i++){
        index[C[i]-1]=i;
    }
    int n=C.size();
    int swapped = 0;
    for(int i=0;i<n &&  swapped<B ;i++){
        if(C[i]!=n-i){
            int ele = C[i];
            swap(C[i],C[index[n-i-1]]);
            swap(index[ele-1],index[n-i-1]);
            swapped++;
        } 
    }
    return C;
}
