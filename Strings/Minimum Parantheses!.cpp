int Solution::solve(string A) {
    
    int balance=0;
    int ans=0;
    
    int len=A.length();
    
    for(int i=0;i<len;i++) {
        
        if(A[i]=='(') {
            balance++;
        }
        
        else {
            balance--;
        }
        
        if(balance==-1) {
            balance++;
            ans++;
        }
  
        
    }
    
    return balance+ans;
}
