int Solution::solve(vector<int> &A) {
    
    vector<int> v(A);
    unordered_set<int> s;
    
    sort(A.begin(),A.end());
    int num,temp=0;
    for(int i=0;i<A.size()-1;i++){
        if(A[i]==A[i+1]){
            num = A[i];temp=1;
            s.insert(num);
        }
    }
    if(temp==0){
        return -1;
    }
    
    for(int i=0;i<v.size();i++){
        if(s.find(v[i])!=s.end()){
            return v[i];
        }
    }
}