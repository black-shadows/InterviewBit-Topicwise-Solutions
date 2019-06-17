string Solution::solve(string A) 
{
    
    vector <char> s;
    string ans;
    char temp;
    for(int i=0; i<A.size(); i++)
    {
        temp = A[i];
        if(s.empty()) s.push_back(temp);
        else {
            if(s[s.size() - 1] == temp) s.pop_back();
            else s.push_back(temp);
        }
    }
    if(s.empty()) return "empty";
    else {
        for(int i=0;i<s.size();i++) ans.push_back(s[i]);
        return ans;
    }
}
