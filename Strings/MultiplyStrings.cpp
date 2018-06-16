string Solution::multiply(string A, string B) {
    int n= A.length(), m=B.length();
    string out="";
    vector<int> total(n+m);
    if(n==0 || m==0) return "0";
    
    int i_n=0, i_m=0;
    for(int i=n-1;i>=0;i--){
        int num1= A[i]- '0';
        int carry=0;
        i_m=0;
        for(int j=m-1;j>=0;j--){
            int num2= B[j]-'0';
            int sum= num1*num2+ carry+ total[i_n+i_m];
            carry= sum/10;
            total[i_n+i_m]= sum%10;
            i_m++;
        }
        if(carry!=0){
            total[i_n+i_m]+=carry;
            carry=0;
        }
        i_n++;
    }
    
    int ind=0;
    for(int i=0;i<n+m;i++){
        if(total[i]!=0) ind=i;
    }
    for(int i=ind;i>=0;i--){
        out+= to_string(total[i]);
    }
    return out;
}