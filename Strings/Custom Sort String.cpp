string Solution::solve(string A, string B) {
    int a[26]={0};
    for(auto &it:B)
        ++a[it-'a'];
    string ans;
    for(auto &it:A){
        while(a[it-'a']--)
            ans.push_back(it);
    }
    for(int i=0; i<26; ++i){
        if(a[i]>0){
            while(a[i]--)
                ans.push_back(i+'a');
        }
    }
    return ans;
    
}