int countSubstrings(string s) {
    int ans=0;
    int n=s.size();
    for(int i=0; i<n; ++i){
        for(int k=i,j=i; k<n&&j>=0; ++k,--j)
            if(s[k]==s[j])
                    ++ans;
            else
                break;
        for(int k=i,j=i-1; k<n&&j>=0; ++k,--j)
            if(s[k]==s[j])
                    ++ans;
            else
                break;
    }
    return ans;
}

int Solution::solve(string A) {
    return countSubstrings(A);
}