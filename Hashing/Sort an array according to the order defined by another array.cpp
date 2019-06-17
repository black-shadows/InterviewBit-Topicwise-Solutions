vector<int> solveit(vector<int> &a,vector<int> &b){
    unordered_map<int,int> mp;
    vector<pair<int,int> > notInB;
    unordered_map<int,int>::iterator it1;
    int i=0;
    for(auto &it:a)
        ++mp[it];
    for(auto &it:b){
        it1=mp.find(it);
        if(it1!=mp.end()){
            int y=mp[it];
            while(y--)
                a[i++]=it;
            mp.erase(it1);
        }
    }
    for(auto &it:mp)
        notInB.push_back({it.first,it.second});
    sort(notInB.begin(),notInB.end());
    for(auto &it:notInB){
        int x=it.first;
        int y=it.second;
        while(y--)
            a[i++]=x;
    }
    return a;
}

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    return solveit(A,B);
}