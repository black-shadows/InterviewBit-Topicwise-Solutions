int checkunset(int x){
    int notset=0;
    for(int i=0; i<8; ++i)
        if(x&(1<<i));
        else
            ++notset;
    return notset;
}

int solveit(string s){
    int n=s.size();
    int unset=0;
    int prev=0;
    for(int i=0; i<s.size(); ++i){
        if(s[i]=='.'){
            unset+=checkunset(prev);
            prev=0;
        }
        else
            prev=prev*10+(s[i]-'0');
    }
    unset+=checkunset(prev);
    if(unset<=1)
        return 0;
    int ans=1;
    for(int i=0; i<unset; ++i)
        ans=ans*2;
    return (ans-2);
}

int Solution::solve(string A) {
    return solveit(A);
}