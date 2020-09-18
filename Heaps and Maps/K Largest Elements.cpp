int partition(vector<int> &A,int l,int r){
    
    int pivot=A[r];
    int i=l-1;
    
    for(int j=l;j<=r;j++){
        
        if(A[j]<pivot){
            
            i++;
            swap(A[j],A[i]);
        }
    }
    
    swap(A[i+1],A[r]);
    return i+1;
}
 
void f(vector<int> &A,int l,int r, int ind){
    
    if(l>r) return ;
    int pivot=partition(A,l,r);
    
    if(pivot < ind) f(A,pivot+1,r,ind);
    else if(pivot > ind) f(A,l,pivot-1,ind);
}
 
vector<int> Solution::solve(vector<int> &A, int k) {
    
    int n=A.size();
    f(A,0,n-1,n-k);
    vector<int> ans;
    for(int i=n-k;i<n;i++){
        ans.push_back(A[i]);
    }
    
    return ans;
}