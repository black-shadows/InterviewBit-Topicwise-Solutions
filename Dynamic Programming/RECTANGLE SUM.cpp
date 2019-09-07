int Solution::solve(vector<vector<int> > &A) {
      for(int i=0;i<A.size();i++){
        for(int j=1;j<A[0].size();j++){
            A[i][j]=A[i][j]+A[i][j-1];
        }
    }
    int ans=INT_MIN;
    for(int i=0;i<A[0].size();i++){
        for(int j=i;j<A[0].size();j++){
            int max1=0;
            for(int k=0;k<A.size();k++){
                if(i==0){
                    max1=max1+A[k][j];
                    if(max1>ans){
                        ans=max1;
                    }
                    if(max1<0){
                        max1=0;
                    }
                }
                else{
                 max1=max1+A[k][j]-A[k][i-1];
                 if(max1>ans){
                     ans=max1;
                 }
                 if(max1<0){
                     max1=0;
                  }
                }
            }
        }
    }
   if(ans<0){
       return 0;
   }
    
    return ans;
    
}