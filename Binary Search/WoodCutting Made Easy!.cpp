int Bisearch(int start,int end,vector<int> A,int B){
    long long sum;
    if(start<=end){
        sum=0;
        int mid=start+(end-start)/2;
        
        for(int i=0;i<A.size();i++){
            if(A[i]>mid){
                sum+=A[i]-mid;
            }
        }
        if(sum>=(long long)B){
            return Bisearch(mid+1,end,A,B);
        }
        else if(sum<B){
            return mid;
        }
        
        
    }
    return -1;
}
int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    int mx=0;
    for(int i=0;i<n;i++){
        if(A[i]>mx)mx=A[i];
        
    }
    int index=Bisearch(0,mx,A,B);
    int ans=index;
    for(int i=index; ;i--){
        long long sum=0;
        for(int j=0;j<n;j++){
            if(A[j]>i){
                sum+=(long long)(A[j]-i);
            }
        }
        if(sum>=(long long)B){
            ans=i;
            break;
        }
        
    }
    
    return ans;
}