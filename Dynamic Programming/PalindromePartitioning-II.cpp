bool ispalin(string s){
    int n=s.length();
    for(int i=0;i<s.length()/2;i++)
        if(s[i]!=s[n-i-1])
            return false;
    return true;
}
int Solution::minCut(string A) {
   int i,j;
   int n=A.length();
   vector<int> v(n+1,INT_MAX);
   v[n]=-1;
   for(i=n-1;i>=0;i--){
       for(j=i;j<n;j++){
           string s=A.substr(i,j-i+1);
           if(ispalin(s))
                v[i]=min(v[i],1+v[j+1]);
       }
   }
   return v[0];
}