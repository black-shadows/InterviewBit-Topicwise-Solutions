bool _isMatch(const string &str, int s, const string &pat, int p){
    if(p == pat.length())        return s == str.size();

    bool star = p < pat.size()-1 and pat[p + 1] == '*';
    bool match = s < str.size() and  (pat[p] == '.' or str[s] == pat[p]);
    // if theres kleene
    if(star){
        // dont match rec, match rec.
        return _isMatch(str, s, pat, p+2) 
            or ( match and _isMatch(str, s+1, pat, p));
    }
    return match and _isMatch(str, s+1, pat, p+1);
}


int Solution::isMatch(const string str, const string pat) {
    return _isMatch(str, 0, pat, 0);
}