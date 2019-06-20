unordered_map<string,vector<int>> mytable;
unordered_map<string,unordered_map<int,string>> subtable;


int b_s(vector<int>&v , int target){
    int left = 0, right = v.size()-1;
    while(right >= left){
        int mid = (right+left)/2;
        if(v[mid] == target)
            return mid;
        else if(v[mid] > target)
            right = mid-1;
        else
            left = mid+1;
    }
    return right;
}

void binary_insert(vector<int>& v, int target){
    if(v.size() == 0 || target > v[v.size()-1])
        v.push_back(target);
    else if(target < v[0])
        v.insert(v.begin(),target);
    else
        v.insert(v.begin()+b_s(v,target),target);
}

void sett(string &key, string &value, int timestamp) {
    binary_insert(mytable[key],timestamp);
    subtable[key][timestamp] = value;
}


string get(string key, int timestamp) {
    if(mytable[key].size() == 0 || timestamp < mytable[key][0])
            return "null";
    else{
        int idx = b_s(mytable[key],timestamp);
        return subtable[key][mytable[key][idx]];
    }
}


vector<string> solveit(vector<int> &type,vector<string> &key,vector<string> &value,vector<int> &timestamp){
    int n=type.size();
    mytable.clear();
    subtable.clear();
    vector<string> ans;
    for(int i=0; i<n; ++i){
        if(type[i]==1){
            sett(key[i],value[i],timestamp[i]);
            ans.push_back("null");
            }
        else
            ans.push_back(get(key[i],timestamp[i]));
    }
    return ans;
}

vector<string> Solution::solve(vector<int> &A, vector<string> &B, vector<string> &C, vector<int> &D) {
    return solveit(A,B,C,D);
}