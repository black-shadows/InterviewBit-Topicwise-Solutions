bool isSquareful(int a, int b){
        long tmp = a + b;
        int num = sqrt(tmp);                          
        if(num*num == tmp){
            return true;
        }else{
            return false;
        } 
} 

void helper(vector<int>& A, int level, vector<int>&visited, vector<int>& out, vector<vector<int>>&res){
    if(level == A.size()){
        res.push_back(out);
        return;
    }
    for(int i = 0; i<A.size(); i++){
        if(visited[i] == 0){
            if((i>0&&A[i]==A[i-1]&&visited[i-1]==0)||(!out.empty()&&!isSquareful(out.back(),A[i])))
                continue;
            visited[i] = 1;
            out.push_back(A[i]);
            helper(A, level + 1,visited,out,res);
            out.pop_back();
            visited[i] = 0;  
        }
    }
}

int numSquarefulPerms(vector<int>& A) {
    vector<int> out;
    vector<int>visited(A.size(),0);
    vector<vector<int>> res;
    sort(A.begin(), A.end());
    helper(A, 0, visited, out ,res);
    return res.size();
}

int Solution::solve(vector<int> &A) 
{
    if(A.size() == 1)
    {
        
        return 0;
        
    }
    return numSquarefulPerms(A);
    
}
