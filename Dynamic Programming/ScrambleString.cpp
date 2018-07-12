map<pair<string, string>, bool> store;
int solverec(const string &A, const string &B) {

    pair<string, string> pt = make_pair(A, B);
    if (store.find(pt) != store.end()) return store[pt];
    
    string temp1 = A;
    string temp2 = B;
    sort(temp1.begin(), temp1.end());
    sort(temp2.begin(), temp2.end());
    // cout<<temp1<<" "<<temp2<<endl;
    
    if(temp1.compare(temp2) != 0) return false;
    
    // for less than 2 yield it true 
    if(temp1.size() <= 2) return true;
    
    for(int i = 1; i < A.length(); i++) {
        if(solverec(A.substr(0, i), B.substr(0, i))
            && solverec(A.substr(i), B.substr(i))) return store[pt] = true;
        if(solverec(A.substr(0, i), B.substr(B.length() - i)) 
            && solverec(A.substr(i), B.substr(0, B.length() - i))) return store[pt] = true;
    }
    return store[pt] = false;
}
int Solution::isScramble(const string A, const string B) {
    // if the string is of length 2 or less and are anagrams it'll 
    // always be true
    // if > 2 we'll have to check the root 
    store.clear();
    int n1 = A.length();
    int n2 = B.length();
    if(n1 != n2) return 0;
    return solverec (A, B);
}
