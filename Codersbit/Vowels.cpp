int Solution::solve(int A) {
    long int q[2][5];
    long int sum=0;
    int mod=1e9+7;
    for(int i=0;i<5;i++){
        q[0][i]=1;
    }
    int j=1;
    while(j<A){
        for(int i=0;i<5;i++){
            switch(i){
                case 0:q[1][i]=(q[0][1]+q[0][2])%mod;
                        break;
                case 1:q[1][i]=(q[0][2])%mod;
                        break;
                case 2:q[1][i]=(q[0][0]+q[0][1]+q[0][3]+q[0][4])%mod;
                        break;
                case 3:q[1][i]=(q[0][0]+q[0][4])%mod;
                        break;
                case 4:q[1][i]=(q[0][3]+q[0][1])%mod;
                        break;
                default: ;
            }
        }
        for(int i=0;i<5;i++){
            q[0][i]=q[1][i];
        }
        j++;

    }
    for(int i=0;i<5;i++){
        sum=(sum+q[0][i])%mod;
    }
 
    return (int)(sum % mod);
}