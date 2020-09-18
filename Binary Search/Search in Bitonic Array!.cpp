int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    int i;
    int start, end;
    // finding pivot point;
    for(i=0;i<n-1;i++){
        if(A[i]>A[i+1]) break;
    }
    if(B ==  A[i]) return i;
    
        start=i+1;
        end=n-1;
        //searching first half
    while(start <= end){
        int mid=(start+end)/2;
        if(B== A[mid]) return mid;
        else if(B<A[mid]) start=mid+1;
        else end=mid-1;
    }
    
        start=0;
        end=i;
     //if not found in first half find in second
     while(start <= end){
        int mid=(start+end)/2;
        if(B== A[mid]) return mid;
        else if(B<A[mid]) end=mid-1;
        else start=mid+1;
    }   
    return -1;
}