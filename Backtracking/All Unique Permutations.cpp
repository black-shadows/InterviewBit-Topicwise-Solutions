void helper(vector<vector<int>>& res, vector<int>& temp, vector<int>& nums, unordered_map<int,int>& m){
    if(temp.size()==nums.size()){
        res.emplace_back(temp);
        return;
    }
    for(int i=0; i<nums.size(); i++){
        if(m[nums[i]]>0){
            if(i&&nums[i]==nums[i-1]) continue;
            temp.emplace_back(nums[i]);
            m[nums[i]]--;
            helper(res, temp, nums, m);
            m[nums[i]]++;
            temp.pop_back();
        }
    }
}
 
vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    unordered_map<int,int> m;
    for(auto n:nums) m[n]++;
    vector<vector<int>> res;
    vector<int> temp;
    helper(res, temp, nums, m);
    return res;
}
 
vector<vector<int> > Solution::permute(vector<int> &A) 
{
    
    return permuteUnique(A);
    
}