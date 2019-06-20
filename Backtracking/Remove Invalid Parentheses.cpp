void rec(int idx, string& s, string curr_str, int off_left, int off_right, set<string>& res_set, int balance) {
    if (idx == s.length()) {
        if (off_left == 0 && off_right == 0) {
            res_set.insert(curr_str);
            }
        }
    else if(balance >= 0) {
        if (s[idx] == '(' && off_left > 0) {
            rec(idx+1, s, curr_str, off_left-1, off_right, res_set, balance);
            }
        if (s[idx] == ')' && off_right > 0) {
            rec(idx+1, s, curr_str, off_left, off_right-1, res_set, balance);
            }
        int diff = 0;
        if (s[idx] == ')') {
            diff = -1;
        }
        if (s[idx] == '(') {
            diff = 1;
        }
        rec(idx+1, s, curr_str + s[idx], off_left, off_right, res_set, balance + diff);
    }
}

void set_off_counts(int& off_left, int& off_right, string &s) {
    for(char c : s) {
        if (c == '(')
            off_left++;
        if (c == ')') {
            if (off_left > 0) {
                off_left--;
            }
            else{
                off_right++;
            }
        }
    }
}

vector<string> removeInvalidParentheses(string s) {
    int off_left = 0, off_right = 0;
    set_off_counts(off_left, off_right, s);
    set<string> res_set;
    rec(0, s, "", off_left, off_right, res_set, 0);
    vector<string> res;
    for (string val : res_set)
        res.push_back(val);
        return res;
}

vector<string> Solution::solve(string A) {
    vector<string> ans=removeInvalidParentheses(A);
    return ans;
}